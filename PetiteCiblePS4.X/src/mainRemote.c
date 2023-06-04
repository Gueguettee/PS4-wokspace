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

#include "comDefinition.h" /* Includes commons definition beetween 2 CiblePS4 */

/******************************************************************************/
/*                         Global Variable Declaration                        */
/******************************************************************************/

const analog_t AN_JOYSTICK[eNbrOfJoy] = {AN2, AN1};

char state = RUN;   //////////////////////////

joySpeed_t middleJoyValue[eNbrOfJoy] = {0};
joySpeed_t stepPos[eNbrOfJoy] = {0};
joySpeed_t stepNeg[eNbrOfJoy] = {0};

bool f1 = false;
bool f2 = false;
bool f3 = false;
bool f4 = false;

/******************************************************************************/
/*                               User functions                               */
/******************************************************************************/
/*void Uint16ToString(char* hexStr, uint16_t valueInt)
{
    sprintf(hexStr, "%03X", valueInt);
}*/

char SpeedToChar(uint16_t valueInt, joystick_t joystick)
{
    if(joystick == eJoyX)
    {
        return((char)valueInt); //(valueInt + '0')
    }
    else
    {
        return((char)((0x30) + (char)valueInt)); //(valueInt-10) + 'A')
    }
}

void JoystickInit(void)
{
    middleJoyValue[eJoyX] = adcChannelRead(AN_JOYSTICK[eJoyX]);
    middleJoyValue[eJoyY] = adcChannelRead(AN_JOYSTICK[eJoyY]);
    
    stepPos[eJoyX] = (MAX_VALUE_JOY-middleJoyValue[eJoyX])/(N_STEP_JOY+2);
    stepNeg[eJoyX] = (middleJoyValue[eJoyX]-MIN_VALUE_JOY)/(N_STEP_JOY+2);
    stepPos[eJoyY] = (MAX_VALUE_JOY-middleJoyValue[eJoyY])/(N_STEP_JOY+2);
    stepNeg[eJoyY] = (middleJoyValue[eJoyY]-MIN_VALUE_JOY)/(N_STEP_JOY+2);
}
    
char JoystickToSpeedChar(joystick_t joystick)
{   
    joySpeed_t value = adcChannelRead(AN_JOYSTICK[joystick]);
    joySpeed_t step = 0;
    
    if(value >= middleJoyValue[joystick])
    {
        for(step=N_STEP_JOY; step>0; step--)
        {
            if(value >= (middleJoyValue[joystick]+(step+1)*stepPos[joystick]))
            {
                return(SpeedToChar(N_STEP_JOY+step, joystick));
            }
        }
        return(SpeedToChar(N_STEP_JOY, joystick));
    }
    else
    {
        for(step=N_STEP_JOY; step>0; step--)
        {
            if(value <= (middleJoyValue[joystick]-(step+1)*stepNeg[joystick]))
            {
                return(SpeedToChar(N_STEP_JOY-step, joystick));
            }
        }
        return(SpeedToChar(N_STEP_JOY, joystick));
    }
}

/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//INT1 interrupt
void externalINT1Interrupt( void )
{
    f1 = true;
}
//INT2 interrupt
void externalINT2Interrupt( void )
{
    f2 = true;
}
//INT3 interrupt
void externalINT3Interrupt( void )
{
    f3 = true;
}
//INT4 interrupt
void externalINT4Interrupt( void )
{
    f4 = true;
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
    char xbeeChar;
    xbeeChar = xbeeReadChar();
    
    switch(xbeeChar)
    {
        case CHAR_PING:
            state = RUN;
            xbeeWriteChar(CHAR_PING_OK);
            break;
            
        case CHAR_PING_OK:
            state = RUN;
            break;
            
        default:
            xbeeWriteChar(xbeeChar);
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
void mainLoop(void)
{
	// TBD: USER CODE HERE
    static bool firstLoop = true;
    static uint16_t sysCounter = 0;
    static char lastJoySpeed[2] = {0};
    static bool ff1 = false;
    static bool ff2 = false;
    static bool ff3 = false;
    static bool ff4 = false;
    static bool ff[2] = {false, false};
    
    if (SYS_LOOP==sysCounter++)
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
                if(firstLoop)
                {
                    JoystickInit(); //obligatoire tester plusieurs fois
                    lastJoySpeed[eJoyX] = JoystickToSpeedChar(eJoyX);
                    lastJoySpeed[eJoyY] = JoystickToSpeedChar(eJoyY);
                    firstLoop = false;
                }
                char speed[2] = 
                    {JoystickToSpeedChar(eJoyX),
                    JoystickToSpeedChar(eJoyY)};

                if((speed[eJoyX] != lastJoySpeed[eJoyX])
                    && (ff[eJoyX] == false))
                {
                    xbeeWriteChar(speed[eJoyX]);
                    lastJoySpeed[eJoyX] = speed[eJoyX];
                    ff[eJoyX] = true;
                }
                else if((speed[eJoyY] != lastJoySpeed[eJoyY]) 
                    && (ff[eJoyY] == false))
                {
                    xbeeWriteChar(speed[eJoyY]);
                    lastJoySpeed[eJoyY] = speed[eJoyY];
                    ff[eJoyY] = true;
                }               
                else
                {
                    if((f1 == true) && (ff1 == false))
                    {
                        xbeeWriteChar(CHAR_MOUNT_BIG_BALL);
                        ff1 = true;
                    }
                    else if((f2 == true) && (ff2 == false))
                    {
                        xbeeWriteChar(CHAR_BIG_WHEEL);
                        ff2 = true;
                    }
                    else if((f3 == true) && (ff3 == false))
                    {
                        xbeeWriteChar(CHAR_BUTTON_4);
                        ff3 = true;
                    }
                    else if((f4 == true) && (ff4 == false))
                    {
                        xbeeWriteChar(CHAR_VERIN);
                        ff4 = true;
                    }
                    else
                    {
                        if(ff[eJoyX] == true)
                        {
                            ff[eJoyX] = false;
                        }
                        else if(ff[eJoyY] == true)
                        {
                            ff[eJoyY] = false;
                        }
                        else if(ff1 == true)
                        {
                            if(gpioBitRead(ePORTB, pinRB14) == 0)
                            {
                                ff1 = false;
                                f1 = false;
                            }
                        }
                        else if(ff2 == true)
                        {
                            if(gpioBitRead(ePORTA, pinRA12) == 0)
                            {
                                ff2 = false;
                                f2 = false;
                            }
                        }
                        else if(ff3 == true)
                        {
                            if(gpioBitRead(ePORTA, pinRA14) == 0)
                            {
                                ff3 = false;
                                f3 = false;
                            }
                        }
                        else if(ff4 == true)
                        {
                            if(gpioBitRead(ePORTA, pinRA15) == 0)
                            {
                                ff4 = false;
                                f4 = false;
                            }
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
    /**************************************************************************/
	/*                             INITIALIZATIONS                            */
	/**************************************************************************/
    
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
            
    
	/* TBD: INITIALIZATION OF THE USER USED MODULE */
    
    adc1Init();

    xbeeInit(57600);
    xbeeInterruptEnable(eRX);
    
    externInterruptInit(eINT1, eRisingEdge);
    externInterruptInit(eINT2, eRisingEdge);
    externInterruptInit(eINT3, eRisingEdge);
    externInterruptInit(eINT4, eRisingEdge);
    
	_GENERAL_INTERRUPT_ENABLED_; // start the interrupt
    
	/**************************************************************************/
	/*                              INFINITE LOOP                             */
	/**************************************************************************/
    
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
    return 0;
}