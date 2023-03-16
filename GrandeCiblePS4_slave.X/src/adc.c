/**
  ****************************************************************************
  * @file    adc.c
  * @author  Andrea Enrile & Simone Varischetti
  * @date    20.11.2019
  * @brief   Implementation of the Analog to Digital conversion functions and
  *          Initialization of ADC 1 sampling in sequence multiple ANx inputs
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "adc.h"

/******************************************************************************/
/*                              GLOBAL VARIABLE                               */
/******************************************************************************/
analog_read_t value;		// global value to store the ADC1 conversion value

static Callback_t cbf_adc1_pointer = 0;

/******************************************************************************/
/*                 ADC INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/

void var_adc1Init(adc_args in)
{
    uint32_t period = in.period ? in.period : 1000;             // 1000us by default
    resolution_t adcRes = in.resolution ? in.resolution : b12;  // 12bits by default

    IEC0bits.AD1IE = 0;     // Disable AD1 interrupt
    
	AD1CON1bits.ADON = 0;   // Disable AD1 for config
    
	/* Assign MUXA inputs */
    AD1CHS0bits.CH0SA = 0;  // CH0SA bits ignored for CH0 +ve input selection
	AD1CHS0bits.CH0NA = 0;  // CH0 negative input is VREFL
	// AD1CSSH/AD1CSSL: A/D Input Scan Selection Register
	AD1CSSH = 0xD100;       // AN 31-30-28-24 activated and scanned
	AD1CSSL = 0x09FF;       // AN 11 + AN 0-8 activated and scanned

    uint8_t noOfCh = countSetBits(AD1CSSH) + countSetBits(AD1CSSL);
    
	/* AD1CON1 Register */
    AD1CON1bits.FORM = 0b00;    // Data output format is unsigned integer
	AD1CON1bits.SIMSAM = 0;     // Samples multiple channels individually in sequence
    if (adcRes == b12)
    {
        AD1CON1bits.AD12B = 1;  // 12-bit, 4-channel ADCx operation
    }
    else
    {
        AD1CON1bits.AD12B = 0;  // 10-bit, 4-channel ADCx operation
    }
	AD1CON1bits.ASAM = 1;       // Sampling begins immediately after last conversion;
                                // SAMP bit is auto-set
	AD1CON1bits.SSRCG = 0;      // Sample Trigger Source Group bit
	AD1CON1bits.SSRC = 0b010;   // Timer3 compare ends sampling and starts conversion
    /* AD1CON2 Register */
	AD1CON2bits.CHPS = 0b00;    // Converts CH0 (When AD12B = 1, CHPS<1:0> is: U-0 (Unimplemented: Read as ?0?))
	AD1CON2bits.VCFG = 0b000;   // VREFH is AVDD and VREFH is AVSS
	AD1CON2bits.CSCNA = 1;      // Scans inputs for CH0+ during Sample MUXA
	AD1CON2bits.ALTS = 0;       // Always uses channel input selects for Sample MUXA
    AD1CON2bits.SMPI = noOfCh-1;// ADC interrupt is generated at the completion of every nth sample/conversion operation
	AD1CON2bits.BUFM = 0;       // Always starts filling the buffer from the Start address
	/* AD1CON3 Register: configuration of time sample and conversion */
	AD1CON3bits.ADRC = 0;       // ADC Clock is derived from System Clock
    // This bit is only used if SSRC<2:0> (AD1CON1<7:5>) = 111 and SSRCG (AD1CON1<4>) = 0:
    if (AD1CON1bits.AD12B == 1)
    {
        AD1CON3bits.SAMC = 3;   // @12 bits; Sample for 3 * Tad before converting
    }
    else
    {
        if ((CM1CONbits.OPMODE == 1 && AD1CSSLbits.CSS3 == 1) || (CM2CONbits.OPMODE == 1 && AD1CSSLbits.CSS0 == 1) ||
            (CM3CONbits.OPMODE == 1 && AD1CSSLbits.CSS6 == 1) || (CM5CONbits.OPMODE == 1 && AD1CSSHbits.CSS25 == 1))
        {
            AD1CON3bits.SAMC = 4;   // @10 bits; Sample for 4 * Tad before converting
        }
        else
        {
            AD1CON3bits.SAMC = 2;   // @10 bits; Sample for 2 * Tad before converting
        }
    }
	AD1CON3bits.ADCS = genADCSParam();  // TAD = TCY * (ADCS + 1); 
                                        // TADmin @12/10 bits mode: 117.6/75 ns
                                // ADC conversion time for 10-bit Tconv = 12 * Tad
    /* AD1CON4 Register */
	AD1CON4bits.ADDMAEN = 0;    // Conversion results are stored in the ADC1BUF0
                                // through ADC1BUFF registers; DMA will not be used

    AD1CON1bits.ADON = 1;   // Enable AD1 
	
	// Interrupt Controller Settings
	IPC3bits.AD1IP = 2;     // Priority level = 2
    IFS0bits.AD1IF = 0;     // Clear AD1 interrupt flag bit
	IEC0bits.AD1IE = 1;     // Enable AD1 interrupt
    
	// Init timer3 used as ADC conversion trigger
	timer3Init(period);
}

