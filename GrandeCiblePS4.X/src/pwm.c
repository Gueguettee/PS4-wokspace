/**
  ****************************************************************************
  * @file    pwm.c
  * @author  Andrea Enrile
  * @date    25.11.2019
  * @brief   initialization of the different PWMs and implementation of the 
  *          function setting the duty cycle and phase shift, and function
  *          enabling and disabling the PWMs.
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "pwm.h"

/******************************************************************************/
/*                              GLOBAL VARIABLE                               */
/******************************************************************************/
static uint32_t Fosc = 0UL;
static bool FoscFlag = false;
static bool PWMModulePrimaryFlag = false;
static bool PWMModuleSecondaryFlag = false;

/******************************************************************************/
/*                PWMs INITIALIZATION FUNCTION Inplementation                 */
/******************************************************************************/

void pwmAllInit(void)
{
    pwm_t ePWMx;
    for (ePWMx=ePWM1;ePWMx<NbrOfPWM;ePWMx++)
    {
        pwmInit(ePWMx,ePWMPrimaryTimeBase);
    }
}

void pwmInit(pwm_t ePWMx, pwmPER_t exPER){
    // Disabled PWM Module as some bits can't be changed otherwise
	PTCONbits.PTEN = 0;
    
    // Check if the PWM module is already initialized, if not initialize it
	if (PWMModulePrimaryFlag == false)
    {
        //Initialization of the PWM module with the Primary Time Base
		setPwmFreq(DEFAULTFPRIMARYPWM,ePWMPrimaryTimeBase);
    }
	if (PWMModuleSecondaryFlag == false)
    {
        //Initialization of the PWM module with the Secondary Time Base
		setPwmFreq(DEFAULTFSECONDARYPWM,ePWMSecondaryTimeBase);
    }
    
    switch(ePWMx)
    {
		case ePWM1:
             // Set PWM Mode to Complementary
            IOCON1bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON1bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON1bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON1bits.POLH = 0;    // PWMxH pin is active-high
            IOCON1bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON1, (IOCON1 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON1 = 0x0000;       // Clear PWM control register
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON1bits.MTBS = 1;   // Secondary Master time base selected  
            }

            setPwmPhase(ePWM1, 0);  // Phase of 0°
            
            setPwmDuty(ePWM1, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM1, 1000);    // Dead Time of 1us is usually large enough
            
            /* Configure Faults */
            FCLCON1bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON1, (FCLCON1 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		case ePWM2:
             // Set PWM Mode to Complementary
            IOCON2bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON2bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON2bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON2bits.POLH = 0;    // PWMxH pin is active-high
            IOCON2bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON2, (IOCON2 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON2 = 0x0000;       // Clear PWM control register
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON2bits.MTBS = 1;   // Secondary Master time base selected  
            }

            setPwmPhase(ePWM2, 0);  // Phase of 0°

            setPwmDuty(ePWM2, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM2, 1000);    // Dead Time of 1us is usually large enough

            /* Configure Faults */
            FCLCON2bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON2, (FCLCON2 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		case ePWM3:
             // Set PWM Mode to Complementary
            IOCON3bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON3bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON3bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON3bits.POLH = 0;    // PWMxH pin is active-high
            IOCON3bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON3, (IOCON3 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON3 = 0x0000;       // Clear PWM control register
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON3bits.MTBS = 1;   // Secondary Master time base selected  
            }
            
            setPwmPhase(ePWM3, 0);  // Phase of 0°

            setPwmDuty(ePWM3, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM3, 1000);    // Dead Time of 1us is usually large enough

            /* Configure Faults */
            FCLCON3bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON3, (FCLCON3 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		case ePWM4:
             // Set PWM Mode to Complementary
            IOCON4bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON4bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON4bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON4bits.POLH = 0;    // PWMxH pin is active-high
            IOCON4bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON4, (IOCON4 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON4 = 0x0000;       // Clear PWM control register
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON4bits.MTBS = 1;   // Secondary Master time base selected  
            }

            setPwmPhase(ePWM4, 0);  // Phase of 0°

            setPwmDuty(ePWM4, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM4, 1000);    // Dead Time of 1us is usually large enough

            /* Configure Faults */
            FCLCON4bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON4, (FCLCON4 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		case ePWM5:
             // Set PWM Mode to Complementary
            IOCON5bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON5bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON5bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON5bits.POLH = 0;    // PWMxH pin is active-high
            IOCON5bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON5, (IOCON5 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON5 = 0x0000;       // Clear PWM control register
            PWMCON5bits.FLTIEN = 0;
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON5bits.MTBS = 1;   // Secondary Master time base selected  
            }

            setPwmPhase(ePWM5, 0);  // Phase of 0°

            setPwmDuty(ePWM5, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM5, 1000);    // Dead Time of 1us is usually large enough

            /* Configure Faults */
            FCLCON5bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON5, (FCLCON5 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		case ePWM6:
             // Set PWM Mode to Complementary
            IOCON6bits.PMOD = 0b00; // PWMx I/O pin pair is in Complementary Output mode
            IOCON6bits.PENH = 1;    // PWMx module controls the PWMxH pin
            IOCON6bits.PENL = 1;    // PWMx module controls the PWMxL pin
            IOCON6bits.POLH = 0;    // PWMxH pin is active-high
            IOCON6bits.POLL = 0;    // PWMxL pin is active-highh
            //__builtin_write_PWMSFR(&IOCON6, (IOCON6 | 0xC000), &PWMKEY);    // If config PWMLOCK = ON

            /* PWMx control register PWMCONx
             * Settings:
             * PWMx generator uses the primary or secondary master time base in function of exPER
             * PTPER or STPER registers provide timing for this PWMx generator
             * PDCx register provides duty cycle information for this PWMx generator
             * Positive dead time actively applied to all output modes
             * Edge-Aligned mode is enabled
             */
            PWMCON6 = 0x0000;       // Clear PWM control register
            if (exPER==ePWMSecondaryTimeBase)
            {
                PWMCON6bits.MTBS = 1;   // Secondary Master time base selected  
            }

            setPwmPhase(ePWM6, 0);  // Phase of 0°

            setPwmDuty(ePWM6, 5000);  // Duty cycle of 50%

            setPwmDeadTime(ePWM6, 1000);    // Dead Time of 1us is usually large enough

            /* Configure Faults */
            FCLCON6bits.FLTMOD = 0b11;  // Fault mode disabled
            //__builtin_write_PWMSFR(&FCLCON6, (FCLCON6 | 0x0003), &PWMKEY);  // If config PWMLOCK = ON
			break;
		default:
			break;
	}
    
    PTCONbits.PTEN = 1;     // Enable PWMx Module
}

/******************************************************************************/
/*                     PWMs USER FUNCTIONS Inplementation                     */
/******************************************************************************/

void setPwmFreq(uint16_t pwmFreq, pwmPER_t exPER)
{
    uint8_t prescaler = 0;
	uint16_t xTPERValue = 0;
    
    genPWMParameter(pwmFreq, &prescaler, &xTPERValue);
    
    // PCLKDIV bits should be changed only when PTEN = 0
    uint8_t xTEN_setting = PTCONbits.PTEN;  // Read current PTEN setting
    PTCONbits.PTEN = 0;             // Disable PWM Module

    // Check the Time Base used to configure it correctly
	if (exPER==ePWMPrimaryTimeBase)
	{
        PTCON2bits.PCLKDIV = prescaler; // Initialization of the frequency divider for the PWMx
        PTPER = xTPERValue;             // PWM period: xTPER = Fosc/(FPWM*Prescaler)
        
        PWMModulePrimaryFlag = true;
    }
    
    // Check the Time Base used to configure it correctly
	if (exPER==ePWMSecondaryTimeBase)
    {
        // PCLKDIV bits should be changed only when PTEN = 0
        STCON2bits.PCLKDIV = prescaler; // Initialization of the frequency divider for the PWMx
        STPER = xTPERValue;             // PWM period: STPER = Fosc/(FPWM*Prescaler)
        
        PWMModuleSecondaryFlag = true;
    }
    PTCONbits.PTEN = xTEN_setting;  // Reapply PTEN setting
    
}

void setPwmPhase(pwm_t ePWMx, uint8_t phase)
{
    uint16_t phaseValue = (uint16_t)((uint32_t)PTPER*(phase%360)/360);
    
	switch(ePWMx)
	{
		case ePWM1:
			PHASE1 = phaseValue;    // Phase of PWM1
			break;
		case ePWM2:
			PHASE2 = phaseValue;    // Phase of PWM2
			break;
		case ePWM3:
			PHASE3 = phaseValue;    // Phase of PWM3
			break;
		case ePWM4:
			PHASE4 = phaseValue;    // Phase of PWM4
			break;
		case ePWM5:
			PHASE5 = phaseValue;    // Phase of PWM5
			break;
		case ePWM6:
			PHASE6 = phaseValue;    // Phase of PWM6
			break;
		default:
			break;
	}
}

void setPwmDeadTime(pwm_t ePWMx, uint16_t DT)
{
	uint16_t DTValue = 0;
	uint16_t altDTValue = 0;
	pwmPER_t exPER;
    
    // Check which Time Base is using in function of PWM channel
    if (pwmCheckPrimaryTimeBase(ePWMx))
    {
        exPER = ePWMPrimaryTimeBase;
    }
    else
    {
        exPER = ePWMSecondaryTimeBase;
    }
	// Set Dead Time DTRx, ALTDTRx = Fosc * (dead time/Prescale)
	genDTParameter(exPER, DT, &DTValue);
	
	altDTValue = DTValue;
	
	switch(ePWMx)
	{
		case ePWM1:
			DTR1 = DTValue;
			ALTDTR1 = altDTValue;
			break;
		case ePWM2:
			DTR2 = DTValue;
			ALTDTR2 = altDTValue;
			break;
		case ePWM3:
			DTR3 = DTValue;
			ALTDTR3 = altDTValue;
			break;
		case ePWM4:
			DTR4 = DTValue;
			ALTDTR4 = altDTValue;
			break;
		case ePWM5:
			DTR5 = DTValue;
			ALTDTR5 = altDTValue;
			break;
		case ePWM6:
			DTR6 = DTValue;
			ALTDTR6 = altDTValue;
			break;
		default:
			break;
	}
}

void setPwmDuty(pwm_t ePWMx, uint16_t DC)
{
    uint16_t DCValue;
	
	switch(ePWMx)
	{
		case ePWM1:
            if (pwmCheckPrimaryTimeBase(ePWM1))
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else{
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC1 = DCValue;		// Duty of PWM1
			break;
		case ePWM2:
            if (pwmCheckPrimaryTimeBase(ePWM2))
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else{
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC2 = DCValue;		// Duty of PWM2
			break;
		case ePWM3:
            if (pwmCheckPrimaryTimeBase(ePWM3)) 
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else{
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC3 = DCValue;		// Duty of PWM3
			break;
		case ePWM4:
            if (pwmCheckPrimaryTimeBase(ePWM4)) 
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else{
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC4 = DCValue;		// Duty of PWM4
			break;
		case ePWM5:
            if (pwmCheckPrimaryTimeBase(ePWM5)) 
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else
            {
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC5 = DCValue;		// Duty of PWM5
			break;
		case ePWM6:
            if (pwmCheckPrimaryTimeBase(ePWM6)) 
            {
                DCValue = (uint16_t)((uint32_t)PTPER*DC/10000);
            }
            else
            {
                DCValue = (uint16_t)((uint32_t)STPER*DC/10000);
            }
			PDC6 = DCValue;		// Duty of PWM6
			break;
		default:
			break;
	}
}

void pwmEnable(pwm_t ePWMx)
{
	switch(ePWMx)
	{
		case ePWM1:
			IOCON1bits.PENH = 0x1;		// 1 PWM module control PWM1H, 0 GPIO module control PWM1H
			IOCON1bits.PENL = 0x1;		// 1 PWM module control PWM1L, 0 GPIO module control PWM1L
			break;
		case ePWM2:
			IOCON2bits.PENH = 0x1;		// 1 PWM module control PWM2H, 0 GPIO module control PWM2H
			IOCON2bits.PENL = 0x1;		// 1 PWM module control PWM2L, 0 GPIO module control PWM2L
			break;
		case ePWM3:
			IOCON3bits.PENH = 0x1;		// 1 PWM module control PWM3H, 0 GPIO module control PWM3H
			IOCON3bits.PENL = 0x1;		// 1 PWM module control PWM3L, 0 GPIO module control PWM3L
			break;
		case ePWM4:
			IOCON4bits.PENH = 0x1;		// 1 PWM module control PWM4H, 0 GPIO module control PWM4H
			IOCON4bits.PENL = 0x1;		// 1 PWM module control PWM4L, 0 GPIO module control PWM4L
			break;
		case ePWM5:
			IOCON5bits.PENH = 0x1;		// 1 PWM module control PWM5H, 0 GPIO module control PWM5H
			IOCON5bits.PENL = 0x1;		// 1 PWM module control PWM5L, 0 GPIO module control PWM5L
			break;
		case ePWM6:
			IOCON6bits.PENH = 0x1;		// 1 PWM module control PWM6H, 0 GPIO module control PWM6H
			IOCON6bits.PENL = 0x1;		// 1 PWM module control PWM6L, 0 GPIO module control PWM6L
			break;
		default:
			break;
	}
}

void pwmDisable(pwm_t ePWMx)
{
  switch(ePWMx)
	{
		case ePWM1:
			IOCON1bits.PENH = 0x0;	// 1 PWM module control PWM1H, 0 GPIO module control PWM1H
			IOCON1bits.PENL = 0x0;	// 1 PWM module control PWM1L, 0 GPIO module control PWM1L
			break;
		case ePWM2:
			IOCON2bits.PENH = 0x0;	// 1 PWM module control PWM2H, 0 GPIO module control PWM2H
			IOCON2bits.PENL = 0x0;	// 1 PWM module control PWM2L, 0 GPIO module control PWM2L
			break;
		case ePWM3:
			IOCON3bits.PENH = 0x0;	// 1 PWM module control PWM3H, 0 GPIO module control PWM3H
			IOCON3bits.PENL = 0x0;	// 1 PWM module control PWM3L, 0 GPIO module control PWM3L
			break;
		case ePWM4:
			IOCON4bits.PENH = 0x0;	// 1 PWM module control PWM4H, 0 GPIO module control PWM4H
			IOCON4bits.PENL = 0x0;	// 1 PWM module control PWM4L, 0 GPIO module control PWM4L
			break;
		case ePWM5:
			IOCON5bits.PENH = 0x0;	// 1 PWM module control PWM5H, 0 GPIO module control PWM5H
			IOCON5bits.PENL = 0x0;	// 1 PWM module control PWM5L, 0 GPIO module control PWM5L
			break;
		case ePWM6:
			IOCON6bits.PENH = 0x0;	// 1 PWM module control PWM6H, 0 GPIO module control PWM6H
			IOCON6bits.PENL = 0x0;	// 1 PWM module control PWM6L, 0 GPIO module control PWM6L
			break;
		default:
			break;
	}
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genPWMParameter(uint16_t PWMFreq, uint8_t *prescaler, uint16_t *xTPERValue)
{
	// Check if Fosc was already calculated, if not, compute it
	if(FoscFlag == false) 
	{
		genOscFreq();
	}
	
    // Compute theoretical PCLKDIV value
    uint8_t clk_div = 0;
	while (Fosc/(PWMFreq*(1<<clk_div)) > UINT16_MAX)
	{
		clk_div++;
	}
	
    if (clk_div > 0b110)    // Max valid PCLKDIV value
    {
        // Set to min achievable PWM frequency
        *prescaler = 0b110;
        *xTPERValue = UINT16_MAX;
    }
    else
    {
        *prescaler = clk_div;
        *xTPERValue = Fosc/(PWMFreq*(1<<clk_div));  // Fosc/(FPWM*Prescaler)
    }
}

/// @private
void genDTParameter(pwmPER_t exPER, uint16_t DT, uint16_t *DTValue)
{
    uint16_t prescaler=0;
    
	// Check if Fosc already calculated, if not compute it
	if(false == FoscFlag)
	{
		genOscFreq();
	}
	
    if (exPER==ePWMPrimaryTimeBase)
    {
        prescaler = 1<<PTCON2bits.PCLKDIV;
    }
    else if (exPER==ePWMSecondaryTimeBase)
    {
        prescaler = 1<<STCON2bits.PCLKDIV;
    }
    
    /* ALTDTRx, DTRx = FOSC * Desired Dead Time / PWM Input Clock Prescaler
     *               = FOSC * (DT[ns] / 1e9) / PCLKDIV
     *               = FOSC * DT[ns] / (1e9 * PCLKDIV)
     * Note: +1 is to avoid 0 value for 0 and small values ([0...8) @120MHz)
     */
    *DTValue = (uint16_t)((float)Fosc*DT/(1.0E9*prescaler))+1;
}

/// @private
void genOscFreq(void)
{
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
	Fosc = (uint32_t)(7370000*M/(N1*N2));
	FoscFlag = true;
}

/// @private
bool pwmCheckPrimaryTimeBase(pwm_t ePWMx)
{
  switch(ePWMx)
	{
		case ePWM1:
			return (PWMCON1bits.MTBS==0);  //return true if the PWM1 using the Primary Time Base
		case ePWM2:
			return (PWMCON2bits.MTBS==0);  //return true if the PWM2 using the Primary Time Base
		case ePWM3:
			return (PWMCON3bits.MTBS==0);  //return true if the PWM3 using the Primary Time Base
		case ePWM4:
			return (PWMCON4bits.MTBS==0);  //return true if the PWM4 using the Primary Time Base
		case ePWM5:
			return (PWMCON5bits.MTBS==0);  //return true if the PWM5 using the Primary Time Base
		case ePWM6:
			return (PWMCON6bits.MTBS==0);  //return true if the PWM6 using the Primary Time Base
		default:
			return true;
			break;
	}    
}