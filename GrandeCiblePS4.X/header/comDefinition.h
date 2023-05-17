/**
  ****************************************************************************
  * @file    comDefinition.h
  * @author  Gaetan Jenni
  * @date    08.03.2023
  * @brief   Header file for gpio.c with definition of the different PORT bits
  *          name, PORT name and definition of the different function prototypes
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _COMDEFINITION_H_
#define	_COMDEFINITION_H_

/******************************************************************************/
/*                                TYPEDEF ENUM                                */
/******************************************************************************/

/// @brief   Enumerate for joysticks X/Y
typedef enum{
  eJoyX,
  eJoyY,
  eNbrOfJoy
}joystick_t;

/******************************************************************************/
/*                                 DEFINITION                                 */
/******************************************************************************/

#define N_STEP_JOY 30   // max (128-1)/2 = 63

#define CHAR_PING 'v'
#define CHAR_PING_OK 'w'

#define CHAR_BUTTON_4 'n'

#define CHAR_VERIN 'o'
#define CHAR_BIG_WHEEL 'p'
#define CHAR_MOUNT_BIG_BALL 'q'

#endif	/* _COMDEFINITION_H_ */
