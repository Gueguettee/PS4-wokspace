/**
  ****************************************************************************
  * @file    gpio.c
  * @author  Andrea Enrile
  * @date    13.11.2019
  * @brief   Function for the configuration of the different PORT and PORT Bits
  *          and reading/writing from/to the I/O
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "gpio.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_int0_pointer = 0;
static Callback_t cbf_int1_pointer = 0;
static Callback_t cbf_int2_pointer = 0;
static Callback_t cbf_int3_pointer = 0;
static Callback_t cbf_int4_pointer = 0;

/******************************************************************************/
/*                GPIO INITIALIZATION FUNCTION Inplementation                 */
/******************************************************************************/

void gpioInit(void)
{
	// Setting all GPIO as digital (0) or Analog (1)
    ANSELA = 0x0003;
    ANSELB = 0x000F;
    ANSELC = 0x0003;
	ANSELD = 0x0000;
    ANSELE = 0x0000;
	ANSELF = 0x0600;
    ANSELG = 0x0000;
	
	// Setting Analog and Digital as input (1) by default, except 2 LEDs outputs (0)
	TRISA = 0xFFFF;
    TRISB = 0xFFFF;
    TRISC = 0xFBF7;
	TRISD = 0xFFFF;
    TRISE = 0xFFFF;
	TRISF = 0xFFFF;
    TRISG = 0xFFFF;
    
    /* As PWM I/Os are not necessarily dedicated to PWM only, disable default 
     * configuration "PWM module control all PWMxH & et PWMxH" to have "GPIO
     * module control all PWMxH & PWMxH pins"
     */
    // With config PWMLOCK = OFF
    IOCON1bits.PENH = 0x0;  // GPIO module control PWM1H
    IOCON1bits.PENL = 0x0;  // GPIO module control PWM1L
    IOCON2bits.PENH = 0x0;  // GPIO module control PWM2H
    IOCON2bits.PENL = 0x0;  // GPIO module control PWM2L
    IOCON3bits.PENH = 0x0;  // GPIO module control PWM3H
    IOCON3bits.PENL = 0x0;  // GPIO module control PWM3L
    IOCON4bits.PENH = 0x0;  // GPIO module control PWM4H
    IOCON4bits.PENL = 0x0;  // GPIO module control PWM4L
    IOCON5bits.PENH = 0x0;  // GPIO module control PWM5H
    IOCON5bits.PENL = 0x0;  // GPIO module control PWM5L
    IOCON6bits.PENH = 0x0;  // GPIO module control PWM6H
    IOCON6bits.PENL = 0x0;  // GPIO module control PWM6L

    // With config PWMLOCK = ON
//    __builtin_write_PWMSFR(&IOCON1, (IOCON1 & 0x3FFF), &PWMKEY);
//    __builtin_write_PWMSFR(&IOCON2, (IOCON2 & 0x3FFF), &PWMKEY);
//    __builtin_write_PWMSFR(&IOCON3, (IOCON3 & 0x3FFF), &PWMKEY);
//    __builtin_write_PWMSFR(&IOCON4, (IOCON4 & 0x3FFF), &PWMKEY);
//    __builtin_write_PWMSFR(&IOCON5, (IOCON5 & 0x3FFF), &PWMKEY);
//    __builtin_write_PWMSFR(&IOCON6, (IOCON6 & 0x3FFF), &PWMKEY);
}

/******************************************************************************/
/*                     GPIO USER FUNCTIONS Inplementation                     */
/******************************************************************************/

uint16_t gpioPortRead(port_t ePORTx)
{
	uint16_t portValue = 0;	//Value of the entire port
    
    // Switch for reading the value of the corresponding PORT
	switch(ePORTx)
    {
		case ePORTA:
			portValue = PORTA;
			break;
		case ePORTB:
			portValue = PORTB;
			break;
		case ePORTC:
			portValue = PORTC;
			break;
		case ePORTD:
			portValue = PORTD;
			break;
		case ePORTE:
			portValue = PORTE;
			break;
		case ePORTG:
			portValue = PORTG;
			break;
		default:
			portValue = 0;
			break;
	}
	return portValue;
}

