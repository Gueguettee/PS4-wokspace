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
  eNbrOfJoy,
  eJoyNone
}joystick_t;



/******************************************************************************/
/*                                 DEFINITION                                 */
/******************************************************************************/

#define N_STEP_JOY 10   // max 48/2-1
#define JOY1_VALUE 0x30
#define JOY2_VALUE 0x50

#define CHAR_PING 'v'
#define CHAR_PING_OK 'w'

#define CHAR_VERIN 'o'
#define CHAR_BIG_WHEEL 'p'
#define CHAR_MOUNT_BIG_BALL_UP 'q'
#define CHAR_CLAPET 'n'
#define CHAR_MOUNT_BIG_BALL_DOWN 'r'
#define CHAR_F6 's'
#define CHAR_F7 't'
#define CHAR_F8 'u'

#endif	/* _COMDEFINITION_H_ */
