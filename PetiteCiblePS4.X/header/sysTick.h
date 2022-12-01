/**
  ****************************************************************************
  * @file    sysTick.h
  * @author  Andrea Enrile & Simone Varischetti
  * @date    20.11.2019
  * @brief   Header file for sysTick.c with definition of the prototype needed.
  *          For the generation of the sysTick, Timer1 is used.
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SYSTICK_H_
#define	_SYSTICK_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition and device definition */

/******************************************************************************/
/*                              EXTERNAL VARIABLE                             */
/******************************************************************************/
extern uint8_t sysTickFlag;

/******************************************************************************/
/*                       SYSTICK INITIALIZATION FUNCTION                      */
/******************************************************************************/

/// @brief  Initialize sysTick at 1ms period
/// @note   
void sysTickInitDflt(void);

/// @brief  Initialize sysTick at the spercified period
/// @param  period time of the sysTick in us
/// @note   If the value is bigger than 65535, cast the decimal value as
///         uint32_t or add UL at the end: 100000UL or (uint32_t)100000
void sysTickInit(uint32_t period);

/******************************************************************************/
/*                           SYSTICK USER FUNCTIONS                           */
/******************************************************************************/

/// @brief  Change the sysTick period
/// @param  period time of the sysTick in us
/// @note   If the value is bigger than 65535, cast the decimal value as
///         uint32_t or add UL at the end: 100000UL or (uint32_t)100000
void sysTickPeriod(uint32_t period);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/

//sysTick interrupt (T1 used for the sysTick)
void __attribute__((__interrupt__, __auto_psv__)) _T1Interrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of the prescaler & PRx value based on the period
/// @param   period Value of desired period in us
/// @param   prescaler Value of the prescaler needed to have the specified period.
/// @param   PRx Value of the PRx register needed to have the specified period.
/// @private
void genSysTickPeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx);

#endif	/* _SYSTICK_H_ */