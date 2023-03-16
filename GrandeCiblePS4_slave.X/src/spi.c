/**
  ****************************************************************************
  * @file    spi.c
  * @author  Michel Bovet
  * @date    26.02.2020
  * @brief   Implementation of the Send & Write functions and Initialization of
  *          SPI 3 in master by default. Serial clock frequency with Fosc =
  *          120MHz: 117 kHz < fsck < 30 MHz
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "spi.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

#ifdef ML180V3
static Callback_t cbf_spi2_pointer = 0;
#endif
static Callback_t cbf_spi3_pointer = 0;

/******************************************************************************/
/*                SPI3 INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/

void spiInit(spi_t eSPIx, uint16_t fsck, spiDataLength_t data_length, spiMode_t mode, spiSdiSample_t sdi_sample)
{
    switch(eSPIx)
    {   
        uint8_t pprescale = 0, sprescale = 0;
#ifdef ML180V3
        case eSPI2:
            TRISDbits.TRISD8 = 1;       // (re)Set SDI2 as input
            
            // Configuration of SPI2 _SS2 pin
            TRISDbits.TRISD12 = 0;      // 0 = SPI2 _SS2 pin as output (manually driven)
            _SS2 = 1;                   // SPI2 _SS2 pin = 1

            /***************************************************************************
             * Silicon Errata #36, but resolve according to https://www.microchip.com/forums/m1015134-p2.aspx
             * "...By setting the output that will be connected to SCLK to SCLK's inactive
             * state (i.e. _LATC1 = 1 if CKP = 1) before configuring the PPS and SPI... "
             **************************************************************************/
            TRISDbits.TRISD5 = 0;      // 0 = SPI2 SCK2 pin as output (manually driven)
            if(mode == TxMode0 || mode == TxMode1)
            {
                LATDbits.LATD5 = 0;    // SPI2 SCK2 pin = 0
            }
            else
            {
                LATDbits.LATD5 = 0;    // SPI3 SCK3 pin = 1
            }

            //Configuration of RPPs
            //*************************************************************
            // Unlock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
            //************************************************************
            // Configure Output Functions RPn Pins
            // (See TABLE 11-3 & TABLE 4-32)
            //*************************************************************
            RPOR8bits.RP69R      = 0b001001; // Assign SCK2 To Pin RP69
            RPOR8bits.RP70R		 = 0b001000; // Assign SDO2 To Pin RP70
            //*************************************************************
            // Configure Input Functions RPIn Pins
            // (See TABLE 11-1 & TABLE 4-33)
            //*************************************************************
            /*"...On this PIC, if you use PPS SPI you have to set the SCK pin as an input
             * and as output..." Forum source; https://www.microchip.com/forums/m843542.aspx
             */
            RPINR22bits.SCK2R   = 0b1000101; // Assign SCK2 To Pin RP69
            RPINR22bits.SDI2R   = 0b1001000; // Assign SDI2 To Pin RPI72
            //*************************************************************
            // Lock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON | (1 << 6));

            /* The following code sequence shows SPI register configuration for master mode */
            SPI2STATbits.SPIEN = 0; // Disable SPI module

            IFS2bits.SPI2IF = 0;    // Clear the Interrupt flag
            IEC2bits.SPI2IE = 0;    // Disable the interrupt

            /********** SPI1CON1 Register Settings **********/ 
            SPI2CON1bits.DISSCK = 0; // Internal SPI clock is enabled
            SPI2CON1bits.DISSDO = 0; // SDOx pin is controlled by the module

            switch (data_length)
            {
                case byte8 :
                    SPI2CON1bits.MODE16 = 0; // Communication is byte-wide (8 bits)
                    break;
                case word16 :
                    SPI2CON1bits.MODE16 = 1; // Communication is word-wide (16 bits)
                    break;
                default :
                    break;
            }

            switch (sdi_sample)
            {
                case RxMiddle :
                    SPI2CON1bits.SMP = 0; // Input data is sampled at the MIDDLE of data output time
                    break;
                case RxEnd :
                    SPI2CON1bits.SMP = 1; // Input data is sampled at the END of data output time
                    break;
                default :
                    break;
            }    

            /* | SPI mode | CKP | CKE |
             * +----------+-----+-----+
             * |    0     |  0  |  1  | Clock Idle state = high, Transmit occurs on transition from active to Idle clock state.
             * |    1     |  0  |  0  | Clock Idle state = high, Transmit occurs on transition from Idle to active clock state.
             * |    2     |  1  |  1  | Clock Idle state = low, Transmit occurs on transition from active to Idle clock state.
             * |    3     |  1  |  0  | Clock Idle state = low, Transmit occurs on transition from Idle to active clock state.
             */
            switch (mode)
            {
                case TxMode0 :
                    SPI2CON1bits.CKP = 0;
                    SPI2CON1bits.CKE = 1;
                    break;
                case TxMode1 :
                    SPI2CON1bits.CKP = 0;
                    SPI2CON1bits.CKE = 0;
                    break;
                case TxMode2 :
                    SPI2CON1bits.CKP = 1;
                    SPI2CON1bits.CKE = 1;
                    break;
                case TxMode3 :
                    SPI2CON1bits.CKP = 1;
                    SPI2CON1bits.CKE = 0;
                    break;
                default :
                    break;
            }

            SPI2CON1bits.SSEN = 0;  // SSx pin is not used by module
            SPI2CON1bits.MSTEN = 1; // Master mode enable

            genSpiPrescaleParam(fsck, &pprescale, &sprescale);
            SPI2CON1bits.PPRE = pprescale; // Set Primary prescale (0=64:1, 1=16:1, 2=4:1, 3=1:1)
            SPI2CON1bits.SPRE = sprescale; // Set Secondary prescale (8:1, ... 1:1)

            /********* SPI3STAT Register Settings **********/ 
            SPI2STATbits.SPIROV = 0;    // Reset Receive Overflow 
            SPI2STATbits.SPIEN = 1;     // Enable SPI module

            // Interrupt Controller Settings
            IPC8bits.SPI2IP = 3;    // Set IRQ priority level
            IFS2bits.SPI2IF = 0;    // Clear the Interrupt flag
            IEC2bits.SPI2IE = 1;    // Enable the interrupt
            break;
