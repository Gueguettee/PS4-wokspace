/**
  ****************************************************************************
  * @file    can.c
  * @author  Lucas Froidevaux
  * @date    13.04.2021
  * @brief   Implementation of CANx initialization functions, the normal &
  *          remote frames write functions and the read function.
  * 
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "can.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_can1_pointer = 0;
static Callback_t cbf_can2_pointer = 0;

/******************************************************************************/
/*                              Global variables                              */
/******************************************************************************/
buffer_t can1MsgBuf, can2MsgBuf;
canParam_t can1, can2;

/******************************************************************************/
/*                CANs INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/

void can1Init()
{
    __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
    RPINR26bits.C1RXR = 0b0110111;  // Assign C1RX To Pin RP55
    RPOR6bits.RP54R = 0b001110;     // Assign C1TX To Pin RP54
    __builtin_write_OSCCONL(OSCCON | (1 << 6));
    
    /* Set the CAN module for Configuration Mode before writing into
     * the BaudRate Control Registers */
    C1CTRL1bits.REQOP = 4;
    /* Wait for the CAN module to enter into Configuration Mode */
    while(C1CTRL1bits.OPMODE != 4);
    
    IFS2bits.C1RXIF = 0;    // clear interrupt flag
    IEC2bits.C1IE = 0;      // disable CAN 1 interrupts
    
    /* make the buffer control and status registers and
     * the transmit and receive data registers accessible */
    C1CTRL1bits.WIN = 0;
    
    /* read MC's AN754 for detailed CAN timing explanations */
    
    uint8_t BRPVAL = 0;
    uint8_t NTQ = 0;
    uint8_t MULT = 0;
    
    genCANBaudParam(can1.baud_rate, &BRPVAL, &NTQ, &MULT);
    
    /* Set Fp or Fp*2 as CAN source clock (-> FCAN=60MHz) */
    C1CTRL1bits.CANCKS = MULT;
    
    /* Phase Segment 2: This time segment compensates for errors that may occur
     * due to phase shift in the edges. The time segment may be shortened during
     * resynchronization to compensate for the phase shift. The Phase Segment 2
     * time can be configured to be either programmable or specified by the
     * Phase Segment 1 time. */
    C1CFG2bits.SEG2PHTS = 0x1; // Phase Segment 2 time is set to be programmable
    C1CFG2bits.SEG2PH = (NTQ-1)/3-1;
    
    /* Phase Segment 1: This time segment compensates for errors that may occur
     * due to phase shift in the edges. The time segment may be lengthened
     * during resynchronization to compensate for the phase shift. */
    C1CFG2bits.SEG1PH = (NTQ-1-(C1CFG2bits.SEG2PH+1))/2-1;
    
    /* Propagation Segment: This time segment compensates for any time delay
     * that may occur due to the bus line or due to the various transceivers
     * connected on that bus. */
    C1CFG2bits.PRSEG = NTQ-1-(C1CFG2bits.SEG2PH+1)-(C1CFG2bits.SEG1PH+1)-1;
    
    /* Bus line is sampled three times at the sample point */
    C1CFG2bits.SAM = 0x1;
    
    /* Synchronization Jump Width set to 1 TQ */
    C1CFG1bits.SJW = 0x0;
    
    /* Set Baud Rate Prescaler bits */
    C1CFG1bits.BRP = BRPVAL;
    
    /* ------------- TX ------------- */
    C1FCTRL = 0xC01F;     // No FIFO, 32 Buffers
    
    /* Assign 32x8word Message Buffers for CAN1 in device RAM. Refer to Section
     * 9.1 "DMA Operation for Transmitting Data" for details on DMA channel
     * configuration for CAN transmit. */
    DMA0CONbits.SIZE = 0x0;                     // word transfer mode
    DMA0CONbits.DIR = 0x1;                      // direction: ram to peripheral
    DMA0CONbits.AMODE = 0x2;                    // Indirect Addressing mode
    DMA0CONbits.MODE = 0x0;                     // Continuous operating mode
    DMA0REQ = 70;                               // CAN1 TX data request
    DMA0CNT = 7;                                // Msg size (8 words)
    DMA0PAD = (volatile unsigned int) &C1TXD;   // where to put the data
    DMA0STAL = (unsigned int) &can1MsgBuf;      // where to get the data from
    DMA0STAH = 0;                               // bits 23:16 unused (16b. addr)
    DMA0CONbits.HALF = 0x0;                     // End of block interrupt
    DMA0CONbits.CHEN = 0x1;                     // Enable DMA channel 0
    
    /* Configure Message Buffer 0 for Transmission and assign priority */
    C1TR01CONbits.TXEN0 = 0x1;      // buffer 0 is a transmit buffer
    C1TR01CONbits.TX0PRI = 0x3;     // highest message priority
    /* ------------- TX ------------- */
    
    /* ------------- RX ------------- */
    C1CTRL1bits.WIN = 1;
    
    /* DMA1 for RX */
    DMA1CONbits.SIZE = 0x0;                     // word transfer mode
    DMA1CONbits.DIR = 0x0;                      // direction: peripheral to ram
    DMA1CONbits.AMODE = 0x2;                    // Indirect Addressing mode
    DMA1CONbits.MODE = 0x0;                     // Continuous operating mode
    DMA1REQ = 34;                               // CAN1 RX data Ready
    DMA1CNT = 7;                                // Msg size (8 words)
    DMA1PAD = (volatile unsigned int) &C1RXD;   // where to get the data from
    DMA1STAL = (unsigned int) &can1MsgBuf;      // where to put the data
    DMA1STAH = 0;                               // bits 23:16 unused (16b. addr)
    DMA1CONbits.HALF = 0x0;                     // End of block interrupt
    DMA1CONbits.CHEN = 0x1;                     // Enable DMA channel 1
    
    /* Select Acceptance Filter Mask 0 for Acceptance Filter 0 */
    C1FMSKSEL1bits.F0MSK=0x0;
    
    /* Configure Acceptance Filter Mask 0 register to accept all IDs */
    C1RXM0SIDbits.SID = 0x0;
    C1RXM0EIDbits.EID = 0x0;
    
    /* Acceptance filter value does not matter (since all bits are masked) */
    // C1RXF0SIDbits.SID = 0x0;
    // C1RXF0EIDbits.EID = 0x0;
    
    /* Acceptance Filter 0 to check for Standard and Extended Identifiers */
    C1RXM0SIDbits.MIDE = 0x0;
    
    /* Acceptance Filter 0 to use Message Buffer 8 to store message */
    C1BUFPNT1bits.F0BP = 0x8;
    
    /* Filter 0 enabled for Identifier match with incoming message */
    C1FEN1bits.FLTEN0=0x1;
    
    C1CTRL1bits.WIN=0x0;
    /* ------------- RX ------------- */
    
    /* Put the CAN Module into Normal Operating Mode */
    C1CTRL1bits.REQOP = 0;
    /* Wait for the CAN module to enter into Normal Operating Mode */
    while(C1CTRL1bits.OPMODE != 0);
    
    IPC17bits.C1TXIP = 3;   // Set TX IRQ priority level
    IPC8bits.C1RXIP = 3;    // Set RX IRQ priority level
}

