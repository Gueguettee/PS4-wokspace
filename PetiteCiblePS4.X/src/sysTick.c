/**
  ****************************************************************************
  * @file    sysTick.c
  * @author  Andrea Enrile & Simone Varischetti
  * @date    20.11.2019
  * @brief   Implementation of the sysTick initialization using timer1 and
  *          the function to change the period of the sysTick. Max period with
  *          Fosc = 120MHz: 280174us
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include  "sysTick.h"

/******************************************************************************/
/*                              EXTERNAL VARIABLE                             */
/******************************************************************************/
uint8_t sysTickFlag = 0;

/******************************************************************************/
/*               SYSTICK INITIALIZATION FUNCTION Implementation               */
/******************************************************************************/

void sysTickInitDflt(void)
{
	sysTickInit(1000UL);    // 1000 us period
}

void sysTickInit(uint32_t period)
{
	TRISCbits.TRISC3 = 0;   // Configure sysTick LED
    
    /* The following code sequence shows Timer1 registers configuration for sysTick */
	uint8_t prescaler = 0;
	uint16_t PRx = 0;
	
    IEC0bits.T1IE = 0;  // Disable Timer 1 interrupt
    
    T1CONbits.TON = 0;  // Turn OFF Timer 1
    T1CON = 0;          // Clear Timer 1 configuration register
	
	TMR1 = 0;           // Clear Timer 1 current value
    
    genSysTickPeriodParam(period, &prescaler, &PRx);   //Calculate prescaler & PRx based on the period
	T1CONbits.TCKPS = prescaler;    // Set Timer 1 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
	PR1 = PRx;                      // Set Timer 1 period (max value is 65535)
    
	T1CONbits.TON = 1;  // Turn ON Timer 1
    
    // Interrupt Controller Settings
    IPC0bits.T1IP = 6;  // Set Timer 1 interrupt priority
	IFS0bits.T1IF = 0;  // Clear Timer 1 interrupt flag
	IEC0bits.T1IE = 1;  // Enable Timer 1 interrupt
}

/******************************************************************************/
/*                    SYSTICK USER FUNCTIONS Inplementation                   */
/******************************************************************************/

void sysTickPeriod(uint32_t period)
{
	uint8_t prescaler = 0;
	uint16_t PRx = 0;
	
	genSysTickPeriodParam(period, &prescaler, &PRx);    //Function to calculate Prescaler and PRx from the period
	
	TMR1 = 0;                       // Clear Timer 1 current value
	T1CONbits.TCKPS = prescaler;    // Set Timer 1 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
	PR1 = PRx;                      // Set Timer 1 period (max value is 65535)         
}

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/
// Timer1 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _T1Interrupt(void)
{
	sysTickFlag = 1;    // Set the System Timer Flag = 1;
	IFS0bits.T1IF = 0;  // Clear Timer 1 interrupt flag
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genSysTickPeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx)
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
	
	uint32_t Fosc = (uint32_t)(7370000*M/(N1*N2));
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