#endif
        case eSPI3:
            TRISGbits.TRISG12 = 1;      // (re)Set SDI3 as input
            // Configuration of SPI3 _SS3 pin
            TRISGbits.TRISG13 = 0;      // 0 = SPI3 _SS3 pin as output (manually driven)
            _SS3 = 1;                   // SPI3 _SS3 pin = 1

            /***************************************************************************
             * Silicon Errata #36, but resolve according to https://www.microchip.com/forums/m1015134-p2.aspx
             * "...By setting the output that will be connected to SCLK to SCLK's inactive
             * state (i.e. _LATC1 = 1 if CKP = 1) before configuring the PPS and SPI... "
             **************************************************************************/
            TRISGbits.TRISG14 = 0;  // 0 = SPI3 SCK3 pin as output (manually driven)
            if(mode == TxMode0 || mode == TxMode1)
            {
                LATGbits.LATG14 = 0;   // SPI3 SCK3 pin = 0
            }
            else
            {
                LATGbits.LATG14 = 1;   // SPI3 SCK3 pin = 1
            }

            //Configuration of RPPs
            //*************************************************************
            // Unlock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
            //************************************************************
            // Configure Output Functions RPn Pins
            // (See TABLE 11-3 & TABLE 4-32)
            //*************************************************************
            RPOR12bits.RP126R   = 0b100000; // Assign SCK3 To Pin RP126
            RPOR4bits.RP42R		= 0b011111; // Assign SDO3 To Pin RP42
            //*************************************************************
            // Configure Input Functions RPIn Pins
            // (See TABLE 11-1 & TABLE 4-33)
            //*************************************************************
            /*"...On this PIC, if you use PPS SPI you have to set the SCK pin as an input
             * and as output..." Forum source; https://www.microchip.com/forums/m843542.aspx
             */
            RPINR29bits.SCK3R   = 0b1111110; // Assign SCK3 To Pin RP126
            RPINR29bits.SDI3R   = 0b1111100; // Assign SDI3 To Pin RPI124
            //*************************************************************
            // Lock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON | (1 << 6));

            /* The following code sequence shows SPI register configuration for master mode */
            SPI3STATbits.SPIEN = 0; // Disable SPI module

            IFS5bits.SPI3IF = 0;    // Clear the Interrupt flag
            IEC5bits.SPI3IE = 0;    // Disable the interrupt

            /********** SPI1CON1 Register Settings **********/ 
            SPI3CON1bits.DISSCK = 0; // Internal SPI clock is enabled
            SPI3CON1bits.DISSDO = 0; // SDOx pin is controlled by the module

            switch (data_length)
            {
                case byte8 :
                    SPI3CON1bits.MODE16 = 0; // Communication is byte-wide (8 bits)
                    break;
                case word16 :
                    SPI3CON1bits.MODE16 = 1; // Communication is word-wide (16 bits)
                    break;
                default :
                    break;
            }

            switch (sdi_sample)
            {
                case RxMiddle :
                    SPI3CON1bits.SMP = 0; // Input data is sampled at the MIDDLE of data output time
                    break;
                case RxEnd :
                    SPI3CON1bits.SMP = 1; // Input data is sampled at the END of data output time
                    break;
                default :
                    break;
            }    

            /* | SPI mode | CKP | CKE |
             * +----------+-----+-----+
             * |    0     |  0  |  1  | Clock Idle state = high, Transmit occurs on transition from active to Idle clock state.
             * |    1     |  0  |  0  | Clock Idle state = high, Transmit occurs on transition from Idle to active clock state.
             * |    2     |  1  |  1  | Clock Idle state = low, Transmit occurs on transition from active to Idle clock state.
             * |    3     |  1  |  0  | Clock Idle state = low, Transmit occurs on transition from Idle to active clock state.
             */
            switch (mode)
            {
                case TxMode0 :
                    SPI3CON1bits.CKP = 0;
                    SPI3CON1bits.CKE = 1;
                    break;
                case TxMode1 :
                    SPI3CON1bits.CKP = 0;
                    SPI3CON1bits.CKE = 0;
                    break;
                case TxMode2 :
                    SPI3CON1bits.CKP = 1;
                    SPI3CON1bits.CKE = 1;
                    break;
                case TxMode3 :
                    SPI3CON1bits.CKP = 1;
                    SPI3CON1bits.CKE = 0;
                    break;
                default :
                    break;
            }

            SPI3CON1bits.SSEN = 0;  // SSx pin is not used by module
            SPI3CON1bits.MSTEN = 1; // Master mode enable

            genSpiPrescaleParam(fsck, &pprescale, &sprescale);
            SPI3CON1bits.PPRE = pprescale; // Set Primary prescale (0=64:1, 1=16:1, 2=4:1, 3=1:1)
            SPI3CON1bits.SPRE = sprescale; // Set Secondary prescale (8:1, ... 1:1)

            /********* SPI3STAT Register Settings **********/ 
            SPI3STATbits.SPIROV = 0;    // Reset Receive Overflow 
            SPI3STATbits.SPIEN = 1;     // Enable SPI module

            // Interrupt Controller Settings
            IPC22bits.SPI3IP = 3;   // Set IRQ priority level
            IFS5bits.SPI3IF = 0;    // Clear the Interrupt flag
            IEC5bits.SPI3IE = 1;    // Enable the interrupt
            break;
        default:
            break;
    }
}

