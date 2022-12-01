/**
  ****************************************************************************
  * @file    clock.c
  * @author  Andrea Enrile
  * @date    19.11.2019
  * @brief   Clock initialization file, if the user need to use a specific
  *          clock frequency, simply change the value of M, N1 and N2
  *          Fosc = Fin*M/(N1*N2); Fcy = Fosc/2
  *          Oscillator configuration example to operate the device at fosc = 120MHz
  *          Fosc = 7.37MHz*65/(2*2) = 120MHz with 7.37MHz input clock (FRC oscillator)
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "clock.h"

/******************************************************************************/
/*             OSCILLATOR INITIALIZATION FUNCTION Inplementation              */
/******************************************************************************/

void clkInit(void) 
{
	// Configure Oscillator to operate the device at 60MHz
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	// Fosc= 7.37*65/(2*2)=120Mhz for 7.37 input clock
	PLLFBD = 63;                // M=65
	CLKDIVbits.PLLPOST = 0;     // N1=2 
	CLKDIVbits.PLLPRE = 0;      // N2=2
	OSCTUN = 0b00000;           // Tune FRC oscillator, if FRC is used
    
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
	__builtin_write_OSCCONH(0x01);
	__builtin_write_OSCCONL(OSCCON || 0x01);  // Start clock switching
    
    // Wait for Clock switch to occur
	while(OSCCONbits.COSC != 0b001);
    
    // Wait for PLL to lock
	while(OSCCONbits.LOCK != 1);
}

/******************************************************************************/
/*                  OSCILLATOR USER FUNCTIONS Inplementation                  */
/******************************************************************************/

void clkUserInit(uint16_t M, uint8_t N1, uint8_t N2) 
{
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	PLLFBD = M - 2;
	CLKDIVbits.PLLPOST = (N1/2) - 1;
	CLKDIVbits.PLLPRE = N2 - 2;
	OSCTUN = 0b00000;           // Tune FRC oscillator, if FRC is used
    
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
	__builtin_write_OSCCONH(0x01);
	__builtin_write_OSCCONL(OSCCON || 0x0);  // Start clock switching
    
    // Wait for Clock switch to occur
	while(OSCCONbits.COSC != 0b001);

    // Wait for PLL to lock
	while(OSCCONbits.LOCK != 1);
}