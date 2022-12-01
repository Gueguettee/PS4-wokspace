/**
  ****************************************************************************
  * @file    clock.h
  * @author  Andrea Enrile
  * @date    14.11.2019
  * @brief   Header file for oscillator.c with definition of functions prototype
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _CLOCK_H_
#define	_CLOCK_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition and device definition */

/******************************************************************************/
/*                    OSCILLATOR INITIALIZATION FUNCTION                      */
/******************************************************************************/

/// @brief   Initialize oscillator at 120 MHz
void clkInit(void);

/******************************************************************************/
/*                         OSCILLATOR USER FUNCTIONS                          */
/******************************************************************************/

/// @brief   Initialize oscillator at user desired frequency
/// @param   M The PLL Feedback Divisor bits
/// @param   N1 The PLL Phase Detector Input Divider Select bits
/// @param   N2 The PLL VCO Output Divider Select bits
/// @note    Fosc = Fin * M/(N1*N2))
void clkUserInit(uint16_t M, uint8_t N1, uint8_t N2);

#endif	/* _CLOCK_H_ */