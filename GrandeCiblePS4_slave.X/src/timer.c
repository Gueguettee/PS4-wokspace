/**
  ****************************************************************************
  * @file    timer.c
  * @author  Andrea Enrile
  * @date    14.11.2019
  * @brief   The user configuration is not error safe, if one of the configurable
  *	         32-bits dual timer (Timer2/3 to timer8/9) timers is used, functions
  *	         will overwrite this configuration with a 16-bit timer. Max period
  *          with Fosc = 120MHz: 280174us
  *	         For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "timer.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_timer2_pointer = 0;
static Callback_t cbf_timer3_pointer = 0;
static Callback_t cbf_timer4_pointer = 0;
static Callback_t cbf_timer5_pointer = 0;
static Callback_t cbf_timer6_pointer = 0;
static Callback_t cbf_timer7_pointer = 0;
static Callback_t cbf_timer8_pointer = 0;
static Callback_t cbf_timer9_pointer = 0;

/******************************************************************************/
/*               TIMERs INITIALIZATION FUNCTION Implementation                */
/******************************************************************************/

void timerAllInit(void)
{
    timer_t eTimerx;
    for (eTimerx=eTimer2;eTimerx<eNbrOfTimer;eTimerx++)
    {
        timerInit(eTimerx);
    }
}

void timerInit(timer_t eTimerx){
	const uint32_t period_100us = 100UL;          // 100 us period
	const uint32_t period_1ms = 1UL * 1000UL;     // 1 ms period
    const uint32_t period_10ms = 10UL * 1000UL;   // 10 ms period
    const uint32_t period_100ms = 100UL * 1000UL; // 100 ms period
    uint8_t prescaler;
	uint16_t PRx;

    switch(eTimerx)
    {
        case eTimer4:
            prescaler = 0;
            PRx = 0;

            IEC1bits.T4IE = 0;  // Disable Timer 4 interrupt 

            T4CONbits.TON = 0;  // Turn OFF Timer 4
            T4CON = 0;          // Clear Timer 4 configuration

            TMR4 = 0; // Set Timer 4 current value to avoid simultaneous end of timers

            genPeriodParam(period_100us, &prescaler, &PRx);
            T4CONbits.TCKPS = prescaler;    // Set Timer 4 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
            PR4 = PRx;                      // Set Timer 4 period (max value is 65535)

            T4CONbits.TON = 1;  // Turn ON Timer 4

            // Interrupt Controller Settings
            IPC6bits.T4IP = 1;  // Set Timer 4 interrupt priority
            IFS1bits.T4IF = 0;  // Clear Timer 4 interrupt flag
            IEC1bits.T4IE = 1;  // Enable Timer 4 interrupt 
            break;
        case eTimer5:
            prescaler = 0;
            PRx = 0;

            IEC1bits.T5IE = 0;  // Disable Timer 5 interrupt

            T5CONbits.TON = 0;  // Turn OFF Timer 5
            T5CON = 0;          // Clear Timer 5 configuration

            TMR5 = 0; // Set Timer 5 current value to avoid simultaneous end of timers

            genPeriodParam(period_1ms, &prescaler, &PRx);
            T5CONbits.TCKPS = prescaler;    // Set Timer 5 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
            PR5 = PRx;                      // Set Timer 5 period (max value is 65535)

            T5CONbits.TON = 1;  // Turn ON Timer 5

            // Interrupt Controller Settings
            IPC7bits.T5IP = 1;  // Set Timer 5 interrupt priority
            IFS1bits.T5IF = 0;  // Clear Timer 5 interrupt flag
            IEC1bits.T5IE = 1;  // Enable Timer 5 interrupt
            break;
        case eTimer6:
            // Configure Timer 6
            prescaler = 0;
            PRx = 0;

            IEC2bits.T6IE = 0;  // Disable Timer 6 interrupt

            T6CONbits.TON = 0;  // Turn OFF Timer 6
            T6CON = 0;          // Clear Timer 6 configuration

            TMR6 = 0; // Set Timer 6 current value to avoid simultaneous end of timers

            genPeriodParam(period_10ms, &prescaler, &PRx);
            T6CONbits.TCKPS = prescaler;    // Set Timer 6 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
            PR6 = PRx;                      // Set Timer 6 period (max value is 65535)

            T6CONbits.TON = 1;  // Turn ON Timer 6

            // Interrupt Controller Settings
            IPC11bits.T6IP = 1; // Set Timer 6 interrupt priority
            IFS2bits.T6IF = 0;  // Clear Timer 6 interrupt flag
            IEC2bits.T6IE = 1;  // Enable Timer 6 interrupt
            break;
        case eTimer7:
            // Configure Timer 7
            prescaler = 0;
            PRx = 0;

            IEC3bits.T7IE = 0;  // Disable Timer 7 interrupt

            T7CONbits.TON = 0;  // Turn OFF Timer 7
            T7CON = 0;          // Clear Timer 7 configuration

            TMR7 = 0;    // Set Timer 7 current value to avoid simultaneous end of timers

            genPeriodParam(period_100ms, &prescaler, &PRx);
            T7CONbits.TCKPS = prescaler;    // Set Timer 7 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
            PR7 = PRx;                      // Set Timer 7 period (max value is 65535)

            T7CONbits.TON = 1;  // Turn ON Timer 7

            // Interrupt Controller Settings
            IPC12bits.T7IP = 1; // Set Timer 7 interrupt priority
            IFS3bits.T7IF = 0;  // Clear Timer 7 interrupt flag
            IEC3bits.T7IE = 1;  // Enable Timer 7 interrupt
            break;
        default:
            break;
    }
}

