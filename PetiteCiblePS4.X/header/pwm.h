/**
  ****************************************************************************
  * @file    pwm.h
  * @author  Andrea Enrile
  * @date    25.11.2019
  * @brief   Header file for pwm.c with definition of the different functions
  *          prototype and pwm definitions. Only complementary mode is avaiable
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _PWM_H_
#define	_PWM_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition  */

/******************************************************************************/
/*                           PWM LIBRARY DEFINITION                           */
/******************************************************************************/
#define DEFAULTFPRIMARYPWM   20000 // Definition of the default PWM frequency 
                                   // using Primary Time Base in Hz
#define DEFAULTFSECONDARYPWM 333   // Definition of the default PWM frequency 
                                   // using Secondary Time Base in Hz

typedef enum {
  ePWM2,
  ePWM4,
  NbrOfPWM
}pwm_t;

typedef enum {
  ePWMPrimaryTimeBase,
  ePWMSecondaryTimeBase,
  NbrOfPWMTimeBasePeriod
}pwmPER_t;

/******************************************************************************/
/*                        PWMs INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   Initialization of all 6 PWMs
void pwmAllInit(void);

/// @brief   PWM Initialization
/// @param   ePWMx PWM you want to initialize
/// @param   exPER Time base you want to use
void pwmInit(pwm_t ePWMx, pwmPER_t exPER);

/******************************************************************************/
/*                            PWMs USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Set the PWM module frequency
/// @param   pwmFreq PWM frequency for all PWM
/// @param   exPER Time base you want to use
void setPwmFreq(uint16_t pwmFreq, pwmPER_t exPER);

/// @brief   Set the phase shift for the PWMx
/// @param   ePWMx PWM that must be set
/// @param   phase Phase shift in [0...359]° for the PWMx
void setPwmPhase(pwm_t ePWMx, uint8_t phase);

/// @brief   Set the desired dead time for the PWMx
/// @param   ePWMx PWM that must be set
/// @param   DT Dead Time value in ns for the PWMx
/// @note    Do not modify the dead time unless you know what you are doing as
///          it can cause damage on the HW (ex. short circuit on the H-bridge)
///          Max valid value is 65535 ns
void setPwmDeadTime(pwm_t ePWMx, uint16_t DT);

/// @brief   Set the desired duty cycles for the PWMx
/// @param   ePWMx PWM that must be set
/// @param   DC Duty Cycle value [0... 10000] for the PWMx (corresponding to 0.00% ... 100.00%)
/// @note    The duty cycle is set for the PWMxH.
///          For more details see the CIBLEPS4 Software documentation 
void setPwmDuty(pwm_t ePWMx, uint16_t DC);

/// @brief   Enable PWMx
/// @param   ePWMx PWM that is enabled
void pwmEnable(pwm_t ePWMx);

/// @brief   Disable PWMx
/// @param   ePWMx PWM that is disabled
void pwmDisable(pwm_t ePWMx);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/
/// @brief   Automatic calculation of the PTPER and prescaler value based on the PWM frequency
/// @param   PWMFreq Value of the desired frequency
/// @param   prescaler pointer to the value of the prescaler
/// @param   PTPERValue pointer to the value of the PTPER
/// @private
void genPWMParameter(uint16_t PWMFreq, uint8_t *prescaler, uint16_t *PTPERValue);

/// @brief   Automatic calculation of the DTRx register value based on the given Dead time in ns
/// @param   exPER The Time Base used
/// @param   DT Dead Time value in ns
/// @param   DTValue pointer to the value of the Dead Time register
/// @private
void genDTParameter(pwmPER_t exPER, uint16_t DT, uint16_t *DTValue);

/// @brief   Automatic calculation of the Fosc value
/// @private
void genOscFreq(void);

/// @brief   Check if PWMx using the Primary Time Base
/// @return  boolean as true if the PWMx using the Primary Time Base
/// @param   ePWMx PWM that is checked
/// @private
bool pwmCheckPrimaryTimeBase(pwm_t ePWMx);

#endif	/* _PWM_H_ */