/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/

#include <p33EP512GM710.h>

#include "definition.h"    /* Includes device header and general definition		*/

#include "oscillator.h"		/* Includes oscillator initialization								*/
#include "gpio.h"					/* Includes GPIO functions													*/
#include "timer.h"				/* Includes Timer 2-9 functions and initialization  */
#include "uart.h"				  /* Includes UART functions and initialization				*/
#include "xbee.h"				  /* Includes XBee functions and initialization				*/
#include "adc.h"					/* Includes ADC functions and initialization				*/
#include "sysTick.h"			/* Includes sysTick functions and initialization		*/
#include "pwm.h"					/* Includes PWM functions and initialization				*/

/******************************************************************************/
/*                         Global Variable Declaration                        */
/******************************************************************************/

/******************************************************************************/
/*                                User Program                                */
/******************************************************************************/
void mainLoop1(void)
{
	//USER CODE HERE
    static uint16_t counter=0;
    static dutyCycle=1;
    counter++;
    if (100==counter)
    {
        //LED 1 seconde
        gpioBitWrite(ePORTC, pinRC10, !gpioBitRead(ePORTC, pinRC10));
        counter=0;
    }
    //Test des PWM    
    setPwmDuty(PWM1,dutyCycle);
    setPwmDuty(PWM2,dutyCycle);
    setPwmDuty(PWM3,dutyCycle);
    setPwmDuty(PWM4,dutyCycle);
    setPwmDuty(PWM5,dutyCycle);
    setPwmDuty(PWM6,dutyCycle);
    dutyCycle++;
    if (dutyCycle==100)
    {
        dutyCycle=1;
    }
}


/******************************************************************************/
/*                                Main Program                                */
/******************************************************************************/

int16_t main(void)
{
	/****************************************************************************/
	/*                              INITIALIZATIONS                             */
	/****************************************************************************/
	
	_GENERAL_INTERRUPT_DISABLED_; //stop all interrupt during the initialization
	
	// Init of the oscillator PLL
	oscInit();
	
	// Init of the SysTick
	sysTickInitDflt();
	
	// Init of the GPIO ANSEL register
	gpioInit();
    
	// TBD: INITIALIZATION OF THE USER USED MODULE
    gpioBitConfig(ePORTC, pinRC10, OUTPUT);
    gpioBitConfig(ePORTC, pinRC3, OUTPUT);
    
    gpioBitWrite(ePORTC, pinRC3, !gpioBitRead(ePORTC, pinRC3));
    
    // Init of the PWM1
	pwmAllInit();

	_GENERAL_INTERRUPT_ENABLED_; // start the interrupt 
    
	/****************************************************************************/
	/*                               INFINITE LOOP                              */
	/****************************************************************************/
	uint16_t counter=0;
    while(1)
	{
		if(1 == sysTickFlag)
		{
            counter++;
            if (10==counter)
            {
                mainLoop1();
                counter=0;
			}
            // Reset sysTickFlag
			sysTickFlag = 0;
            ClrWdt(); // reset the watch dog counter to 0
		}
	}
}

/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//INT0 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT0Interrupt( void )
{
  IFS0bits.INT0IF = 0;        //Clear the INT0 interrupt flag or else
}
//INT1 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT1Interrupt( void )
{
  IFS1bits.INT1IF = 0;        //Clear the INT1 interrupt flag or else
}
//INT2 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT2Interrupt( void )
{
   IFS1bits.INT2IF = 0;        //Clear the INT2 interrupt flag or else
}
//INT3 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT3Interrupt( void )
{
  IFS3bits.INT3IF = 0;        //Clear the INT3 interrupt flag or else
}
//INT4 interrupt
/// @private
void __attribute__ ( (interrupt, no_auto_psv) ) _INT4Interrupt( void )
{
  IFS3bits.INT4IF = 0;        //Clear the INT4 interrupt flag or else
}

/******************************************************************************/
/*                       Timer Interrupt Routines (IRQ)                       */
/******************************************************************************/
// Timer2 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T2Interrupt(void)
{
	IFS0bits.T2IF = 0;            // Clear Timer 2 interrupt flag
}
// Timer4 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T4Interrupt(void)
{
	IFS1bits.T4IF = 0;            // Clear Timer 4 interrupt flag
}
// Timer5 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T5Interrupt(void)
{
	IFS1bits.T5IF = 0;            // Clear Timer 5 interrupt flag
}
// Timer6 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T6Interrupt(void)
{
	IFS2bits.T6IF = 0;            // Clear Timer 6 interrupt flagg
}
// Timer7 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T7Interrupt(void)
{
	IFS3bits.T7IF = 0;            // Clear Timer 7 interrupt flag
}
// Timer8 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T8Interrupt(void)
{
	IFS3bits.T8IF = 0;            // Clear Timer 8 interrupt flag
}
// Timer9 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T9Interrupt(void)
{
	IFS3bits.T9IF = 0;            // Clear Timer 9 interrupt flag
}

/******************************************************************************/
/*                        UART Interrupt Routines (IRQ)                       */
/******************************************************************************/
//UART2 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U2TXInterrupt(void)
{
	IFS1bits.U2TXIF = 0;    // Clear the Transmit Interrupt Flag
}
// UART2 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U2RXInterrupt(void)
{
	IFS1bits.U2RXIF = 0;    // Clear the Transmit Interrupt Flag
}
//UART3 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U3TXInterrupt(void)
{
	IFS5bits.U3TXIF = 0;    // Clear the Transmit Interrupt Flag
}
//UART3 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U3RXInterrupt(void)
{
	IFS5bits.U3RXIF = 0;    // Clear the Transmit Interrupt Flag
}

/******************************************************************************/
/*                        XBee Interrupt Routines (IRQ)                       */
/******************************************************************************/
//UART4 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U4TXInterrupt(void)
{
	IFS5bits.U4TXIF = 0;    // Clear the Transmit Interrupt Flag
}

//UART4 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U4RXInterrupt(void)
{
	IFS5bits.U4RXIF = 0;    // Clear the Transmit Interrupt Flag
}