/******************************************************************************/
/*                     ADC USER FUNCTIONS Inplementation                      */
/******************************************************************************/

uint16_t adcChannelRead(analog_t ANx)
{
	switch(ANx)
	{
#ifdef ML180V3
		case AN0:   // AN0 uP pin
			return value.AN0;
			break;
		case AN1:   // AN1 uP pin
			return value.AN1;
			break;
		case AN2:   // AN2 uP pin
			return value.AN2;
			break;
		case AN3:   // AN3 uP pin
			return value.AN3;
			break;
		case AN4:   // AN4 uP pin
			return value.AN4;
			break;
		case AN5:   // AN5 uP pin
			return value.AN5;
			break;
		case AN6:   // AN6 uP pin
			return value.AN6;
			break;
		case AN7:   // AN7 uP pin
			return value.AN7;
			break;
		case A0:    // AN8 uP pin
			return value.A0;
			break;
		case A1:    // AN11 uP pin
			return value.A1;
			break;
		case A2:    // AN24 uP pin
			return value.A2;
			break;
		case A3:    // AN28 uP pin
			return value.A3;
			break;
		case A4:    // AN30 uP pin
			return value.A4;
			break;
		case A5:    // AN31 uP pin
			return value.A5;
			break;
#else
#ifdef ML180V2
        case AN0:   // AN5 uP pin
			return value.AN0;
			break;
		case AN1:   // AN4 uP pin
			return value.AN1;
			break;
		case AN2:   // AN3 uP pin
			return value.AN2;
			break;
		case AN3:   // AN2 uP pin
			return value.AN3;
			break;
		case AN4:   // AN1 uP pin
			return value.AN4;
			break;
		case AN5:   // AN0 uP pin
			return value.AN5;
			break;
		case AN6:   // AN24 uP pin
			return value.AN6;
			break;
		case AN7:   // AN28 uP pin
			return value.AN7;
			break;
		case A0:    // AN11 uP pin
			return value.A0;
			break;
		case A1:    // AN6 uP pin
			return value.A1;
			break;
		case A2:    // AN7 uP pin
			return value.A2;
			break;
		case A3:    // AN8 uP pin
			return value.A3;
			break;
		case A4:    // AN30 uP pin
			return value.A4;
			break;
		case A5:    // AN31 uP pin
			return value.A5;
			break;
#endif
#endif
		default:
            return 0xdead;
			break;
	}
}