void can2Init()
{
    __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
    RPINR26bits.C2RXR = 0b0111001;  // Assign C2RX To Pin RP57
    RPOR7bits.RP56R = 0b001111;     // Assign C2TX To Pin RP56
    __builtin_write_OSCCONL(OSCCON | (1 << 6));
    
    /* Set the CAN module for Configuration Mode before writing into
     * the BaudRate Control Registers */
    C2CTRL1bits.REQOP = 4;
    /* Wait for the CAN module to enter into Configuration Mode */
    while(C2CTRL1bits.OPMODE != 4);
    
    IFS3bits.C2RXIF = 0;    // clear interrupt flag
    IEC3bits.C2IE = 0;      // disable CAN 2 interrupts
    
    /* make the buffer control and status registers and
     * the transmit and receive data registers accessible */
    C2CTRL1bits.WIN = 0;
    
    /* read MC's AN754 for detailed CAN timing explanations */
    
    uint8_t BRPVAL = 0;
    uint8_t NTQ = 0;
    uint8_t MULT = 0;
    
    genCANBaudParam(can2.baud_rate, &BRPVAL, &NTQ, &MULT);
    
    /* Set Fp or Fp*2 as CAN source clock (-> FCAN=60MHz) */
    C2CTRL1bits.CANCKS = MULT;
    
    /* Phase Segment 2: This time segment compensates for errors that may occur
     * due to phase shift in the edges. The time segment may be shortened during
     * resynchronization to compensate for the phase shift. The Phase Segment 2
     * time can be configured to be either programmable or specified by the
     * Phase Segment 1 time. */
    C2CFG2bits.SEG2PHTS = 0x1; // Phase Segment 2 time is set to be programmable
    C2CFG2bits.SEG2PH = (NTQ-1)/3-1;
    
    /* Phase Segment 1: This time segment compensates for errors that may occur
     * due to phase shift in the edges. The time segment may be lengthened
     * during resynchronization to compensate for the phase shift. */
    C2CFG2bits.SEG1PH = (NTQ-1-(C2CFG2bits.SEG2PH+1))/2-1;
    
    /* Propagation Segment: This time segment compensates for any time delay
     * that may occur due to the bus line or due to the various transceivers
     * connected on that bus. */
    C2CFG2bits.PRSEG = NTQ-1-(C2CFG2bits.SEG2PH+1)-(C2CFG2bits.SEG1PH+1)-1;
    
    /* Bus line is sampled three times at the sample point */
    C2CFG2bits.SAM = 0x1;
    
    /* Synchronization Jump Width set to 1 TQ */
    C2CFG1bits.SJW = 0x0;
    
    /* Set Baud Rate Prescaler bits */
    C2CFG1bits.BRP = BRPVAL;
    
    /* ------------- TX ------------- */
    C2FCTRL = 0xC01F;     // No FIFO, 32 Buffers
    
    /* Assign 32x8word Message Buffers for CAN2 in device RAM. Refer to Section
     * 9.1 "DMA Operation for Transmitting Data" for details on DMA channel
     * configuration for CAN transmit. */
    DMA2CONbits.SIZE = 0x0;                     // word transfer mode
    DMA2CONbits.DIR = 0x1;                      // direction: ram to peripheral
    DMA2CONbits.AMODE = 0x2;                    // Indirect Addressing mode
    DMA2CONbits.MODE = 0x0;                     // Continuous operating mode
    DMA2REQ = 71;                               // CAN2 TX data request
    DMA2CNT = 7;                                // Msg size (8 words)
    DMA2PAD = (volatile unsigned int) &C2TXD;   // where to put the data
    DMA2STAL = (unsigned int) &can2MsgBuf;      // where to get the data from
    DMA2STAH = 0;                               // bits 23:16 unused (16b. addr)
    DMA2CONbits.HALF = 0x0;                     // End of block interrupt
    DMA2CONbits.CHEN = 0x1;                     // Enable DMA channel 2
    
    /* Configure Message Buffer 0 for Transmission and assign priority */
    C2TR01CONbits.TXEN0 = 0x1;      // buffer 0 is a transmit buffer
    C2TR01CONbits.TX0PRI = 0x3;     // highest message priority
    /* ------------- TX ------------- */
    
    /* ------------- RX ------------- */
    C2CTRL1bits.WIN = 1;
    
    /* DMA3 for RX */
    DMA3CONbits.SIZE = 0x0;                     // word transfer mode
    DMA3CONbits.DIR = 0x0;                      // direction: peripheral to ram
    DMA3CONbits.AMODE = 0x2;                    // Indirect Addressing mode
    DMA3CONbits.MODE = 0x0;                     // Continuous operating mode
    DMA3REQ = 55;                               // CAN2 RX data Ready
    DMA3CNT = 7;                                // Msg size (8 words)
    DMA3PAD = (volatile unsigned int) &C2RXD;   // where to get the data from
    DMA3STAL = (unsigned int) &can2MsgBuf;      // where to put the data
    DMA3STAH = 0;                               // bits 23:16 unused (16b. addr)
    DMA3CONbits.HALF = 0x0;                     // End of block interrupt
    DMA3CONbits.CHEN = 0x1;                     // Enable DMA channel 3
    
    /* Select Acceptance Filter Mask 0 for Acceptance Filter 0 */
    C2FMSKSEL1bits.F0MSK=0x0;
    
    /* Configure Acceptance Filter Mask 0 register to accept all IDs */
    C2RXM0SIDbits.SID = 0x0;
    C2RXM0EIDbits.EID = 0x0;
    
    /* Acceptance filter value does not matter (since all bits are masked) */
    // C1RXF0SIDbits.SID = 0x0;
    // C1RXF0EIDbits.EID = 0x0;
    
    /* Acceptance Filter 0 to check for Standard and Extended Identifiers */
    C2RXM0SIDbits.MIDE = 0x0;
    
    /* Acceptance Filter 0 to use Message Buffer 8 to store message */
    C2BUFPNT1bits.F0BP = 0x8;
    
    /* Filter 0 enabled for Identifier match with incoming message */
    C2FEN1bits.FLTEN0=0x1;
    
    C2CTRL1bits.WIN=0x0;
    /* ------------- RX ------------- */
    
    /* Put the CAN Module into Normal Operating Mode */
    C2CTRL1bits.REQOP = 0;
    /* Wait for the CAN module to enter into Normal Operating Mode */
    while(C2CTRL1bits.OPMODE != 0);
    
    IPC17bits.C2TXIP = 3;   // Set TX IRQ priority level
    IPC13bits.C2RXIP = 3;   // Set RX IRQ priority level
}

