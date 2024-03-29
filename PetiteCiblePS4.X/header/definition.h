/**
  ****************************************************************************
  * @file    definition.h
  * @author  Andrea Enrile
  * @date    14.11.2019
  * @brief   Header file that include device header file and general definition.
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEFINITION_H_
#define	_DEFINITION_H_

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif  

#include <assert.h>        /* Include assert definition                       */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stddef.h>        /* Includes NULL Pointer definition                */
#include <stdbool.h>       /* Includes true/false definition                  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// @brief   Pointer definition for for callback of interrupt
typedef void (*Callback_t)(void);

/// @brief   Enumerate for direction of serial communication
typedef enum{
  eRX,
  eTX,
}rx_tx_t;

/// @brief   Enumerate for internal pullup ON/OFF
typedef enum{
  ePullUpOn,
  ePullUpOff,
}pullup_on_off_t;

// User definitions types
typedef uint16_t joySpeed_t;

// Temp system loop
#define SYS_LOOP 10

// General Interrupt Enable/Disable Macro
#define _GENERAL_INTERRUPT_ENABLED_  INTCON2bits.GIE = 1
#define _GENERAL_INTERRUPT_DISABLED_ INTCON2bits.GIE = 0

// States
#define WAIT_CONNECTION 0
#define RUN 1

// Extremes values of the joystick
#define MAX_VALUE_JOY 1537
#define MIN_VALUE_JOY 527

// Bit direction definition
#define INPUT  1
#define OUTPUT 0

// Output/Input level definition
#define HIGH 1
#define LOW  0

#define STATE_BUTTON_ON 1
#define STATE_BUTTON_OFF 0

// Enable/disable definition
#define ENABLE  1
#define DISABLE 0

/* Port mask definition */
// PORTA
#define pinRA7  0x0080  // I/O only if PWM4L or JTAG TDI is not used
#define pinRA8  0x0100  // I/O only if I2C2 is not used (I2C2CONbits.I2CEN = 0)
#define pinRA10 0x0400  // I/O only if PWM4H or JTAG TDO is not used
#define pinRA12 0x1000  // I/O only if INT2 is not used
#define pinRA14 0x4000  // I/O only if INT3 is not used
#define pinRA15 0x8000  // I/O only if INT4 is not used

// PORTB
#define pinRB4  0x0010  // I/O only if I2C2 is not used (I2C2CONbits.I2CEN = 0)
#define pinRB7  0x0080  // I/O only if INT0 is not used
#define pinRB8  0x0100  // I/O only if JTAG TCK is not used
#define pinRB9  0x0200  // I/O only if JTAG TMS is not used
#define pinRB10 0x0400  // I/O only if SDO3 (OUT PPS) is not used
#define pinRB11 0x0800
#define pinRB12 0x1000  // I/O only if PWM2H is not used
#define pinRB13 0x2000  // I/O only if PWM2L is not used
#define pinRB14 0x4000  // I/O only if INT1 is not used
#define pinRB15 0x8000

// PORTC
#define pinRC3  0x0008  // Output only (LED dedicated)
#define pinRC6  0x0040  // I/O only if _U3RTS (OUT PPS) is not used
#define pinRC7  0x0080  // I/O only if _U3CTS (IN PPS) is not used
#define pinRC10 0x0400  // Output only (LED dedicated)

// PORTD
#define pinRD1  0x0002
#define pinRD2  0x0004
#define pinRD3  0x0008
#define pinRD4  0x0010
#define pinRD5  0x0020
#define pinRD6  0x0040
#define pinRD12 0x1000
#define pinRD13 0x2000
#define pinRD14 0x4000
#define pinRD15 0x8000

// PORTE
#define pinRE8  0x0100
#define pinRE9  0x0200
#define pinRE14 0x4000
#define pinRE15 0x8000

// PORTF

// PORTG
#define pinRG0  0x0001  // I/O only if U3RX (IN PPS) is not used
#define pinRG1  0x0002  // I/O only if U3TX (OUT PPS) is not used
#define pinRG7  0x0080
#define pinRG8  0x0100
#define pinRG11 0x0800
#define pinRG12 0x1000  // I/O only if SDI3 (IN PPS) is not used
#define pinRG13 0x2000  // I/O only if _SS3 (OUT) is not used
#define pinRG14 0x4000  // I/O only if SCK3 (OUT PPS) is not used
#define pinRG15 0x8000

#endif	/* _DEFINITION_H_ */