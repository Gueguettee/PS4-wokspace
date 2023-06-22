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
#include "i2c.h"        /* Includes I2C functions and initialization          */
#include "adc.h"        /* Includes ADC functions and initialization          */
#include "sysTick.h"    /* Includes sysTick functions and initialization      */
#include "pwm.h"        /* Includes PWM functions and initialization          */
#include "can.h"        /* Includes CAN functions and initialization          */
#include "rtc.h"        /* Includes RTC functions and initialization          */

#include "comDefinition.h" /* Includes commons definition beetween 2 CiblePS4 */

/******************************************************************************/
/*                         Global Variable Declaration                        */
/******************************************************************************/
char state = WAIT_CONNECTION;

bool flagBigWheel = false;
bool stateBigWheel = false;
bool dirBigWheel = false;
bool flagMountBigBallUp = false;
bool flagMountBigBallDown = false;
bool flagVerinUp = false;
bool flagVerinDown = false;
bool stateVerin = false;
bool dirVerin = false;
bool stateMountBigBall = false;
bool dirMountBigBall = false;

//uint16_t timeMountBigBall = 0;

/******************************************************************************/
/*                               User functions                               */
/******************************************************************************/


/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//INT0 interrupt
void externalINT0Interrupt( void )
{
  // user code
}
//INT1 interrupt
void externalINT1Interrupt( void )
{
    
}
//INT2 interrupt
void externalINT2Interrupt( void )
{
    setPwmFreq(BIG_WHEEL_FREQ_DOWN, ePWMPrimaryTimeBase);
    pwmStepByStepSetDirection(ePWM1, ePWM2, ePWMDown);
    pwmStepByStepEnable(ePWM1, ePWM2);
    //pwmStepByStepInit(ePWM1, ePWM2, RAIL_FREQ, ePWMPrimaryTimeBase, ePWMDown);
    dirBigWheel = false;
    stateBigWheel = true;
}
//INT3 interrupt
void externalINT3Interrupt( void )
{
    pwmStepByStepDisable(ePWM1, ePWM2);
    stateBigWheel = false;
}
//INT4 interrupt
void externalINT4Interrupt( void )
{
    /*setPwmFreq(MOUNT_BIG_BALL_FREQ, ePWMSecondaryTimeBase);
    pwmStepByStepSetDirection(ePWM3, ePWM4, ePWMUp);
    pwmStepByStepEnable(ePWM3, ePWM4);
    dirMountBigBall = true;
    //pwmStepByStepInit(ePWM3, ePWM4, 30, ePWMSecondaryTimeBase, ePWMUp);
    stateMountBigBall = true;*/
    pwmStepByStepDisable(ePWM3, ePWM4);
    stateMountBigBall = false;
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
#ifdef ML180V3
//UART1 RX interrupt
void uart1RXInterrupt( void )
{
  // user code
}
//UART1 TX interrupt
void uart1TXInterrupt( void )
{
  // user code
}
#endif
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
    char uartChar;
    uartChar = uartReadChar(eUART3);
    
    switch(uartChar)
    {
        case CHAR_PING:
            state = RUN;
            uartWriteChar(eUART3, CHAR_PING_OK);
            break;
            
        case CHAR_PING_OK:
            state = RUN;
            break;
            
        case CHAR_MOUNT_BIG_BALL_UP:
            flagMountBigBallUp = true;
            break;
            
        case CHAR_MOUNT_BIG_BALL_DOWN:
            flagMountBigBallDown = true;
            break;
            
        case CHAR_BIG_WHEEL:
            flagBigWheel = true;
            break;
            
        case CHAR_VERIN_UP:
            flagVerinUp = true;
            break;
            
        case CHAR_VERIN_DOWN:
            flagVerinDown = true;
            break;
           
        default:
            break;
    }
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
#ifdef ML180V3
//SPI2 interrupt
void spi2Interrupt( void )
{
  // user code
}
#endif
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
/*                        CAN Interrupt Routines (IRQ)                        */
/******************************************************************************/
//CAN1 interrupt
void can1Interrupt( void )
{
  // user code
}
//CAN2 interrupt
void can2Interrupt( void )
{
  // user code
}

/******************************************************************************/
/*                        RTC Interrupt Routines (IRQ)                        */
/******************************************************************************/
//RTC interrupt
void rtcInterrupt( void )
{
    // user code
}

/******************************************************************************/
/*                        PWM Interrupt Routines (IRQ)                        */
/******************************************************************************/
//PWM1 interrupt
void PWM1Interrupt( void )
{
    /*if(timeMountBigBall == TIME_MOUNT_BIG_BALL)
    {
        //pwmStepByStepDisable(ePWM1, ePWM2);
        //uartWriteChar(eUART3, CHAR_MOUNT_BIG_BALL);
        //timeMountBigBall = 0;
        stateMountBigBall = false;
    }
    else
    {
        timeMountBigBall++;
    }*/
}
//PWM2 interrupt
void PWM2Interrupt( void )
{
  // user code
}
//PWM3 interrupt
void PWM3Interrupt( void )
{
  // user code
}
//PWM4 interrupt
void PWM4Interrupt( void )
{
  // user code
}
//PWM5 interrupt
void PWM5Interrupt( void )
{
  // user code
}
//PWM6 interrupt
void PWM6Interrupt( void )
{
  // user code
}

/******************************************************************************/
/*                                User Program                                */
/******************************************************************************/
void mainLoop(void)
{
	// TBD: USER CODE HERE
    static uint16_t sysCounter=0;
    static bool firstLoop = true;
    
    if (SYS_LOOP==sysCounter++)
    {             
        switch(state)
        {
            case WAIT_CONNECTION:
            {
                uartWriteChar(eUART3, CHAR_PING);
                break;
            }
            case RUN:
            {
                LATCbits.LATC3 = !LATCbits.LATC3;
                
                if(firstLoop == true)
                {
                    pwmStepByStepInit(ePWM1, ePWM2, BIG_WHEEL_FREQ_UP, ePWMPrimaryTimeBase, ePWMUp);
                    pwmStepByStepInit(ePWM3, ePWM4, MOUNT_BIG_BALL_FREQ, ePWMSecondaryTimeBase, ePWMUp);
                    pwmStepByStepInit(ePWM5, ePWM6, VERIN_FREQ, ePWMPrimaryTimeBase, ePWMUp);
                    
                    firstLoop = false;
                }
                
                if(flagBigWheel==true)
                {
                    if(stateBigWheel==true)
                    {
                        if(dirBigWheel==false)
                        {
                            pwmStepByStepDisable(ePWM1, ePWM2);
                            stateBigWheel = false;
                        }
                        else
                        {
                            pwmStepByStepDisable(ePWM1, ePWM2);
                            setPwmFreq(BIG_WHEEL_FREQ_DOWN, ePWMPrimaryTimeBase);
                            pwmStepByStepSetDirection(ePWM1, ePWM2, ePWMDown);
                            pwmStepByStepEnable(ePWM1, ePWM2);
                            //pwmStepByStepInit(ePWM1, ePWM2, RAIL_FREQ, ePWMPrimaryTimeBase, ePWMDown);
                            dirBigWheel = false;
                        }
                    }
                    else
                    {
                        pwmStepByStepDisable(ePWM1, ePWM2);
                        setPwmFreq(BIG_WHEEL_FREQ_UP, ePWMPrimaryTimeBase);
                        pwmStepByStepSetDirection(ePWM1, ePWM2, ePWMUp);
                        pwmStepByStepEnable(ePWM1, ePWM2);
                        //pwmStepByStepInit(ePWM1, ePWM2, RAIL_FREQ, ePWMPrimaryTimeBase, ePWMUp);
                        stateBigWheel = true;
                        dirBigWheel = true;
                    }
                    flagBigWheel = false;
                }
                else if(stateBigWheel==true)
                {
                    if((gpioBitRead(ePORTA, pinRA12) == LOW)&&(dirBigWheel == true))
                    {
                        pwmStepByStepDisable(ePWM1, ePWM2);
                        setPwmFreq(BIG_WHEEL_FREQ_DOWN, ePWMPrimaryTimeBase);
                        pwmStepByStepSetDirection(ePWM1, ePWM2, ePWMDown);
                        pwmStepByStepEnable(ePWM1, ePWM2);
                        //pwmStepByStepInit(ePWM1, ePWM2, RAIL_FREQ, ePWMPrimaryTimeBase, ePWMDown);
                        dirBigWheel = false;
                        stateBigWheel = true;
                    }
                    else if((gpioBitRead(ePORTA, pinRA14) == LOW)&&(dirBigWheel == false))
                    {
                        pwmStepByStepDisable(ePWM1, ePWM2);
                        stateBigWheel = false;
                    }
                }
                
                if(flagMountBigBallDown==true)
                {
                    if((stateMountBigBall==true)&&(dirMountBigBall == false))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateMountBigBall = false;
                    }
                    else
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        setPwmFreq(MOUNT_BIG_BALL_FREQ, ePWMSecondaryTimeBase);
                        pwmStepByStepSetDirection(ePWM3, ePWM4, ePWMDown);
                        pwmStepByStepEnable(ePWM3, ePWM4);
                        dirMountBigBall = false;
                        //pwmStepByStepInit(ePWM3, ePWM4, 30, ePWMSecondaryTimeBase, ePWMUp);
                        stateMountBigBall = true;
                    }
                    flagMountBigBallDown = false;
                }
                else if(flagMountBigBallUp==true)
                {
                    if((stateMountBigBall==true)&&(dirMountBigBall == true))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateMountBigBall = false;
                    }
                    else
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        setPwmFreq(MOUNT_BIG_BALL_FREQ, ePWMSecondaryTimeBase);
                        pwmStepByStepSetDirection(ePWM3, ePWM4, ePWMUp);
                        pwmStepByStepEnable(ePWM3, ePWM4);
                        dirMountBigBall = true;
                        //pwmStepByStepInit(ePWM3, ePWM4, 30, ePWMSecondaryTimeBase, ePWMUp);
                        stateMountBigBall = true;
                    }
                    flagMountBigBallUp = false;
                }
                else if(stateMountBigBall==true)
                {
                    if((gpioBitRead(ePORTE, pinRE8) == LOW)&&(dirMountBigBall == true))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateMountBigBall = false;
                    }
                    else if((gpioBitRead(ePORTE, pinRE9) == LOW)&&(dirMountBigBall == false))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateMountBigBall = false;
                    }
                }
                
                if(flagVerinDown==true)
                {
                    if((stateVerin==true)&&(dirVerin == false))
                    {
                        pwmStepByStepDisable(ePWM5, ePWM6);
                        stateVerin = false;
                    }
                    else
                    {
                        pwmStepByStepDisable(ePWM5, ePWM6);
                        setPwmFreq(VERIN_FREQ, ePWMPrimaryTimeBase);
                        pwmStepByStepSetDirection(ePWM5, ePWM6, ePWMDown);
                        pwmStepByStepEnable(ePWM5, ePWM6);
                        dirVerin = false;
                        stateVerin = true;
                    }
                    flagVerinDown = false;
                }
                else if(flagVerinUp==true)
                {
                    if((stateVerin==true)&&(dirVerin == true))
                    {
                        pwmStepByStepDisable(ePWM5, ePWM6);
                        stateVerin = false;
                    }
                    else
                    {
                        pwmStepByStepDisable(ePWM5, ePWM6);
                        setPwmFreq(VERIN_FREQ, ePWMPrimaryTimeBase);
                        pwmStepByStepSetDirection(ePWM5, ePWM6, ePWMUp);
                        pwmStepByStepEnable(ePWM5, ePWM6);
                        dirVerin = true;
                        stateVerin = true;
                    }
                    flagVerinUp = false;
                }
                else if(stateVerin==true)
                {
                    /*if((gpioBitRead(ePORTE, pinRE8) == LOW)&&(dirMountBigBall == true))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateVerin = false;
                    }
                    else if((gpioBitRead(ePORTE, pinRE9) == LOW)&&(dirMountBigBall == false))
                    {
                        pwmStepByStepDisable(ePWM3, ePWM4);
                        stateVerin = false;
                    }*/
                }
                
                break;
            }
            default:
            {
                break;
            }
        }
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
    //External
    registerExternCallback(eINT0, externalINT0Interrupt);
    registerExternCallback(eINT1, externalINT1Interrupt);
    registerExternCallback(eINT2, externalINT2Interrupt);
    registerExternCallback(eINT3, externalINT3Interrupt);
    registerExternCallback(eINT4, externalINT4Interrupt);   
    //Timer
    registerTimerCallback(eTimer4, timer4Interrupt);
    registerTimerCallback(eTimer5, timer5Interrupt);
    registerTimerCallback(eTimer6, timer6Interrupt);
    registerTimerCallback(eTimer7, timer7Interrupt);
    //ADC1
    registerADC1Callback(adc1Interrupt);
    //UART