/******************************************************************************/
/*                     CANs USER FUNCTIONS Implementation                     */
/******************************************************************************/

/*********************************************************************
Function Prototype : 
Description        : 
Arguments          : 
Return Value       : 
Remarks            : 
*********************************************************************/

void canWriteData(can_t eCANx, uint32_t ID, uint8_t dataLength, uint8_t* msg)
{
    canIdLength_t canIdLength = (eCANx==eCAN1) ? can1.idLength : can2.idLength;
    buffer_t canTXMsgBuf;
    switch (canIdLength){
        case bits11:
            canTXMsgBuf[0].SIDhi  = (ID >> 6) & 0x1F;
            canTXMsgBuf[0].SIDlo  = (ID >> 0) & 0x3F;
            canTXMsgBuf[0].SRR    = 0;
            canTXMsgBuf[0].IDE    = 0;

            canTXMsgBuf[0].EIDhi  = 0;
            canTXMsgBuf[0].EIDmi  = 0;
            canTXMsgBuf[0].EIDlo  = 0;
            break;
        case bits29:
            canTXMsgBuf[0].SIDhi  = (ID >> 24) & 0x1F;
            canTXMsgBuf[0].SIDlo  = (ID >> 18) & 0x3F;
            canTXMsgBuf[0].SRR    = 1; // must be set to 1 for extended frames
            canTXMsgBuf[0].IDE    = 1; // extended identifier flag

            canTXMsgBuf[0].EIDhi  = (ID >> 14) & 0x0F;
            canTXMsgBuf[0].EIDmi  = (ID >>  6) & 0xFF;
            canTXMsgBuf[0].EIDlo  = (ID >>  0) & 0x3F;
            break;
        default:
            // error code
            break;
    }
    
    canTXMsgBuf[0].RTR    = 0;
    canTXMsgBuf[0].RB1    = 0x0;
    canTXMsgBuf[0].RB0    = 0x0;
    
    if(dataLength>7){
        canTXMsgBuf[0].DLC = 8;
    } else {
        canTXMsgBuf[0].DLC = dataLength;
    }
    
    canTXMsgBuf[0].Byte0  = msg[0];
    canTXMsgBuf[0].Byte1  = msg[1];
    canTXMsgBuf[0].Byte2  = msg[2];
    canTXMsgBuf[0].Byte3  = msg[3];
    canTXMsgBuf[0].Byte4  = msg[4];
    canTXMsgBuf[0].Byte5  = msg[5];
    canTXMsgBuf[0].Byte6  = msg[6];
    canTXMsgBuf[0].Byte7  = msg[7];
    
    canTXMsgBuf[0].FILHIT = 0x0; // unused for transmit buffers
    
    switch (eCANx){
        case eCAN1:
            can1MsgBuf[0] = canTXMsgBuf[0];
            C1TR01CONbits.TXREQ0 = 0x1; // Request message buffer 0 transmission
            break;
        case eCAN2:
            can2MsgBuf[0] = canTXMsgBuf[0];
            C2TR01CONbits.TXREQ0 = 0x1; // Request message buffer 0 transmission
            break;
        default:
            break;
    }
}