/******************************************************************************/
/*                    TIMERs USER FUNCTIONS Inplementation                    */
/******************************************************************************/

void timerConfig(timer_t eTimerX, uint8_t prescaler, uint16_t PRx,
                 bool enableInterrupt, uint8_t priority)
{
	switch(eTimerX)
	{
		case eTimer2:
            IEC0bits.T2IE = 0;  // Disable Timer 2 interrupt
            
			T2CONbits.TON = 0;  // Turn OFF Timer 2
			T2CON = 0;          // Clear Timer 2 configuration
            
			TMR2 = 0;           // Set Timer 2 current value to avoid simultaneous end of timers
            
			T2CONbits.TCKPS = prescaler & 0x03; // Set timer 2 prescaler
			PR2 = PRx;                          // Set Timer 2 period (max value is 65535)
			
			T2CONbits.TON = 1;  // Turn ON Timer 2
            
            // Interrupt Controller Settings
            IPC1bits.T2IP = priority & 0x07;    // Set Timer 2 interrupt priority
			IFS0bits.T2IF = 0;                  // Clear Timer 2 interrupt flag
			IEC0bits.T2IE = enableInterrupt;    // Enable Timer 2 interrupt
			break;
		case eTimer3:
            IEC0bits.T3IE = 0;  // Disable Timer 3 interrupt
            
			T3CONbits.TON = 0;  // Turn OFF Timer 3
			T3CON = 0;          // Clear Timer 3 configuration
            
			TMR3 = 0;           // Set Timer 3 current value to avoid simultaneous end of timers
            
			T3CONbits.TCKPS = prescaler & 0x03; // Set timer 3 prescaler
			PR3 = PRx;                          // Set Timer 3 period (max value is 65535)
			
			T3CONbits.TON = 1;  // Turn ON Timer 3
            
            // Interrupt Controller Settings
            IPC2bits.T3IP = priority & 0x07;    // Set Timer 3 interrupt priority
			IFS0bits.T3IF = 0;                  // Clear Timer 3 interrupt flag
			IEC0bits.T3IE = enableInterrupt;    // Enable Timer 3 interrupt
			break;
		case eTimer8:
            IEC3bits.T8IE = 0;  // Disable Timer 8 interrupt
            
			T8CONbits.TON = 0;  // Turn OFF Timer 8
			T8CON = 0;          // Clear Timer 8 configuration
            
			TMR8 = 0;           // Set Timer 8 current value to avoid simultaneous end of timers7
            
			T8CONbits.TCKPS = prescaler & 0x03; // Set timer 8 prescaler
			PR8 = PRx;                          // Set Timer 8 period (max value is 65535)
			
			T8CONbits.TON = 1;  // Turn ON Timer 8
            
            // Interrupt Controller Settings
            IPC12bits.T8IP = priority & 0x07;   // Set Timer 8 interrupt priority
			IFS3bits.T8IF = 0;                  // Clear Timer 8 interrupt flag
			IEC3bits.T8IE = enableInterrupt;    // Enable Timer 8 interrupt
			break;
		case eTimer9:
            IEC3bits.T9IE = 0;  // Disable Timer 9 interrupt
            
			T9CONbits.TON = 0;  // Turn OFF Timer 9
			T9CON = 0;          // Clear Timer 9 configuration
            
			TMR9 = 0;           // Set Timer 9 current value to avoid simultaneous end of timers
            
			T9CONbits.TCKPS = prescaler & 0x03; // Set timer 9 prescaler
			PR9 = PRx;                          // Set Timer 9 period (max value is 65535)
			
			T9CONbits.TON = 1;  // Turn ON Timer 9
            
            // Interrupt Controller Settings
            IPC13bits.T9IP = priority & 0x07;   // Set Timer 9 interrupt priority
			IFS3bits.T9IF = 0;                  // Clear Timer 9 interrupt flag
			IEC3bits.T9IE = enableInterrupt;    // Enable Timer 9 interrupt
			break;
		default:
			break;
  }
}

