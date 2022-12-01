/**
  ****************************************************************************
  * @file    xbee.c
  * @author  Andrea Enrile
  * @date    01.12.2019
  * @brief   Implementation of the Send & Write functions and Initialization of
  *			 UART 4 used by the XBee with 8 bit data, no parity, 1 stop bit by
  *          default. Baud range with Fosc = 120MHz: 57 Bd < baud < 3.75 MBd
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "xbee.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_xbee_rx_pointer = 0;
static Callback_t cbf_xbee_tx_pointer = 0;

/******************************************************************************/
/*                XBEE INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/

void xbeeInit(uint32_t baud)
{
    uint8_t BRGH_setting;
    uint16_t BRG_val;
    
    TRISFbits.TRISF0 = 1;   // (re)Set U4RX as input
    
	//Configuration of RPPs
	//*************************************************************
	// Unlock Registers
	//*************************************************************
	__builtin_write_OSCCONL(OSCCON & ~(1 << 6));
	//************************************************************
	// Configure Output Functions RPn Pins
	// (See TABLE 11-3 & TABLE 4-32)
  //*************************************************************
    RPOR9bits.RP97R		= 0b011101; // Assign XBee_TX(U4TX) To Pin RP97
	//*************************************************************
	// Configure Input Functions RPIn Pins
	// (See TABLE 11-1 & TABLE 4-33)
	//*************************************************************
	RPINR28bits.U4RXR  = 0b1100000; // Assign XBee_RX(U4RX) To Pin RPI96  
	//*************************************************************
	// Lock Registers
	//*************************************************************
	__builtin_write_OSCCONL(OSCCON | (1 << 6));
	
	U4MODEbits.UARTEN = 0;  // TX, RX DISABLED, ENABLE at end of func
	
	U4MODEbits.STSEL = 0;   // 1-Stop bit
	U4MODEbits.PDSEL = 0;   // No Parity, 8-Data bits
	U4MODEbits.ABAUD = 0;   // Auto-Baud disabled
    
    genXbeeBaudParam(baud, &BRGH_setting, &BRG_val);
	U4MODEbits.BRGH = BRGH_setting; // High Baud Rate Enable bit
	
	U4BRG = BRG_val;        // UART Baud Rate setting
	
	U4STAbits.UTXISEL0 = 0; // Interrupt after one TX character is transmitted
	U4STAbits.UTXISEL1 = 0;
	U4STAbits.URXISEL = 0b00;   // Interrupt after one RX character is received;
	
	U4MODEbits.UARTEN = 1;  // Enable UART
	U4STAbits.UTXEN = 1;    // Enable UART TX
	
    // Interrupt Controller Settings
    IPC22bits.U4TXIP = 1;   // Set IRQ priority level
	IFS5bits.U4TXIF = 0;    // Clear the Transmit Interrupt Flag
	IEC5bits.U4TXIE = 1;    // Enable Transmit Interrupts
	
    IPC22bits.U4RXIP = 1;   // Set IRQ priority level
	IFS5bits.U4RXIF = 0;    // Clear the RX Interrupt Flag
	IEC5bits.U4RXIE = 1;    // Enable RX Interrupts
}

/******************************************************************************/
/*                     XBEE USER FUNCTIONS Implementation                     */
/******************************************************************************/

void xbeeWriteChar(char c) 
{
	while(1 == U4STAbits.UTXBF){}
	U4TXREG = c;    // Write the data byte to the USART.
}

char xbeeReadChar(void) 
{
	while (0 == U4STAbits.URXDA);   // Wait for data to be available
	return U4RXREG;
}

/******************************************************************************/
/*                        XBee Interrupt Routines (IRQ)                       */
/******************************************************************************/
void xbeeInterruptEnable(rx_tx_t rxtx){
    
    switch (rxtx){
        case eTX:
            IFS5bits.U4TXIF = 0;    // Clear the Transmit Interrupt Flag
            IEC5bits.U4TXIE = 1;    // Enable Transmit Interrupts
            break;
        case eRX:
            IFS5bits.U4RXIF = 0;    // Clear the RX Interrupt Flag
            IEC5bits.U4RXIE = 1;    // Enable RX Interrupts
            break;
        default:
            break;
    }
}

void xbeeInterruptDisable(rx_tx_t rxtx){

    switch (rxtx){
        case eTX:
            IEC5bits.U4TXIE = 0;    // Disable Transmit Interrupts
            IFS5bits.U4TXIF = 0;    // Clear the Transmit Interrupt Flag
            break;
        case eRX:
            IEC5bits.U4RXIE = 0;    // Disable RX Interrupts
            IFS5bits.U4RXIF = 0;    // Clear the RX Interrupt Flag
            break;
        default:
            break;
    }    
}


//Callback register function
void registerXbeeCallback(rx_tx_t rxtx, Callback_t cbf_pointer)
{
    if (eRX==rxtx)
    {
        cbf_xbee_rx_pointer = cbf_pointer;
    }
    else
    {
        cbf_xbee_tx_pointer = cbf_pointer;
    }
}
//UART4 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U4TXInterrupt(void)
{
  IFS5bits.U4TXIF = 0;    // Clear the Transmit Interrupt Flag
  if (0!=cbf_xbee_tx_pointer)
  {
    cbf_xbee_tx_pointer();
  }
}

//UART4 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U4RXInterrupt(void)
{
  IFS5bits.U4RXIF = 0;    // Clear the Receive Interrupt Flag
  if (0!=cbf_xbee_rx_pointer)
  {
    cbf_xbee_rx_pointer();
  }
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genXbeeBaudParam(uint32_t baud, uint8_t *BRGH_bit, uint16_t *BRG_val)
{
    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
    uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
    uint32_t Fcy = Fosc >> 1;

//	// Abort the program if baud = 0 or a pointer address is NULL.
//	if(baud == 0 || BRGH_bit == NULL || BRG_val == NULL)
//	{
//		assert(0);
//	}
    
    if (baud <= Fcy/(16*((uint32_t)0xFFFF+1)))
    {
        *BRGH_bit = 0;
        *BRG_val = UINT16_MAX;  // Min achievable baudrate
    }
    else if (baud <= Fcy/(4*((uint32_t)0xFFFF+1)))
    {
        *BRGH_bit = 0;
        *BRG_val = (uint16_t)(Fcy/(16.0*baud)+0.5)-1;
    }
    else if(baud >= Fcy/4)
    {
        *BRGH_bit = 1;
        *BRG_val = 0x0000;    // Max achievable baudrate
    }
    else
    {
        *BRGH_bit = 1;
        *BRG_val = (uint16_t)(Fcy/(4.0*baud)+0.5)-1;
    }				
}