void canWriteRemote(can_t eCANx, uint32_t ID, uint8_t dataLength)
{
    canIdLength_t canIdLength = (eCANx==eCAN1) ? can1.idLength : can2.idLength;
    buffer_t canTXMsgBuf;
    switch (canIdLength){
        case bits11:
            canTXMsgBuf[0].SIDhi  = (ID >> 6) & 0x1F;
            canTXMsgBuf[0].SIDlo  = (ID >> 0) & 0x3F;
            canTXMsgBuf[0].SRR    = 0;
            canTXMsgBuf[0].IDE    = 0;

            canTXMsgBuf[0].EIDhi  = 0;
            canTXMsgBuf[0].EIDmi  = 0;
            canTXMsgBuf[0].EIDlo  = 0;
            break;
        case bits29:
            canTXMsgBuf[0].SIDhi  = (ID >> 24) & 0x1F;
            canTXMsgBuf[0].SIDlo  = (ID >> 18) & 0x3F;
            canTXMsgBuf[0].SRR    = 1; // must be set to 1 for extended frames
            canTXMsgBuf[0].IDE    = 1; // extended identifier flag

            canTXMsgBuf[0].EIDhi  = (ID >> 14) & 0x0F;
            canTXMsgBuf[0].EIDmi  = (ID >>  6) & 0xFF;
            canTXMsgBuf[0].EIDlo  = (ID >>  0) & 0x3F;
            break;
        default:
            // error code
            break;
    }
    
    canTXMsgBuf[0].RTR    = 1; // must be set to 1 for remote frames
    canTXMsgBuf[0].RB1    = 0x0;
    canTXMsgBuf[0].RB0    = 0x0;
    
    // .DLC bits must match expected data size for remote frames
    if(dataLength>7){
        canTXMsgBuf[0].DLC = 8;
    } else {
        canTXMsgBuf[0].DLC = dataLength;
    }
    
    // data field unused for remote frames
    canTXMsgBuf[0].Byte0  = 0x00;
    canTXMsgBuf[0].Byte1  = 0x00;
    canTXMsgBuf[0].Byte2  = 0x00;
    canTXMsgBuf[0].Byte3  = 0x00;
    canTXMsgBuf[0].Byte4  = 0x00;
    canTXMsgBuf[0].Byte5  = 0x00;
    canTXMsgBuf[0].Byte6  = 0x00;
    canTXMsgBuf[0].Byte7  = 0x00;
    
    canTXMsgBuf[0].FILHIT = 0x0; // unused for transmit buffers
    
    switch (eCANx){
        case eCAN1:
            can1MsgBuf[0] = canTXMsgBuf[0];
            C1TR01CONbits.TXREQ0 = 0x1; // Request message buffer 0 transmission
            break;
        case eCAN2:
            can2MsgBuf[0] = canTXMsgBuf[0];
            C2TR01CONbits.TXREQ0 = 0x1; // Request message buffer 0 transmission
            break;
        default:
            break;
    }
}

