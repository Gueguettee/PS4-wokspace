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

char speedChar[eNbrOfJoy] = {(JOY1_VALUE+N_STEP_JOY), (JOY2_VALUE+N_STEP_JOY)};

bool flagBigWheel = false;
bool flagMountBigBallUp = false;
bool flagMountBigBallDown = false;
bool fVerin = false;
bool fClapet = false;

/******************************************************************************/
/*                               User functions                               */
/******************************************************************************/
joystick_t SpeedcharToJoystick(char ch)
{
    if((ch <= (JOY1_VALUE + 2*N_STEP_JOY))&&(ch >= JOY1_VALUE))
    {
        return eJoyX;
    }
    else if((ch <= (JOY2_VALUE + 2*N_STEP_JOY))&&(ch >= JOY2_VALUE))
    {
        return eJoyY;
    }
    return eJoyNone;
}

joyspeed_t SpeedcharToJoyspeed(char ch, joystick_t eJoyx)
{
    if(eJoyx == eJoyX)
    {
        return(((joyspeed_t)(ch - JOY1_VALUE)) - N_STEP_JOY);
    }
    else
    {
        return(((joyspeed_t)(ch - JOY2_VALUE)) - N_STEP_JOY);
    }
}

void Uint16ToString(char* hexStr, uint16_t valueInt)
{
    sprintf(hexStr, "%03X", valueInt);
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
    //
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
    //uartWriteChar(eUART2, uartChar);
    
    switch(uartChar)
    {
        case CHAR_PING:
            uartWriteChar(eUART3, CHAR_PING_OK);
            break;
            
        case CHAR_PING_OK:
            break;
            
        /*case CHAR_MOUNT_BIG_BALL:
            stateMountBigBall = false;
            break;
            
        case CHAR_BIG_WHEEL:
            stateBigWheel = false;
            break;*/
            
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
    static xbeeChar;
    xbeeChar = xbeeReadChar();
    //uartWriteChar(eUART2, xbeeChar);  // for debug
    
    switch(xbeeChar)
    {
        case CHAR_PING:
            state = RUN;
            xbeeWriteChar(CHAR_PING_OK);
            break;

        case CHAR_PING_OK:
            state = RUN;
            break;

        case CHAR_BIG_WHEEL:
            flagBigWheel = true;
            break;

        case CHAR_MOUNT_BIG_BALL_UP:
            flagMountBigBallUp = true;
            break;
            
        case CHAR_MOUNT_BIG_BALL_DOWN:
            flagMountBigBallDown = true;
            break;

        case CHAR_VERIN:
            fVerin = true;
            break;

        case CHAR_CLAPET:
            fClapet = true;
            break;

        default:
            joystick_t joy = SpeedcharToJoystick(xbeeChar);
            if(joy != eJoyNone)
            {
                speedChar[joy] = xbeeChar;
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
/*                        PWM Interrupt Routines (IRQ)                        */
/******************************************************************************/
//PWM1 interrupt
void PWM1Interrupt( void )
{
    // user code
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
    joyspeed_t lastSpeed[eNbrOfJoy] = {0};
    
    verinState_t stateVerin = eVerinNotPull;
    bool stateClapet = false;
    
    static uint16_t sysCounter=0;
    static bool firstLoop = true;
    if (SYS_LOOP==sysCounter++)
    {              
        switch(state)
        {
            case WAIT_CONNECTION:
            {
                xbeeWriteChar(CHAR_PING);
                uartWriteChar(eUART3, CHAR_PING);
                break;
            }
            
            case RUN:
            {
                LATCbits.LATC3 = !LATCbits.LATC3;
                
                if(firstLoop)
                {
                    setPwmFreq(DC_FREQ, ePWMPrimaryTimeBase);
                    pwmInit(ePWM1,ePWMPrimaryTimeBase, ePWMModeCompl);
                    pwmInit(ePWM4,ePWMPrimaryTimeBase, ePWMModeCompl);
                    setPwmDuty(ePWM1, 
                        (uint16_t)(5000));
                    setPwmDuty(ePWM4, 
                        (uint16_t)(5000));

                    setPwmFreq(SERVO_FREQ, ePWMSecondaryTimeBase);
                    pwmInit(ePWM2,ePWMSecondaryTimeBase, ePWMModeCompl);
                    pwmInit(ePWM3,ePWMSecondaryTimeBase, ePWMModeCompl);
                    setPwmDuty(ePWM2, SERVO_MIDDLE_DUTY_ON);
                    setPwmDuty(ePWM3, SERVO_MAX_DUTY_ON);
                    pwmEnable(ePWM2);
                    pwmEnable(ePWM3);
                    
                    firstLoop = false;
                }
                
                joyspeed_t tempSpeed[eNbrOfJoy] = 
                    {SpeedcharToJoyspeed(speedChar[eJoyX], eJoyX), 
                    SpeedcharToJoyspeed(speedChar[eJoyY], eJoyY)};
                
                if(tempSpeed[eJoyX] != lastSpeed[eJoyX])
                {
                    if(tempSpeed[eJoyX] == 0)
                    {
                        pwmDisable(ePWM1);
                        pwmDisable(ePWM4);
                    }
                    else if(tempSpeed[eJoyX] > 0)
                    {
                        setPwmDuty(ePWM1, 
                            (uint16_t)(10000/N_STEP_JOY*tempSpeed[eJoyX]));
                        setPwmDuty(ePWM4, 
                            (uint16_t)(10000/N_STEP_JOY*tempSpeed[eJoyX]));
                        pwmEnableSide(ePWM1, ePWMH);
                        pwmEnableSide(ePWM4, ePWMH);
                    }
                    else
                    {
                        setPwmDuty(ePWM1, 
                            (uint16_t)(10000/N_STEP_JOY*(N_STEP_JOY+tempSpeed[eJoyX])));    //'+' car tempSpeed negatif
                        setPwmDuty(ePWM4, 
                            (uint16_t)(10000/N_STEP_JOY*(N_STEP_JOY+tempSpeed[eJoyX])));    //'+' car tempSpeed negatif
                        pwmEnableSide(ePWM1, ePWML);
                        pwmEnableSide(ePWM4, ePWML);
                    }
                    lastSpeed[eJoyX] = tempSpeed[eJoyX];
                }
                
                if(tempSpeed[eJoyY] != lastSpeed[eJoyY])
                {
                    setPwmDuty(ePWM2, 
                        (SERVO_MIDDLE_DUTY_ON + SERVO_GAP_DUTY_ON/N_STEP_JOY*tempSpeed[eJoyY]));
                    lastSpeed[eJoyY] = tempSpeed[eJoyY];
                    
                    if(tempSpeed[eJoyX] == 0)
                    {
                        if(tempSpeed[eJoyY] > 0)
                        {
                            setPwmDuty(ePWM1, 
                                (uint16_t)(10000/N_STEP_JOY*tempSpeed[eJoyY]));
                            pwmEnableSide(ePWM1, ePWMH);
                        }
                        else if(tempSpeed[eJoyY] < 0)
                        {
                            setPwmDuty(ePWM4, 
                                (uint16_t)(10000/N_STEP_JOY*(-tempSpeed[eJoyY])));
                            pwmEnableSide(ePWM4, ePWMH);
                        }
                        else
                        {
                            pwmDisable(ePWM1);
                            pwmDisable(ePWM4);
                        }
                    }
                    else
                    {
                        if(tempSpeed[eJoyX] > 0)
                        {
                            if(tempSpeed[eJoyY] > 0)
                            {
                                setPwmDuty(ePWM1, 
                                    ((10000/N_STEP_JOY*(uint16_t)tempSpeed[eJoyX])+(N_STEP_JOY-(uint16_t)tempSpeed[eJoyX])*10000*(uint16_t)tempSpeed[eJoyY]/N_STEP_JOY));
                            }
                            else
                            {
                                setPwmDuty(ePWM4, 
                                    ((10000/N_STEP_JOY*(uint16_t)tempSpeed[eJoyX])+(N_STEP_JOY-(uint16_t)tempSpeed[eJoyX])*10000*(uint16_t)tempSpeed[eJoyY]/N_STEP_JOY));
                            }
                        }
                        else
                        {
                            if(tempSpeed[eJoyY] > 0)
                            {
                                setPwmDuty(ePWM1, 
                                    ((10000/N_STEP_JOY*(N_STEP_JOY+(uint16_t)tempSpeed[eJoyX]))
                                        +(uint16_t)(-tempSpeed[eJoyX])*10000*(uint16_t)(-tempSpeed[eJoyY])/N_STEP_JOY));
                            }
                            else
                            {
                                setPwmDuty(ePWM4, 
                                    ((10000/N_STEP_JOY*(N_STEP_JOY+(uint16_t)tempSpeed[eJoyX]))
                                        +(uint16_t)(-tempSpeed[eJoyX])*10000*(uint16_t)(-tempSpeed[eJoyY])/N_STEP_JOY));
                            }
                        }
                    }
                }
                
                if(flagMountBigBallUp == true)
                {
                    uartWriteChar(eUART3, CHAR_MOUNT_BIG_BALL_UP);
                    flagMountBigBallUp = false;
                }
                if(flagMountBigBallDown == true)
                {
                    uartWriteChar(eUART3, CHAR_MOUNT_BIG_BALL_DOWN);
                    flagMountBigBallDown = false;
                }
                
                if(flagBigWheel == true)
                {
                    uartWriteChar(eUART3, CHAR_BIG_WHEEL);
                    flagBigWheel = false;
                }
                
                if(fVerin == true)
                {
                    if(stateVerin == eVerinNotPull)
                    {
                        gpioBitConfig(ePORTF, pinRF7, OUTPUT);
                        gpioBitWrite(ePORTF, pinRF7, HIGH);
                        gpioBitConfig(ePORTF, pinRF6, OUTPUT);
                        gpioBitWrite(ePORTF, pinRF6, HIGH);
                        stateVerin = eVerinInTransitionToPull;
                    }
                    else if(stateVerin == eVerinPull)
                    {
                        gpioBitConfig(ePORTF, pinRF7, OUTPUT);
                        gpioBitWrite(ePORTF, pinRF7, LOW);
                        gpioBitConfig(ePORTF, pinRF6, OUTPUT);
                        gpioBitWrite(ePORTF, pinRF6, HIGH);
                        stateVerin = eVerinInTransitionToNotPull;
                    }
                    else if(stateVerin == eVerinInTransitionToNotPull)
                    {
                        gpioBitWrite(ePORTF, pinRF6, LOW);
                        stateVerin = eVerinNotPull;
                    }
                    else    //(stateVerin == eVerinInTransitionToPull)
                    {
                        gpioBitWrite(ePORTF, pinRF6, LOW);
                        stateVerin = eVerinPull;
                    }
                    fVerin = false;
                }
                else if(stateVerin == true)
                {
                    /*if(gpioBitRead(ePORT..., pinR...) == HIGH)
                    {
                        
                    }*/
                }
                
                if(fClapet == true)
                {
                    if(stateClapet == true)
                    {
                        setPwmDuty(ePWM3, SERVO_MAX_DUTY_ON);
                        stateClapet = false;
                    }
                    else
                    {
                        setPwmDuty(ePWM3, SERVO_MIN_DUTY_ON);
                        stateClapet = true;
                    }
                    fClapet = false;
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
  
    //uartInit(eUART2, 9600);
    //uartInterruptEnable(eUART2, eRX);
    uartInit(eUART3, 115200);
    uartInterruptEnable(eUART3, eRX);
    
    xbeeInit(57600);
    xbeeInterruptEnable(eRX);
    
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