/******************************************************************************/
/*                     SPI3 USER FUNCTIONS Implementation                     */
/******************************************************************************/
void spiWrite(spi_t eSPIx, uint16_t TxData) 
{
    switch(eSPIx)
    {
#ifdef ML180V3
        case eSPI2:
//            // If using Buffer flexibility: (1 extra data can be stored in buffer even if
//            // SPI2 Tx already in progress BUT _SS2 and spiRead(eSPI2) must be managed in IRQ)
//            while(SPI2STATbits.SPITBF == 1);
    
            // If not using Buffer flexibility: Test if SPI Tx already in progress =>
            // wait on SPI IRQ to set _SS2 = 1 and complete the current transfer
            if (_SS2 == 0)
            {
                // Should not happen: means that the last SPI send is not complete
                while(_SS2 == 0);   // wait the end of the current transfer
                //uint16_t RxData = spiRead(eSPI2); // Read buffer to guarantee no overflow
            }

            _SS2 = 0;

            SPI2BUF = TxData;
            break;
#endif
        case eSPI3:
//            // If using Buffer flexibility: (1 extra data can be stored in buffer even if
//            // SPI3 Tx already in progress BUT _SS3 and spi3Read() must be managed in IRQ)
//            while(SPI3STATbits.SPITBF == 1);
    
            // If not using Buffer flexibility: Test if SPI Tx already in progress =>
            // wait on SPI IRQ to set _SS3 = 1 and complete the current transfert
            if (_SS3 == 0)
            {
                // Should not happen: means that the last SPI send is not complete
                while(_SS3 == 0);   // wait the end of the current transert
                //uint16_t RxData = spi3Read(); // Read buffer to guarantee no overflow
            }

            _SS3 = 0;

            SPI3BUF = TxData;
            break;
        default:
            break;
    }
}