uint8_t* canReadData(can_t eCANx){
    switch (eCANx){
        case eCAN1:
            return can1MsgBuf[8].byteBuff;
        case eCAN2:
            return can2MsgBuf[8].byteBuff;
        default:
            return NULL;
    }
}

void canInit(can_t eCANx, uint32_t baud_rate, canIdLength_t idLength){
    switch (eCANx){
        case eCAN1:
            can1.baud_rate=baud_rate;
            can1.idLength=idLength;
            can1Init();
            canInterruptEnable(eCAN1); // interrupts enabled by default
            break;
        case eCAN2:
            can2.baud_rate=baud_rate;
            can2.idLength=idLength;
            can2Init();
            canInterruptEnable(eCAN2); // interrupts enabled by default
            break;
        default:
            break;
    }
}

void canInterruptEnable(can_t eCANx){
    switch(eCANx){
        case eCAN1:
            IFS0bits.DMA1IF = 0;    // clear flag
            IEC0bits.DMA1IE = 0x1;  // Enable DMA 1 interrupt
            break;
        case eCAN2:
            IFS2bits.DMA3IF = 0;    // clear flag
            IEC2bits.DMA3IE = 0x1;  // Enable DMA 3 interrupt
            break;
        default:
            break;
    }
}

void canInterruptDisable(can_t eCANx){
    switch(eCANx){
        case eCAN1:
            IEC0bits.DMA1IE = 0x0;  // Disable DMA 1 interrupt
            IFS0bits.DMA1IF = 0;    // clear flag
            break;
        case eCAN2:
            IEC2bits.DMA3IE = 0x0;  // Disable DMA 3 interrupt
            IFS2bits.DMA3IF = 0;    // clear flag
            break;
        default:
            break;
    }
}