#ifdef ML180V3
    registerUARTxCallback(eUART1, eRX, uart1RXInterrupt);
    registerUARTxCallback(eUART1, eTX, uart1TXInterrupt);
#endif
    registerUARTxCallback(eUART2, eRX, uart2RXInterrupt);
    registerUARTxCallback(eUART2, eTX, uart2TXInterrupt);
    registerUARTxCallback(eUART3, eRX, uart3RXInterrupt);
    registerUARTxCallback(eUART3, eTX, uart3TXInterrupt);
    //XBee
    registerXbeeCallback(eRX, xbeeRXInterrupt);
    registerXbeeCallback(eTX, xbeeTXInterrupt);
    //SPI3
#ifdef ML180V3
    registerSPIxCallback(eSPI2, spi2Interrupt);
#endif
    registerSPIxCallback(eSPI3, spi3Interrupt);
    //I2C
    registerI2CxCallback(eI2C1, i2c1Interrupt);
    registerI2CxCallback(eI2C2, i2c2Interrupt);
    //CAN
    registerCANxCallback(eCAN1, can1Interrupt);
    registerCANxCallback(eCAN2, can2Interrupt);
    //RTC
    registerRTCCallback(rtcInterrupt);
    //PWM
    registerPWMCallback(ePWM1, PWM1Interrupt);
    registerPWMCallback(ePWM2, PWM2Interrupt);
    registerPWMCallback(ePWM3, PWM3Interrupt);
    registerPWMCallback(ePWM4, PWM4Interrupt);
    registerPWMCallback(ePWM5, PWM5Interrupt);
    registerPWMCallback(ePWM6, PWM6Interrupt);
    
	// TBD: INITIALIZATION OF THE USER USED MODULE
    
    uartInit(eUART3, 115200);
    uartInterruptEnable(eUART3, eRX);
    
    //externInterruptInit(eINT2, eFallingEdge);
    //externInterruptInit(eINT3, eFallingEdge);
    //externInterruptInit(eINT4, eFallingEdge);

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