bool gpioBitRead(port_t ePORTx, uint16_t BIT)
{
	uint16_t portValue = 0;	// Value of the entire port
	bool bitValue = 0;	// Value of the desired bit
	
	portValue = gpioPortRead(ePORTx);
	
	// Masking on the entire port value to isolate the desired bit
	portValue = portValue & BIT;
	
	switch(BIT)
    {
		case 0x0001:
            bitValue = (bool) portValue;
			break;
		case 0x0002:
			bitValue = (bool) (portValue >> 1);
			break;
		case 0x0004:
			bitValue = (bool) (portValue >> 2);
			break;
		case 0x0008:
			bitValue = (bool) (portValue >> 3);
			break;
		case 0x0010:
			bitValue = (bool) (portValue >> 4);
			break;
		case 0x0020:
			bitValue = (bool) (portValue >> 5);
			break;
		case 0x0040:
			bitValue = (bool) (portValue >> 6);
			break;
		case 0x0080:
			bitValue = (bool) (portValue >> 7);
			break;
		case 0x0100:
			bitValue = (bool) (portValue >> 8);
			break;
		case 0x0200:
			bitValue = (bool) (portValue >> 9);
			break;
		case 0x0400:
			bitValue = (bool) (portValue >> 10);
			break;
		case 0x0800:
			bitValue = (bool) (portValue >> 11);
			break;
		case 0x1000:
			bitValue = (bool) (portValue >> 12);
			break;
		case 0x2000:
			bitValue = (bool) (portValue >> 13);
			break;
		case 0x4000:
			bitValue = (bool) (portValue >> 14);
			break;
		case 0x8000:
			bitValue = (bool) (portValue >> 15);
			break;
		default:
			break;
	}
	
	return bitValue;	
}

uint16_t gpioRead(port_t ePORTx, uint16_t BITs)
{
    uint16_t portValue = 0;	// Value of the entire port
	
	portValue = gpioPortRead(ePORTx);
	
	// Masking on the entire port value to return only the desired bit(s)
	return(portValue & BITs);
}

bool gpioPortWrite(port_t ePORTx, uint16_t value)
{	
	// Switch to write the value on the corresponding PORT
	switch(ePORTx)
    {
		case ePORTA:
			LATA = value;
			break;
		case ePORTB:
			LATB = value;
			break;
		case ePORTC:
			LATC = value;
			break;
		case ePORTD:
			LATD = value;
			break;
		case ePORTE:
			LATE = value;
			break;
		case ePORTG:
			LATG = value;
			break;
		default:
            // No changes on LAT register and return that modification failed
			return false;
			break;
	}
	return true;
}