void setTimerPeriod(timer_t eTimerX, uint32_t period)
{
	uint8_t prescaler = 0;
	uint16_t PRx = 0;
	
	genPeriodParam(period, &prescaler, &PRx);   // Function to calculate prescaler and PRx from the period in us
	
	switch(eTimerX)
	{
		case eTimer2:
			T2CONbits.TON = 0;  // Turn OFF Timer 2
            
			TMR2 = 0;           // Set Timer 2 current value to avoid simultaneous end of timers
            
			T2CONbits.TCKPS = prescaler & 0x03; // Set timer 2 prescaler
			PR2 = PRx;                          // Set Timer 2 period (max value is 65535)
            
			T2CONbits.TON = 1;  // Turn ON Timer 2
			break;
		case eTimer3:
			T3CONbits.TON = 0;  // Turn OFF Timer 3
            
			TMR3 = 0;           // Set Timer 3 current value to avoid simultaneous end of timers
            
			T3CONbits.TCKPS = prescaler & 0x03; // Set timer 3 prescaler
			PR3 = PRx;                          // Set Timer 3 period (max value is 65535)
            
			T3CONbits.TON = 1;  // Turn ON Timer 3
			break;
		case eTimer8:
			T8CONbits.TON = 0;  // Turn OFF Timer 8
            
			TMR8 = 0;           // Set Timer 8 current value to avoid simultaneous end of timers
            
			T8CONbits.TCKPS = prescaler & 0x03; // Set timer 8 prescaler
			PR8 = PRx;                          // Set Timer 8 period (max value is 65535)
            
			T8CONbits.TON = 1;  // Turn ON Timer 8
			break;
		case eTimer9:
			T9CONbits.TON = 0;  // Turn OFF Timer 9
            
			TMR9 = 0;           // Set Timer 9 current value to avoid simultaneous end of timers
            
			T9CONbits.TCKPS = prescaler & 0x03; // Set timer 9 prescaler
			PR9 = PRx;                          // Set Timer 9 period (max value is 65535)
            
			T9CONbits.TON = 1;  // Turn ON Timer 9
			break;
		default:
			break;
	}
}

void timerInterruptEnable(timer_t eTimerX)
{
	switch(eTimerX)
	{
		case eTimer2:
			IFS0bits.T2IF = 0;	// Clear Timer 2 interrupt flag
			IEC0bits.T2IE = 1;  // Enable Timer 2 interrupt
			break;
		case eTimer3:
			IFS0bits.T3IF = 0;	// Clear Timer 3 interrupt flag
			IEC0bits.T3IE = 1;  // Enable Timer 3 interrupt
			break;
		case eTimer8:
			IFS3bits.T8IF = 0;	// Clear Timer 8 interrupt flag
			IEC3bits.T8IE = 1;  // Enable Timer 8 interrupt
			break;
		case eTimer9:
			IFS3bits.T9IF = 0;	// Clear Timer 9 interrupt flag
			IEC3bits.T9IE = 1;  // Enable Timer 9 interrupt
			break;
		default:
			break;
	}
}

void timerInterruptDisable(timer_t eTimerX)
{
	switch(eTimerX)
	{
		case eTimer2:
			IFS0bits.T2IF = 0;	// Clear Timer 2 interrupt flag
			IEC0bits.T2IE = 0;  // Enable Timer 2 interrupt
			break;
		case eTimer3:
			IFS0bits.T3IF = 0;	// Clear Timer 3 interrupt flag
			IEC0bits.T3IE = 0;  // Enable Timer 3 interrupt
			break;
		case eTimer8:
			IFS3bits.T8IF = 0;	// Clear Timer 8 interrupt flag
			IEC3bits.T8IE = 0;  // Enable Timer 8 interrupt
			break;
		case eTimer9:
			IFS3bits.T9IF = 0;	// Clear Timer 9 interrupt flag
			IEC3bits.T9IE = 0;  // Enable Timer 9 interrupt
			break;
		default:
			break;
	}
}

