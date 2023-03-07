/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/

#include "definition.h" /* Includes device header and general definition      */

#include "clock.h"      /* Includes oscillator initialization                 */
#include "gpio.h"       /* Includes GPIO functions                            */
#include "timer.h"      /* Includes Timer 2-9 functions and initialization    */
#include "uart.h"       /* Includes UART functions and initialization         */
#include "xbee.h"       /* Includes XBee functions and initialization         */
#include "spi.h"        /* Includes SPI functions and initialization          */
#include "i2c.h"        /* Includes SPI functions and initialization          */
#include "adc.h"        /* Includes ADC functions and initialization          */
#include "sysTick.h"    /* Includes sysTick functions and initialization      */
#include "pwm.h"        /* Includes PWM functions and initialization          */

/******************************************************************************/
/*                         Global Variable Declaration                        */
/******************************************************************************/


/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//INT1 interrupt
void externalINT1Interrupt( void )
{
    xbeeWriteChar('1');
}
//INT2 interrupt
void externalINT2Interrupt( void )
{
    xbeeWriteChar('2');
}
//INT3 interrupt
void externalINT3Interrupt( void )
{
    xbeeWriteChar('3');
}
//INT4 interrupt
void externalINT4Interrupt( void )
{
    xbeeWriteChar('4');
}

/******************************************************************************/
/*                       Timer Interrupt Routines (IRQ)                       */
/******************************************************************************/
//Timer4 interrupt
void timer4Interrupt( void )
{
  // user code
}
//Timer5 interrupt
void timer5Interrupt( void )
{
  // user code
}
//Timer6 interrupt
void timer6Interrupt( void )
{
  // user code
}
//Timer7 interrupt
void timer7Interrupt( void )
{
  // user code
}

/******************************************************************************/
/*                        ADC Interrupt Routines (IRQ)                        */
/******************************************************************************/
//ADC1 interrupt
void adc1Interrupt( void )
{
    //user code
}

/******************************************************************************/
/*                        UART Interrupt Routines (IRQ)                       */
/******************************************************************************/
//UART2 RX interrupt
void uart2RXInterrupt( void )
{
    // user code
}
//UART2 TX interrupt
void uart2TXInterrupt( void )
{
  // user code
}
//UART3 RX interrupt
void uart3RXInterrupt( void )
{
  // user code
}
//UART3 TX interrupt
void uart3TXInterrupt( void )
{
  // user code
}

/******************************************************************************/
/*                        XBee Interrupt Routines (IRQ)                       */
/******************************************************************************/
//XBee RX interrupt
void xbeeRXInterrupt( void )
{
  // user code
}
//XBee TX interrupt
void xbeeTXInterrupt( void )
{
  // user code
}

/******************************************************************************/
/*                        SPI Interrupt Routines (IRQ)                        */
/******************************************************************************/
//SPI3 interrupt
void spi3Interrupt( void )
{
  // user code
}

/******************************************************************************/
/*                        I2C Interrupt Routines (IRQ)                        */
/******************************************************************************/
//I2C1 interrupt
void i2c1Interrupt( void )
{
  // user code
}
//I2C2 interrupt
void i2c2Interrupt( void )
{
  // user code
}

/******************************************************************************/
/*                                User Program                                */
/******************************************************************************/
void Uint16ToString(char* hexStr, uint16_t valueInt)
{
    sprintf(hexStr, "%04X", valueInt);
}

void mainLoop(void)
{
	// TBD: USER CODE HERE
    static uint16_t sysCounter=0;
    if (100==sysCounter++)
    {
        LATCbits.LATC3 = !LATCbits.LATC3;
        
        uint16_t value = adcChannelRead(AN3);
        
        //char* hexStr = (char *)malloc(5); // 4 hex digits + '\0'
        char hexStr[5];
        Uint16ToString(hexStr,value);
        value=0;
        xbeeWriteString(hexStr);
        
        sysCounter=0;
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
    
	_GENERAL_INTERRUPT_DISABLED_;   // Stop all interrupt during the initialization
    
    /* From Errata #33 or/and #25 combination(s): => to avoid IRQ losses during DO loop
     * Seems to get the problems on SPI3 _SS3 (returning to 0, getting if (_SS3 == 0)
     * condition => infinite loop) when SPI3 and timerAllInit() function are used
     */
    INTCON1bits.NSTDIS = 1;         // Interrupt nesting is disabled
	
	// Init of the oscillator PLL for the clock system
	clkInit();
	
	// Init of the SysTick
	sysTickInitDflt();
	
	// Init of the GPIO registers
	gpioInit();
    
    // Callback register for all interrupts
    // External interrupts
    registerExternCallback(eINT1, externalINT1Interrupt);
    registerExternCallback(eINT2, externalINT2Interrupt);
    registerExternCallback(eINT3, externalINT3Interrupt);
    registerExternCallback(eINT4, externalINT4Interrupt);   
    // Timer
    registerTimerCallback(eTimer4, timer4Interrupt);
    registerTimerCallback(eTimer5, timer5Interrupt);
    registerTimerCallback(eTimer6, timer6Interrupt);
    registerTimerCallback(eTimer7, timer7Interrupt);
    // ADC1
    registerADC1Callback(adc1Interrupt);
    // UART
    registerUARTxCallback(eUART2, eRX, uart2RXInterrupt);
    registerUARTxCallback(eUART2, eTX, uart2TXInterrupt);
    registerUARTxCallback(eUART3, eRX, uart3RXInterrupt);
    registerUARTxCallback(eUART3, eTX, uart3TXInterrupt);
    // XBee
    registerXbeeCallback(eRX, xbeeRXInterrupt);
    registerXbeeCallback(eTX, xbeeTXInterrupt);
    // SPI3
    registerSPI3Callback(spi3Interrupt);
    // I2C
    registerI2CxCallback(eI2C2, i2c2Interrupt);
            
	// TBD: INITIALIZATION OF THE USER USED MODULE
    
    uartInit(eUART2, 9600);
    uartInterruptEnable(eUART2, eRX);
    
    adc1Init(); // number of 1us, 12 bits or 10 bits
    
    pwmAllInit();
    
    //gpioInit();
    externInterruptInit(eINT1, eRisingEdge);
    externInterruptEnable(eINT1);

    xbeeInit(57600);
    //xbeeInterruptEnable(eTX);
    
	_GENERAL_INTERRUPT_ENABLED_; // start the interrupt
    
	/****************************************************************************/
	/*                               INFINITE LOOP                              */
	/****************************************************************************/
	while(1)
	{
		if(1 == sysTickFlag)
		{
			mainLoop();
			// Reset sysTickFlag
			sysTickFlag = 0;
            ClrWdt(); // reset the watch dog counter to 0
		}
	}
}