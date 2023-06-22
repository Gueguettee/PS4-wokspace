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

#define ML180V3         /* Define the board used. Possible values are ML180V3 */
                        /*                                            ML180V2 */

#include <assert.h>        /* Include assert definition                       */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stddef.h>        /* Includes NULL Pointer definition                */
#include <stdbool.h>       /* Includes true/false definition                  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief   Pointer definition for callback of interrupt
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

typedef enum{
    eVerinPull,
    eVerinNotPull,
    eVerinInTransitionToPull,
    eVerinInTransitionToNotPull
}verinState_t;

// User definitions types
typedef int8_t joyspeed_t;

// Temp system loop
#define SYS_LOOP 10

// General Interrupt Enable/Disable Macro
#define _GENERAL_INTERRUPT_ENABLED_  INTCON2bits.GIE = 1
#define _GENERAL_INTERRUPT_DISABLED_ INTCON2bits.GIE = 0

// States
#define WAIT_CONNECTION 0
#define RUN 1

// Servomoteurs (min 0.5ms, middle 1.5 ms, max 2.5ms, f=50Hz)
#define SERVO_MAX_DUTY_ON 1250
#define SERVO_MIDDLE_DUTY_ON 750
#define SERVO_MIN_DUTY_ON 240   //250
#define SERVO_GAP_DUTY_ON 500

#define SERVO_FREQ 50

#define DC_FREQ 10000

// Times
#define TIME_BIG_WHEEL 10000

// Bit direction definition
#define INPUT  1
#define OUTPUT 0

// Output/Input level definition
#define HIGH 1
#define LOW  0

// Enable/disable definition
#define ENABLE  1
#define DISABLE 0

/* Port mask definition */
// PORTA
#define pinRA7  0x0080  // I/O only if PWM4L or JTAG TDI is not used
#define pinRA8  0x0100  // I/O only if I2C2 is not used (I2C2CONbits.I2CEN = 0)
#define pinRA10 0x0400  // I/O only if PWM4H or JTAG TDO is not used
#define pinRA11 0x0800  // I/O only if INT1 is not used
#define pinRA12 0x1000  // I/O only if INT2 is not used
#define pinRA14 0x4000  // I/O only if INT3 is not used
#define pinRA15 0x8000  // I/O only if INT4 is not used

// PORTB
#define pinRB4  0x0010  // I/O only if I2C2 is not used (I2C2CONbits.I2CEN = 0)
#define pinRB7  0x0080  // I/O only if INT0 is not used
#define pinRB8  0x0100  // I/O only if JTAG TCK is not used
#define pinRB9  0x0200  // I/O only if JTAG TMS is not used
#define pinRB10 0x0400  // I/O only if PWM3H or SDO3 (OUT PPS) is not used
#define pinRB11 0x0800  // I/O only if PWM3L is not used
#define pinRB12 0x1000  // I/O only if PWM2H is not used
#define pinRB13 0x2000  // I/O only if PWM2L is not used
#define pinRB14 0x4000  // I/O only if PWM1H or INT1 is not used
#define pinRB15 0x8000  // I/O only if PWM1L is not used

// PORTC
#define pinRC3  0x0008  // Output only (LED dedicated) 
#define pinRC4  0x0010  // I/O only if I2C1 is not used (I2C1CONbits.I2CEN = 0)
#define pinRC5  0x0020  // I/O only if I2C1 is not used (I2C1CONbits.I2CEN = 0)
#define pinRC6  0x0040  // I/O only if CAN1 is not used
#define pinRC7  0x0080  // I/O only if CAN1 is not used
#define pinRC8  0x0100  // I/O only if CAN2 is not used
#define pinRC9  0x0200  // I/O only if CAN2 is not used
#define pinRC10 0x0400  // Output only (LED dedicated) 

// PORTD
#define pinRD1  0x0002  // I/O only if PWM5L is not used
#define pinRD2  0x0004  // I/O only if PWM5H is not used
#define pinRD3  0x0008  // I/O only if PWM6L is not used
#define pinRD4  0x0010  // I/O only if PWM6H is not used
#define pinRD5  0x0020
#define pinRD6  0x0040
#define pinRD8  0x0100
#define pinRD12 0x1000
#define pinRD13 0x2000
#define pinRD14 0x4000
#define pinRD15 0x8000

// PORTE
#define pinRE1  0x0002  // I/O only if U2TX (OUT PPS) is not used and USB/UART not used
#define pinRE8  0x0100
#define pinRE9  0x0200
#define pinRE13 0x2000  // I/O only if _U2RTS (OUT PPS) is not used and USB/UART not used
#define pinRE14 0x4000
#define pinRE15 0x8000

// PORTF
#define pinRF0  0x0001  // I/O only if RF0 is not XBEE (X1) dedicated and not set as U4RX (IN PPS)
#define pinRF1  0x0002  // I/O only if RF1 is not XBEE (X1) dedicated and not set as U4TX (OUT PPS)
#define pinRF4  0x0010
#define pinRF5  0x0020
#define pinRF6  0x0040
#define pinRF7  0x0080
#define pinRF12 0x1000
#define pinRF13 0x2000

// PORTG
#define pinRG0  0x0001  // I/O only if U3RX (IN PPS) is not used and no jumper in J17
#define pinRG1  0x0002  // I/O only if U3TX (OUT PPS) is not used and no jumper in J17
#define pinRG2  0x0004
#define pinRG3  0x0008
#define pinRG6  0x0040  // I/O only if _U3RTS (OUT PPS) is not used
#define pinRG7  0x0080
#define pinRG8  0x0100
#define pinRG9  0x0200  // I/O only if _U3CTS (IN PPS) is not used
#define pinRG10 0x0400
#define pinRG11 0x0800
#define pinRG12 0x1000  // I/O only if SDI3 (IN PPS) is not used
#define pinRG13 0x2000  // I/O only if _SS3 (OUT) is not used
#define pinRG14 0x4000  // I/O only if SCK3 (OUT PPS) is not used
#define pinRG15 0x8000

#endif	/* _DEFINITION_H_ */