void setTimerPriority(timer_t eTimerX, uint8_t priority)
{
	switch(eTimerX)
	{
		case eTimer2:
			IPC1bits.T2IP = priority & 0x07;    // Set Timer 2 interrupt priority
			break;
		case eTimer3:
			IPC2bits.T3IP = priority & 0x07;    // Set Timer 3 interrupt priority
			break;
		case eTimer8:
			IPC12bits.T8IP = priority & 0x07;   // Set Timer 8 interrupt priority
			break;
		case eTimer9:
			IPC13bits.T9IP = priority & 0x07;   // Set Timer 9 interrupt priority
			break;
		default:
			break;
	}
}

/******************************************************************************/
/*                       Timer Interrupt Routines (IRQ)                       */
/******************************************************************************/
//Callback register function
void registerTimerCallback(timer_t eTimerX, Callback_t cbf_pointer)
{
    switch (eTimerX)
    {
        case eTimer2:
            cbf_timer2_pointer = cbf_pointer;
            break;
        //Timer3 used for ADC1
        case eTimer4:
            cbf_timer4_pointer = cbf_pointer;
            break; 
        case eTimer5:
            cbf_timer5_pointer = cbf_pointer;
            break;
        case eTimer6:
            cbf_timer6_pointer = cbf_pointer;
            break;
        case eTimer7:
            cbf_timer7_pointer = cbf_pointer;
            break;
        case eTimer8:
            cbf_timer8_pointer = cbf_pointer;
            break;
        case eTimer9:
            cbf_timer9_pointer = cbf_pointer;
            break;
        default:
            break;
    }
}

// Timer2 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T2Interrupt(void)
{
  IFS0bits.T2IF = 0;            // Clear Timer 2 interrupt flag
  if (0!=cbf_timer2_pointer)
  {
    cbf_timer2_pointer();
  }
}
// Timer4 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T4Interrupt(void)
{
  IFS1bits.T4IF = 0;            // Clear Timer 4 interrupt flag
  if (0!=cbf_timer4_pointer)
  {
    cbf_timer4_pointer();
  }
}
// Timer5 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T5Interrupt(void)
{
  IFS1bits.T5IF = 0;            // Clear Timer 5 interrupt flag
  if (0!=cbf_timer5_pointer)
  {
    cbf_timer5_pointer();
  }
}
// Timer6 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T6Interrupt(void)
{
  IFS2bits.T6IF = 0;            // Clear Timer 6 interrupt flagg
  if (0!=cbf_timer6_pointer)
  {
    cbf_timer6_pointer();
  }
}
// Timer7 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T7Interrupt(void)
{
  IFS3bits.T7IF = 0;            // Clear Timer 7 interrupt flag
  if (0!=cbf_timer7_pointer)
  {
    cbf_timer7_pointer();
  }
}
// Timer8 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T8Interrupt(void)
{
  IFS3bits.T8IF = 0;            // Clear Timer 8 interrupt flag
  if (0!=cbf_timer8_pointer)
  {
    cbf_timer8_pointer();
  }
}
// Timer9 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T9Interrupt(void)
{
  IFS3bits.T9IF = 0;            // Clear Timer 9 interrupt flag
  if (0!=cbf_timer9_pointer)
  {
    cbf_timer9_pointer();
  }
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genPeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx)
{
    const uint16_t PrescalerVal[4] = {1,8,64,256};
    float PRx_f = 0;
    
	// Abort the program if period is 0 or a pointer address is NULL.
	if(0 == period || NULL == prescaler || NULL == PRx)
	{
		assert(0);
	}
    
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
	uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
	uint32_t Fcy = Fosc >> 1;
	
    /* Period[s] = 1/Fcy * prescaler * PRx
     * Period[us] = 1000000/Fcy * prescaler * PRx
     * PRx = (Period[us] * Fcy) / (prescaler * 1000000) */
    uint8_t i;
	for(i = 0; i < 4; i++)
	{
        PRx_f = (float)period*Fcy/(PrescalerVal[i]*1000000);
        if((uint32_t)PRx_f <= UINT16_MAX)
        {
            *prescaler = i;
            *PRx = (uint16_t)PRx_f;
            break;
        }
        else if (i == 3)    // PRx is out of range
        {
            *prescaler = 3;
            *PRx = UINT16_MAX;
        }
    }
}