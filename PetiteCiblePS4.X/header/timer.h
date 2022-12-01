/**
  ****************************************************************************
  * @file    timer.h
  * @author  Andrea Enrile
  * @date    14.11.2019
  * @brief   Header file for timer.c with definition of the different functions
 *           prototypes and the definition of 4 timers for doing a 100us, 1ms,
 *           10ms and 100ms timer (timer 4,5,6 and 7 used because pairs of 16-bit
 *           timer). Timers 2, 3, 8 and 9 can be setted by the user if needed.
 *           For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _TIMER_H_
#define	_TIMER_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition and device definition */
 
/******************************************************************************/
/*                          TIMER LIBRARY DEFINITION                          */
/******************************************************************************/
typedef enum {
  eTimer2,
  eTimer3,
  eTimer4,
  eTimer5,
  eTimer6,
  eTimer7,
  eTimer8,
  eTimer9,
  eNbrOfTimer
}timer_t;

/******************************************************************************/
/*                       TIMERs INITIALIZATION FUNCTION                       */
/******************************************************************************/

/// @brief   Initialize Timers 4,5,6 and 7
void timerAllInit(void);

/// @brief   Timer Initialization
/// @param   eTimerx Timer you want to initialize
/// @note    Initialize a Timer
void timerInit(timer_t eTimerx);

/******************************************************************************/
/*                            TIMERs USER FUNCTIONS                           */
/******************************************************************************/

/// @brief   Complete configuration of the Timer
/// @param   eTimerX Timer you want to configure
/// @param   prescaler Timer prescaler value (0=1:1, 1=1:8, 2=1:64, 3=1:256)
/// @param   PRx Period value -> count time = PRx * prescaler * Tcy, Tcy = 1/Fcy
/// @param   enableInterrupt, true to enable interrupt, false to disable
/// @param   priority level value for the IRQ (1 to 7, with 1 the lowest priority)
/// @note    This function allow only the setting of 16-bit timers
void timerConfig(timer_t eTimerX, uint8_t prescaler, uint16_t PRx,
                 bool enableInterrupt, uint8_t priority);

/// @brief   Set the period of the Timer
/// @param   eTimerX Timer you want to set
/// @param   period Period of the counter time in us (if the value is bigger than
///          65535, cast the decimal value as uint32_t or add UL at the end:
///          100000UL or (uint32_t)100000)
/// @note    This function allow only the setting of 16-bit timers
void setTimerPeriod(timer_t eTimerX, uint32_t period);

/// @brief   Enable the Interrupt of the Timer
/// @param   eTimerX Timer you want to Set
/// @note    This function enables the interruption of 16bits timer
void timerInterruptEnable(timer_t eTimerX);

/// @brief   Disable the Interrupt of the Timer
/// @param   eTimerX Timer you want to Set
/// @note    This function disables the interruption of 16bits timer
void timerInterruptDisable(timer_t eTimerX);

/// @brief   Set the priority of the interrupt of the Timer
/// @param   eTimerX Timer you want to set
/// @param   priority level value for the IRQ (1 to 7, with 1 the lowest priority)
/// @note    This function allow only the setting of 16-bit timers.
void setTimerPriority(timer_t eTimerX, uint8_t priority);

/// @brief   Register callback of interrupt routines function
/// @param   eTimerX The timer that you want to regsiter
/// @param   cbf_pointer Adress of the function to register
/// @note    This function allow to register timer interrupt routines by 
///          a callback.
void registerTimerCallback(timer_t eTimerX, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
// Timer2 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T2Interrupt(void);
// Timer3 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T3Interrupt(void);
// Timer4 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T4Interrupt(void);
// Timer5 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T5Interrupt(void);
// Timer6 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T6Interrupt(void);
// Timer7 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T7Interrupt(void);
// Timer8 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T8Interrupt(void);
// Timer9 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _T9Interrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of the prescaler & PRx value based on the period
/// @param   period Value of desired period in us
/// @param   prescaler Value of the prescaler needed to have the specified period.
/// @param   PRx Value of the PRx register needed to have the specified period.
/// @private
void genPeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx);

#endif	/* _TIMER_H_ */