uint16_t spiRead(spi_t eSPIx)
{
    switch(eSPIx)
    {
#ifdef ML180V3
        case eSPI2:
            if (IEC2bits.SPI2IE == 0)       // IRQ not set => polling
            {
                while(SPI2STATbits.SPIRBF == 0);
                _SS2 = 1;
            }

//            // If Buffer flexibility used in spiWrite() AND this function not used in IRQ
//            if(SPI2STATbits.SPITBF == 1)    // Next Tx data is already in the buffer
//            {
//                _SS2 = 1;
//                // Add delay?
//                _SS2 = 0;
//                //    // If Buffer flexibility used in spiWrite() AND this function not used in IRQ/    }

            if (SPI2STATbits.SPIROV == 1)   // Overflow has occurred?
            {
                // Do something else?
                SPI2STATbits.SPIROV = 0;    // Clear overflow
            }

            return SPI2BUF;
            break;
#endif
        case eSPI3:
            if (IEC5bits.SPI3IE == 0)       // IRQ not set => polling
            {
                while(SPI3STATbits.SPIRBF == 0);
                _SS3 = 1;
            }

//            // If Buffer flexibility used in spiWrite() AND this function not used in IRQ
//            if(SPI3STATbits.SPITBF == 1)    // Next Tx data is already in the buffer
//            {
//                _SS3 = 1;
//                // Add delay?
//                _SS3 = 0;
//                //    // If Buffer flexibility used in spiWrite() AND this function not used in IRQ/    }

            if (SPI3STATbits.SPIROV == 1)   // Overflow has occurred?
            {
                // Do something else?
                SPI3STATbits.SPIROV = 0;    // Clear overflow
            }

            return SPI3BUF;
            break;
        default:
            break;
    }
}

/******************************************************************************/
/*                        SPI Interrupt Routines (IRQ)                        */
/******************************************************************************/
void spiInterruptEnable(spi_t eSPIx){
    switch(eSPIx)
    {
#ifdef ML180V3
        case eSPI2:
            IFS2bits.SPI2IF = 0;    // Clear the Interrupt flag
            IEC2bits.SPI2IE = 1;    // Enable the interrupt 
            break;
#endif
        case eSPI3:
            IFS5bits.SPI3IF = 0;    // Clear the Interrupt flag
            IEC5bits.SPI3IE = 1;    // Enable the interrupt 
            break;
        default:
            break;
    }   
}