uint16_t adcChannelReadmV(analog_t ANx)
{	
    uint16_t mVValue;
            
    if(AD1CON1bits.AD12B == 1)
    {
#ifdef ML180V3
        /* Uin PIC [V] = Uin pin * 3.3k/5.1k = 3.3 * ADC val/2^12
         * Uin pin [V] = 5.1 * 3.3 * ADC val/(3.3*4096)
         * Uin pin [mV] = 1000 * 5.1 * ADC val / 4096 = 1275 * ADC val / 1024
         */
        mVValue = (uint16_t)((uint32_t)adcChannelRead(ANx)*1275/1024);
#else
#ifdef ML180V2
        /* Uin PIC [V] = Uin pin * 3k/5k = 3.3 * ADC val/2^12
         * Uin pin [V] = 5 * 3.3 * ADC val/(3*4096)
         * Uin pin [mV] = 1000 * 5.5 * ADC val / 4096 = 1375 * ADC val / 1024
         */
        mVValue = (uint16_t)((uint32_t)adcChannelRead(ANx)*1375/1024);
#endif
#endif
    }
    else
    {
#ifdef ML180V3
        /* Uin PIC [V] = Uin pin * 3.3k/5.1k = 3.3 * ADC val/2^10
         * Uin pin [V] = 5.1 * 3.3 * ADC val/(3.3*1024)
         * Uin pin [mV] = 1000 * 5.1 * ADC val / 1024 = 1275 * ADC val / 256
         */
        mVValue = (uint16_t)((uint32_t)adcChannelRead(ANx)*1275/256);
#else
#ifdef ML180V2
        /* Uin PIC [V] = Uin pin * 3k/5k = 3.3 * ADC val/2^10
         * Uin pin [V] = 5 * 3.3 * ADC val/(3*1024)
         * Uin pin [mV] = 1000 * 5.5 * ADC val / 1024 = 1375 * ADC val / 256
         */
        mVValue = (uint16_t)((uint32_t)adcChannelRead(ANx)*1375/256);
#endif
#endif
    }

	return mVValue;
}

/******************************************************************************/
/*                        GPIO Interrupt Routines (IRQ)                       */
/******************************************************************************/
void adc1InterruptEnable(void){
    AD1CON1bits.ADON = 1; // Enable AD1 
    IFS0bits.AD1IF = 0;   // Clear AD1 interrupt flag bit
	IEC0bits.AD1IE = 1;   // Enable AD1 interrupt

	IFS0bits.T3IF = 0;    // Clear Timer 3 interrupt flag
	IEC0bits.T3IE = 1;    // Enable Timer 3 interrupt
}

void adc1InterruptDisnable(void){
	IEC0bits.T3IE = 0;    // Disable Timer 3 interrupt
	IFS0bits.T3IF = 0;    // Clear Timer 3 interrupt flag
    TMR3 = 0;             // Reset Timer 3 value

    AD1CON1bits.ADON = 0; // Disable AD1 
	IEC0bits.AD1IE = 0;   // Disable AD1 interrupt
    IFS0bits.AD1IF = 0;   // Clear AD1 interrupt flag bit
}


//Callback register function
void registerADC1Callback(Callback_t cbf_pointer)
{
    cbf_adc1_pointer = cbf_pointer;
}