bool gpioBitWrite(port_t ePORTx, uint16_t BIT, uint16_t value)
{
	uint16_t oldLatValue = 0;
	uint16_t invertedBitValue = ~BIT;
	
	// Switch to write the value on the corresponding BIT(s) PORT
	switch(ePORTx)
    {
		case ePORTA:
			oldLatValue = LATA;
			if(HIGH == value)
            {
				LATA = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATA = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		case ePORTB:
			oldLatValue = LATB;
			if(HIGH == value)
            {
				LATB = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATB = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		case ePORTC:
			oldLatValue = LATC;
			if(HIGH == value)
            {
				LATC = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATC = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		case ePORTD:
			oldLatValue = LATD;
			if(HIGH == value)
            {
				LATD = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATD = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		case ePORTE:
			oldLatValue = LATE;
			if(HIGH == value)
            {
				LATE = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATE = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		case ePORTG:
			oldLatValue = LATG;
			if(HIGH == value)
            {
				LATG = (oldLatValue | BIT); // Masking the old value, so the desired bit(s) are set
			}
			else
            {
				LATG = (oldLatValue & invertedBitValue); // Masking the old value, so the desired bit(s) are cleared
			}
			break;
		default:
            // No changes on LAT register and return that modification failed
			return false;
			break;
	}
	return true;
}

bool gpioPortConfig(port_t ePORTx, uint16_t value)
{	
	// Switch to write the value in the TRISx register of the corresponding PORT
	switch(ePORTx)
    {
		case ePORTA:
			TRISA = value;
			break;
		case ePORTB:
			TRISB = value;
			break;
		case ePORTC:
			TRISC = value;
			break;
		case ePORTD:
			TRISD = value;
			break;
		case ePORTE:
			TRISE = value;
			break;
		case ePORTG:
			TRISG = value;
			break;
		default:
            // No changes on TRIS register and return that modification failed
			return false;
			break;
	}
	return true;
}

bool gpioBitConfig(port_t ePORTx, uint16_t BIT, uint16_t direction)
{
	uint16_t oldTrisValue = 0;
	uint16_t invertedBitValue = ~BIT;
	
	// Switch to write the direction to selected GPIO PORT bit(s)
	switch(ePORTx)
    {
		case ePORTA:
			oldTrisValue = TRISA;
			if(INPUT == direction)
            {
				TRISA = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISA = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		case ePORTB:
			oldTrisValue = TRISB;
			if(INPUT == direction)
            {
				TRISB = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISB = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		case ePORTC:
			oldTrisValue = TRISC;
			if(INPUT == direction)
            {
				TRISC = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISC = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		case ePORTD:
			oldTrisValue = TRISD;
			if(INPUT == direction)
            {
				TRISD = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISD = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		case ePORTE:
			oldTrisValue = TRISE;
			if(INPUT == direction)
            {
				TRISE = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISE = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		case ePORTG:
			oldTrisValue = TRISG;
			if(INPUT == direction)
            {
				TRISG = (oldTrisValue | BIT); // Masking the old value, so the desired bit(s) are set as input
			}
			else
            {
				TRISG = (oldTrisValue & invertedBitValue); // Masking the old value, so the desired bit(s) are set as output
			}
			break;
		default:
            // No changes on TRIS register and return that modification failed
			return false;
			break;
	}
	return true;
}

void externInterruptInit(extINT_t eINTx, edge_t edgeSelect)
{
	switch(eINTx)
    {
		case eINT1:
            TRISBbits.TRISB14 = 0x1;    // (re)Set PWM1H/INT1 as input
            
			//Configuration of RPPs
			//*************************************************************
			// Unlock Registers
			//*************************************************************
			__builtin_write_OSCCONL(OSCCON & ~(1 << 6));
			//*************************************************************
			// Configure Input Functions RPIn Pins
			// (See TABLE 11-1 & TABLE 4-33)
			//*************************************************************
			RPINR0bits.INT1R    = 0x2E; // Assign INT1 To Pin RPI46
			//*************************************************************
			// Lock Registers
			//*************************************************************
			__builtin_write_OSCCONL(OSCCON | (1 << 6));

            INTCON2bits.INT1EP = edgeSelect;    // Set INTx edge
            
            // Interrupt Controller Settings
            IPC5bits.INT1IP = 4;        // Set INT1 IRQ priority level
			IFS1bits.INT1IF = 0;        // Reset INT1 interrupt flag
            IEC1bits.INT1IE = 1;        // Enable INT1 Interrupt Service Routine
			break;
		case eINT2:
			TRISAbits.TRISA12 = 0x1;    // (re)Set RA12/INT2 as input
            
			//Configuration of RPPs
			//*************************************************************
			// Unlock Registers
			//*************************************************************
			__builtin_write_OSCCONL(OSCCON & ~(1 << 6));
			//*************************************************************
			// Configure Input Functions RPIn Pins
			// (See TABLE 11-1 & TABLE 4-33)
			//*************************************************************
			RPINR1bits.INT2R    = 0x1C; // Assign INT2 To Pin RPI28
			//*************************************************************
			// Lock Registers
			//*************************************************************
			__builtin_write_OSCCONL(OSCCON | (1 << 6));
			
            INTCON2bits.INT2EP = edgeSelect;    // Set INTx edge
            
            // Interrupt Controller Settings
            IPC7bits.INT2IP = 4;        // Set INT2 IRQ priority level
			IFS1bits.INT2IF = 0;        // Reset INT2 interrupt flag
			IEC1bits.INT2IE = 1;        // Enable INT2 Interrupt Service Routine
			break;
		case eINT3:
			TRISAbits.TRISA14 = 0x1;    // (re)Set RA14/INT3 as input
            
            INTCON2bits.INT3EP = edgeSelect;    // Set INTx edge
            
            // Interrupt Controller Settings
            IPC13bits.INT3IP = 4;       // Set INT3 IRQ priority level
			IFS3bits.INT3IF = 0;        // Reset INT3 interrupt flag
			IEC3bits.INT3IE = 1;        // Enable INT3 Interrupt Service Routine
			break;
		case eINT4:
			TRISAbits.TRISA15 = 0x1;    // (re)Set RA15/INT4 as input
            
            INTCON2bits.INT4EP = edgeSelect;    // Set INTx edge
            
            // Interrupt Controller Settings
            IPC13bits.INT4IP = 4;       // Set INT4 IRQ priority level
			IFS3bits.INT4IF = 0;        // Reset INT4 interrupt flag
			IEC3bits.INT4IE = 1;        // Enable INT4 Interrupt Service Routine
			break;
		default:
			break;
	}
}

void externInterruptEnable(extINT_t eINTx)
{
	switch(eINTx)
    {
		case eINT1:
			IFS1bits.INT1IF = 0;        // Reset INT1 interrupt flag
            IEC1bits.INT1IE = 1;        // Enable INT1 Interrupt Service Routine
			break;
		case eINT2:
			IFS1bits.INT2IF = 0;        // Reset INT2 interrupt flag
			IEC1bits.INT2IE = 1;        // Enable INT2 Interrupt Service Routine
			break;
		case eINT3:
			IFS3bits.INT3IF = 0;        // Reset INT3 interrupt flag
			IEC3bits.INT3IE = 1;        // Enable INT3 Interrupt Service Routine
			break;
		case eINT4:
			IFS3bits.INT4IF = 0;        // Reset INT4 interrupt flag
			IEC3bits.INT4IE = 1;        // Enable INT4 Interrupt Service Routine
			break;
		default:
			break;
	}
}

void externInterruptDisable(extINT_t eINTx)
{
	switch(eINTx)
    {
		case eINT1:
            IEC1bits.INT1IE = 0;        // Disable INT1 Interrupt Service Routine
			IFS1bits.INT1IF = 0;        // Reset INT1 interrupt flag
			break;
		case eINT2:
			IEC1bits.INT2IE = 0;        // Disable INT2 Interrupt Service Routine
			IFS1bits.INT2IF = 0;        // Reset INT2 interrupt flag
			break;
		case eINT3:
			IEC3bits.INT3IE = 0;        // Disable INT3 Interrupt Service Routine
			IFS3bits.INT3IF = 0;        // Reset INT3 interrupt flag
			break;
		case eINT4:
			IEC3bits.INT4IE = 0;        // Disable INT4 Interrupt Service Routine
			IFS3bits.INT4IF = 0;        // Reset INT4 interrupt flag
			break;
		default:
			break;
	}
}

/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//Callback register function
void registerExternCallback(extINT_t intx, Callback_t cbf_pointer)
{
    switch (intx)
    {
        case eINT1:
            cbf_int1_pointer = cbf_pointer;
            break;
        case eINT2:
            cbf_int2_pointer = cbf_pointer;
            break;
        case eINT3:
            cbf_int3_pointer = cbf_pointer;
            break;
        case eINT4:
            cbf_int4_pointer = cbf_pointer;
            break;
        default:
            break;
    }
}

//INT1 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT1Interrupt( void )
{
  IFS1bits.INT1IF = 0;        //Clear the INT1 interrupt flag or else
  if (0!=cbf_int1_pointer)
  {
    cbf_int1_pointer();
  }
}
//INT2 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT2Interrupt( void )
{
  IFS1bits.INT2IF = 0;        //Clear the INT2 interrupt flag or else
  if (0!=cbf_int2_pointer)
  {
    cbf_int2_pointer();
  }
}
//INT3 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT3Interrupt( void )
{
  IFS3bits.INT3IF = 0;        //Clear the INT3 interrupt flag or 
  if (0!=cbf_int3_pointer)
  {
    cbf_int3_pointer();
  }  
}
//INT4 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT4Interrupt( void )
{
  IFS3bits.INT4IF = 0;        //Clear the INT4 interrupt flag or else
  if (0!=cbf_int4_pointer)
  {
    cbf_int4_pointer();
  }
}