void registerCANxCallback(can_t eCANx, Callback_t cbf_pointer)
{
    switch (eCANx)
    {
        case eCAN1:
            cbf_can1_pointer = cbf_pointer;
            break;
        case eCAN2:
            cbf_can2_pointer = cbf_pointer;
            break;
        default:
            break;
    }
}

void __attribute__((__interrupt__, __auto_psv__)) _DMA1Interrupt(void){
    C1RXFUL1bits.RXFUL8 = 0;    // clear buffer full bit
    IFS0bits.DMA1IF = 0;        // clear interrupt flag
    if (0!=cbf_can1_pointer)
    {
        cbf_can1_pointer();
    }
}

void __attribute__((__interrupt__, __auto_psv__)) _DMA3Interrupt(void){
    C2RXFUL1bits.RXFUL8 = 0;    // clear buffer full bit
    IFS2bits.DMA3IF = 0;        // clear interrupt flag
    if (0!=cbf_can2_pointer)
    {
        cbf_can2_pointer();
    }
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/

/// @private
void genCANBaudParam(uint32_t Fbaud, uint8_t *bestBRPVAL, uint8_t *bestNTQ, uint8_t *bestMULT)
{
    uint8_t BRPVAL;
    uint8_t NTQ;
    uint8_t MULT;
    float min;
    
    // Fcan=Fp=Fosc/2=(Fin*M/(N1*N2))/2, Ftq=15*Fbaud (15 Tq)
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
    uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));    
    
    for(NTQ=8; NTQ<26; NTQ++){
        for(MULT=1; MULT<3; MULT++){
            float Fcan = Fosc/2*MULT;
            float Ftq = NTQ*Fbaud;
    
            // Calculation of Baud Rate Prescaler: BRP = Fcan/(2*Ftq)-1
            float BRPVAL_f = (Fcan/(2*Ftq)-1);
            
            if (BRPVAL_f <= 0.0)
            {
                BRPVAL = 0x00;    // Min BRP value
            }
            else if (BRPVAL_f >= 0x3F)
            {
                BRPVAL = 0x3F;    // Max BRP value
            }
            else
            {
                // round to the nearest integer
                if((BRPVAL_f-(float)((uint8_t)BRPVAL_f)) <= 0.5){
                    BRPVAL = (uint8_t)BRPVAL_f;
                }
                else
                {
                    BRPVAL = (uint8_t)BRPVAL_f+1;
                }
            }
            
            float actualBR = Fcan/((BRPVAL+1)*(2*NTQ));
            
            float error = (Fbaud-actualBR)/Fbaud*100;
            float errorsq = error*error; // only positive values
            
            if (NTQ == 8 && MULT == 1) // first value
            {
                min = errorsq;
                (*bestBRPVAL) = BRPVAL;
                (*bestNTQ) = NTQ;
                (*bestMULT) = MULT-1;
            }
            else
            {
                if (errorsq < min)
                {
                    min = errorsq;
                    (*bestBRPVAL) = BRPVAL;
                    (*bestNTQ) = NTQ;
                    (*bestMULT) = MULT-1;
                }
            }
        }
    }
}