/******************************************************************************/
/*                        ADC Interrupt Routines (IRQ)                        */
/******************************************************************************/
//ADC1 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _AD1Interrupt(void)
{
	//Read of all the ADC1 used buffer
#ifdef ML180V3
	value.AN0 = ADC1BUF0;   // AN0 uP pin
	value.AN1 = ADC1BUF1;   // AN1 uP pin
	value.AN2 = ADC1BUF2;   // AN2 uP pin
	value.AN3 = ADC1BUF3;   // AN3 uP pin
	value.AN4 = ADC1BUF4;   // AN4 uP pin
	value.AN5 = ADC1BUF5;   // AN5 uP pin
	value.AN6 = ADC1BUF6;   // AN6 uP pin
	value.AN7 = ADC1BUF7;   // AN7 uP pin
	value.A0  = ADC1BUF8;   // AN8 uP pin
	value.A1  = ADC1BUF9;   // AN11 uP pin
	value.A2  = ADC1BUFA;   // AN24 uP pin
	value.A3  = ADC1BUFB;   // AN28 uP pin
	value.A4  = ADC1BUFC;   // AN30 uP pin
	value.A5  = ADC1BUFD;   // AN31 uP pin
#else
#ifdef ML180V2
    value.AN5 = ADC1BUF0;   // AN0 uP pin
	value.AN4 = ADC1BUF1;   // AN1 uP pin
	value.AN3 = ADC1BUF2;   // AN2 uP pin
	value.AN2 = ADC1BUF3;   // AN3 uP pin
	value.AN1 = ADC1BUF4;   // AN4 uP pin
	value.AN0 = ADC1BUF5;   // AN5 uP pin
	value.A1  = ADC1BUF6;   // AN6 uP pin
	value.A2  = ADC1BUF7;   // AN7 uP pin
	value.A3  = ADC1BUF8;   // AN8 uP pin
	value.A0  = ADC1BUF9;   // AN11 uP pin
	value.AN6 = ADC1BUFA;   // AN24 uP pin
	value.AN7 = ADC1BUFB;   // AN28 uP pin
	value.A4  = ADC1BUFC;   // AN30 uP pin
	value.A5  = ADC1BUFD;   // AN31 uP pin
#endif
#endif
    
	IFS0bits.AD1IF = 0;
    if (0!=cbf_adc1_pointer)
    {
        cbf_adc1_pointer();
    }
}

// Timer3 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T3Interrupt(void)
{
	IFS0bits.T3IF = 0;            // Clear Timer 3 interrupt flag
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
uint16_t genADCSParam(void)
{
    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
	uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
	uint32_t Fcy = Fosc >> 1;
    
    /* ADCS value computation:
     * ADC Clock Period (TADmin) >= TP * (ADCS + 1) = 1/FP * (ADCS + 1)
     * ADCS >= TAD * FP - 1 
     * (int)ADCS = roundUp(TAD * FP) - 1 = TAD * FP
     * 
     * From datasheet: tADmin @12/10 bits mode: 117.6/75 ns
     */
    
    float ADCSval = 0;
    if(AD1CON1bits.AD12B == 1)
    {
        ADCSval= 117.5E-9*Fcy;
    }
    else
    {
        ADCSval = 75.0E-9*Fcy;
    }
    
    return (uint16_t)ADCSval;
}

/* Function to get no of set bits in binary representation of positive integer n
 * (Brian Kernighan's Algorithm implementation)
 */
uint8_t countSetBits(uint16_t val)
{ 
    uint8_t count = 0;
    while (val)
    { 
        val &= (val - 1);
        count++;
    } 
    
    return count;
}

void timer3Init(uint32_t period)
{
	// Configure Timer 3
	uint8_t prescaler = 0;
	uint16_t PRx = 0;
	
	genTimer3PeriodParam(period, &prescaler, &PRx);
	
    IEC0bits.T3IE = 0;  // Disable Timer 2 interrupt
    
	T3CONbits.TON = 0;  // Turn off Timer 3
	T3CON = 0;          // Clear Timer 3 configuration
    
	TMR3 = 0;           // Set Timer 3 start value
    
	T3CONbits.TCKPS = prescaler & 0x03; // Set Timer 3 prescaler (0=1:1, 1=1:8, 2=1:64, 3=1:256)
	PR3 = PRx;                          // Set Timer 3 period (max value is 65535)
    
	T3CONbits.TON = 1;  // Turn on Timer 3
    
    // Interrupt Controller Settings
    IPC2bits.T3IP = 2;  // Set Timer 3 interrupt priority
	IFS0bits.T3IF = 0;  // Clear Timer 3 interrupt flag
	IEC0bits.T3IE = 1;  // Enable Timer 3 interrupt
}

/// @private
void genTimer3PeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx)
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
