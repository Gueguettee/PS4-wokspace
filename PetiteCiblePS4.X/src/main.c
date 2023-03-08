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

char state = WAIT_CONNECTION_ROBOT;

uint16_t middleValue = 0;
uint16_t stepPos = 0;
uint16_t stepNeg = 0;

/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
//INT1 interrupt
void externalINT1Interrupt( void )
{
    xbeeWriteChar(CHAR_BUTTON_1);
}
//INT2 interrupt
void externalINT2Interrupt( void )
{
    xbeeWriteChar(CHAR_BUTTON_2);
}
//INT3 interrupt
void externalINT3Interrupt( void )
{
    xbeeWriteChar(CHAR_BUTTON_3);
}
//INT4 interrupt
void externalINT4Interrupt( void )
{
    xbeeWriteChar(CHAR_BUTTON_4);
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
    
    if(xbeeChar == CHAR_ROBOT)
    {
        state = RUN;
    }
    
    xbeeWriteChar(xbeeChar);
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

void stepJoystickSend(void)
{
    xbeeWriteChar(CHAR_JOYSTICK_STEP);
    xbeeWriteChar(N_STEP_JOYSTICK);
}

bool joysitckInit(analog_t ANx, port_t ePORTx, uint16_t BIT)
{
    bool check = true;
    uint16_t maxValue = 0x0FFF;
    uint16_t minValue = 0x0000;
    middleValue = (maxValue+minValue)/2;
    
    if(gpioBitConfig(ePORTx, BIT, OUTPUT))
    {
        if(gpioBitWrite(ePORTx, BIT, 0))
        {
            __delay_ms(100);
            minValue = adcChannelRead(ANx);
            if(minValue >= middleValue)
            {
                minValue = 0x0000;
                check = false;
            }
            if(gpioBitWrite(ePORTx, BIT, 1))
            {
                __delay_ms(100);
                maxValue = adcChannelRead(ANx);
                if(maxValue <= middleValue)
                {
                    maxValue = 0x0FFF;
                    check = false;
                }
                if(gpioBitConfig(ePORTx, BIT, INPUT))
                {
                    __delay_ms(100);
                    middleValue = adcChannelRead(ANx);
                    if((middleValue>=maxValue)||(middleValue<=minValue))
                    {
                        middleValue = (maxValue+minValue)/2;
                        check = false;
                    }
                }
                else
                {
                    check = false;
                }
            }
            else
            {
                check = false;
            }
        }
        else
        {
            check = false;
        }
    }
    else
    {
        check = false;
    }
    
    stepPos = (maxValue-middleValue)/(N_STEP_JOYSTICK+1);
    stepNeg = (middleValue-minValue)/(N_STEP_JOYSTICK+1);
    
    return check;
}
    
char joystickToSpeed(uint16_t value)
{   
    if(value >= middleValue)
    {
        for(uint16_t step=N_STEP_JOYSTICK; step>0; step--)
        {
            if(value >= (middleValue+step*stepPos))
            {
                return ((N_STEP_JOYSTICK+step) + '0');
            }
        }
        return N_STEP_JOYSTICK;
    }
    else
    {
        for(uint16_t step=N_STEP_JOYSTICK; step>0; step--)
        {
            if(value <= (middleValue-step*stepNeg))
            {
                return ((N_STEP_JOYSTICK-step) + '0');
            }
        }
        return N_STEP_JOYSTICK;
    }
}

void Uint16ToString(char* hexStr, uint16_t valueInt)
{
    sprintf(hexStr, "%03X", valueInt);
}

void mainLoop(void)
{
	// TBD: USER CODE HERE
    static uint16_t sysCounter = 0;
    
    if (100==sysCounter++)
    {
        LATCbits.LATC3 = !LATCbits.LATC3;
        
        switch(state)
        {
            case WAIT_CONNECTION_ROBOT:
                
                stepJoystickSend();
                
                break;
                
            case RUN:
                //uint16_t value = adcChannelRead(AN3);  
                //char hexStr[4];
                //Uint16ToString(hexStr,value);
                //value=0;
                //xbeeWriteString(hexStr);

                xbeeWriteChar(CHAR_JOYSTICK_X);
                xbeeWriteChar(joystickToSpeed(adcChannelRead(AN1)));
                xbeeWriteChar(CHAR_JOYSTICK_Y);
                xbeeWriteChar(joystickToSpeed(adcChannelRead(AN2)));
                
                break;        
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
    
    //gpioInit();
    //externInterruptInit(eINT1, eRisingEdge);
    //externInterruptEnable(eINT1);
    
    adc1Init(1000, b12); // number of 1us, 12 bits or 10 bits

    xbeeInit(57600);
    xbeeInterruptEnable(eRX);
    
	_GENERAL_INTERRUPT_ENABLED_; // start the interrupt
    
    
    /* Other init output the intern system */
    
    __delay_ms(200);
    
    bool check = joystickInit(AN1, ePORTx, pinRxxx); ///////////////////////////
    bool check2 = joystickInit(AN2, ePORTx, pinRxxx); //////////////////////////
    
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
}