void spiInterruptDisable(spi_t eSPIx){
    switch(eSPIx)
    {
#ifdef ML180V3
        case eSPI2:
            IEC2bits.SPI2IE = 0;    // Disable the interrupt  
            IFS2bits.SPI2IF = 0;    // Clear the Interrupt flag
            break;
#endif
        case eSPI3:
            IEC5bits.SPI3IE = 0;    // Disable the interrupt    
            IFS5bits.SPI3IF = 0;    // Clear the Interrupt flag
            break;
        default:
            break;
    }
}

//Callback register function
void registerSPIxCallback(spi_t eSPIx, Callback_t cbf_pointer)
{
    switch(eSPIx)
    {
#ifdef ML180V3
        case eSPI2:
            cbf_spi2_pointer = cbf_pointer;
            break;
#endif
        case eSPI3:
            cbf_spi3_pointer = cbf_pointer;
            break;
        default:
            break;
    }
}

#ifdef ML180V3
//SPI2 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _SPI2Interrupt(void)
{
  _SS2 = 1;

//    // Only if buffer flexibility is used in spiSend() AND if spi3Read() is
//    // performed in this IRQ (optimally after this test)
//    if(SPI2STATbits.SPITBF == 1)    // Next Tx data is already in the buffer
//    {
//        // Add delay?
//        _SS2 = 0;
//    }
    
  IFS2bits.SPI2IF = 0;    // Clear the SPI Interrupt Flag
  if (0!=cbf_spi2_pointer)
  {
    cbf_spi2_pointer();
  }    
}
#endif

//SPI3 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _SPI3Interrupt(void)
{
  _SS3 = 1;

//    // Only if buffer flexibility is used in spiSend() AND if spi3Read() is
//    // performed in this IRQ (optimally after this test)
//    if(SPI3STATbits.SPITBF == 1)    // Next Tx data is already in the buffer
//    {
//        // Add delay?
//        _SS3 = 0;
//    }
    
  IFS5bits.SPI3IF = 0;    // Clear the SPI Interrupt Flag
  if (0!=cbf_spi3_pointer)
  {
    cbf_spi3_pointer();
  }    
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genSpiPrescaleParam(uint16_t fsck, uint8_t *pprescale, uint8_t *sprescale)
{
//	// Abort the program if a pointer address is NULL.
//	if(pprescale == NULL || sprescale == NULL)
//	{
//		assert(0);
//	}
    
    const uint8_t tempPprescalerVal[4] = {64,16,4,1};
    uint8_t tempSprescaler = 0;
    
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
	uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
	uint32_t FP = Fosc >> 1;
    
    uint8_t i, j;
	for(i = 3; i >= 0; i--)
	{
        if (i==3)
        {
            // Note: primary and secondary prescalers cannot be both set to the
            //       1:1 value
            tempSprescaler = 2;
        }
        else
        {
            tempSprescaler = 1;
        }
        
        /* Fsck*1000 = FP/(Primary Prescaler * Secondary Prescaler)
         * Note: Do not set both primary and secondary prescalers to the
         *       value of 1:1
         */
        
        // Test with primary and min secondary prescaler value
        if((FP/(tempPprescalerVal[i]*tempSprescaler)) < (fsck*1000UL))
        {
            // Set to min primary and min secondary prescaler value (max fsck))
            *pprescale = 0b11;  // Set to 1:1
            *sprescale = 0b110; // Set to 2:1 (cannot be both set to 1:1)
            break;
        }
        else
        {
            // Test with max secondary prescaler value
            if((FP/(tempPprescalerVal[i]*8)) < (fsck*1000UL))
            {
                // Test optimal secondary prescaler value
                for(j = 2; j <= 8; j++)
                {
                    if((FP/(tempPprescalerVal[i]*j)) < (fsck*1000UL))
                    {
                        *pprescale = i;
                        *sprescale = 8-j;
                        break;
                    }
                }
                break;
            }
            else
            {
                // Set to max primary and max secondary prescaler value (min fsck))
                if (i == 0)
                {
                    *pprescale = 0b00;  // Set to 8:1
                    *sprescale = 0b000; // Set to 64:1
                    break;
                }
            }
        }
	}
}