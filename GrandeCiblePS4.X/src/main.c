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

bool stateBigWheel = false;
uint16_t timeBigWheel = 0;

char xbeeChar = '0';
char lastXbeeChar = '0';

//bool fButton1 = false;
bool fButton2 = false;
bool fButton3 = false;
bool fButton4 = false;

joySpeed_t speed[2] = {0};
joySpeed_t lastSpeed[2] = {0};

/******************************************************************************/
/*                               User functions                               */
/******************************************************************************/
uint8_t CharToUint8(char ch)
{
    if((ch >= '0')&&(ch <= '9'))
    {
        return((uint8_t)(ch - '0'));
    }
    else if((ch >= 'A')&&(ch <= 'F'))
    {
        return(((uint8_t)(ch - 'A')) + 10);
    }
    else
    {
        return 0;
    }
}

joySpeed_t Uint8ToJoySpeed(uint8_t val)
{
    if(val >= N_STEP_JOYSTICK)
    {
        return((joySpeed_t)(val - N_STEP_JOYSTICK));
    }
    else
    {
        return(-((joySpeed_t)(N_STEP_JOYSTICK - val)));
    }
}

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
  // user code
}
//INT2 interrupt
void externalINT2Interrupt( void )
{
  // user code
}
//INT3 interrupt
void externalINT3Interrupt( void )
{
  // user code
}
//INT4 interrupt
void externalINT4Interrupt( void )
{
  // user code
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
    uint8_t uartChar;
    uartChar = uartReadChar(eUART2);
    
    xbeeWriteChar(uartChar);
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
    lastXbeeChar = xbeeChar;
    
    xbeeChar = xbeeReadChar();
    
    uartWriteChar(eUART2, xbeeChar);
    
    switch(xbeeChar)
    {
        case CHAR_PING:
            state = RUN;
            xbeeWriteChar(CHAR_PING_OK);
            break;

        case CHAR_PING_OK:
            state = RUN;
            break;

        case CHAR_BUTTON_1:
            stateBigWheel = true;
            break;

        case CHAR_BUTTON_2:
            fButton2 = true;
            break;

        case CHAR_BUTTON_3:
            fButton3 = true;
            break;

        case CHAR_BUTTON_4:
            fButton4 = true;
            break;

        default:
            switch(lastXbeeChar)
            {
                case CHAR_JOYSTICK_X:
                    speed[eJoyX] = Uint8ToJoySpeed(CharToUint8(xbeeChar));
                    break;

                case CHAR_JOYSTICK_Y:
                    speed[eJoyY] = Uint8ToJoySpeed(CharToUint8(xbeeChar));
                    break;

                default:
                    break;
            }
            break;
    }
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
/*                                User Program                                */
/******************************************************************************/
void mainLoop(void)
{
	// TBD: USER CODE HERE
    static uint16_t sysCounter=0;
    if (100==sysCounter++)
    {
        LATCbits.LATC3 = !LATCbits.LATC3;
               
        switch(state)
        {
            case WAIT_CONNECTION:
            {
                xbeeWriteChar(CHAR_PING);
                break;
            }
            case RUN:
            {
                if(speed[eJoyX] != lastSpeed[eJoyX])
                {
                    if(lastSpeed[eJoyX] == 0)
                    {
                        //setPwmFreq(150, ePWMPrimaryTimeBase);
                        //pwmInit(ePWM1,ePWMPrimaryTimeBase);
                        //setPwmDuty(ePWM1, speed[eJoyX]*1000);
                        //pwmEnable(ePWM1);
                    }
                    else
                    {
                        if(speed[eJoyX] == 0)
                        {
                            //pwmDisable(ePWM2);
                        }
                    }
                }
                if(speed[eJoyY] != lastSpeed[eJoyY])
                {
                    if(lastSpeed[eJoyY] == 0)
                    {
                        //setPwmFreq(5000, ePWMSecondaryTimeBase);
                        //pwmInit(ePWM2,ePWMSecondaryTimeBase);
                        //setPwmDuty(ePWM2, 1000);
                        //pwmEnable(ePWM2);
                    }
                    else
                    {
                        if(speed[eJoyY] == 0)
                        {
                            //pwmDisable(ePWM2);
                        }
                    }
                }
                
                if(stateBigWheel)
                {
                    if(timeBigWheel == 0)
                    {
                        //pwmEnable(ePWMx);
                    }
                    else
                    {
                        if(timeBigWheel == TIME_BIG_WHEEL)
                        {
                            //pwmDisable(ePWMx);
                            stateBigWheel = false;
                        }
                        else
                        {
                            timeBigWheel++;
                        }
                    }
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
    
	// TBD: INITIALIZATION OF THE USER USED MODULE

    //pwmAllInit();
    //pwmInit(ePWM1,ePWMPrimaryTimeBase);
    //setPwmFreq(1000, ePWMPrimaryTimeBase);
    //setPwmPhase(ePWM, 90)
    //setPwmDeadTime(ePWM1, 1);
    //setPwmDuty(ePWM1, 5000); //0 -> 10000 = 0 -> 100%
    
    //adc1Init();
    
    //spiInit(eSPI2, 10, byte8,
    //    TxMode3, RxMiddle,);
    
    uartInit(eUART2, 9600);
    uartInterruptEnable(eUART2, eRX);
    
    xbeeInit(57600);
    xbeeInterruptEnable(eRX);
    
	_GENERAL_INTERRUPT_ENABLED_; // start the interrupt
    
    /*setPwmFreq(150, ePWMPrimaryTimeBase);
    pwmInit(ePWM1,ePWMPrimaryTimeBase);
    setPwmDeadTime(ePWM1, 100);
    setPwmDuty(ePWM1, 2000);
    pwmEnable(ePWM1);*/
    
    setPwmFreq(10, ePWMPrimaryTimeBase);
    pwmStepByStepInit(ePWM1, ePWM2, ePWMPrimaryTimeBase);
    
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
