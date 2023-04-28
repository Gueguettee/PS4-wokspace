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
  eJoyX=0,
  eJoyY=1,
  eNbrOfJoy=2
}joystick_t;

/******************************************************************************/
/*                                 DEFINITION                                 */
/******************************************************************************/

#define N_STEP_JOYSTICK 17   //plus petit que (9 + Z)/2

#define CHAR_PING 'v'
#define CHAR_PING_OK 'w'

#define CHAR_JOYSTICK_X 'x'
#define CHAR_JOYSTICK_Y 'y'

#define CHAR_BUTTON_1 'l'
#define CHAR_BUTTON_2 'm'
#define CHAR_BUTTON_3 'n'
#define CHAR_BUTTON_4 'o'

#define CHAR_BIG_WHEEL 'p'
#define CHAR_MOUNT_BIG_BALL 'q'

#endif	/* _COMDEFINITION_H_ */
