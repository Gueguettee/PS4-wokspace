/**
  ****************************************************************************
  * @file    gpio.h
  * @author  Andrea Enrile
  * @date    13.11.2019
  * @brief   Header file for gpio.c with definition of the different PORT bits
  *          name, PORT name and definition of the different function prototypes
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _GPIO_H_
#define	_GPIO_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition  */

/******************************************************************************/
/*                           GPIO LIBRARY DEFINITION                          */
/******************************************************************************/
typedef enum {
  ePORTA,
  ePORTB,
  ePORTC,
  ePORTD,
  ePORTE,
  ePORTF,
  ePORTG, 
  eNbrOfPORT
}port_t;

typedef enum {
  eRisingEdge = 0,
  eFallingEdge = 1,
  eNbrOfEdgeSelection
}edge_t;

typedef enum {
  eINT0,
  eINT1,
  eINT2,
  eINT3,
  eINT4,
  eNbrOfINT
}extINT_t;

/******************************************************************************/
/*                        GPIO INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   GPIO Initialization
/// @note    Set all I/Os as inputs by default, except 2 dedicated outputs LEDs
void gpioInit(void);

/******************************************************************************/
/*                            GPIO USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Read from the whole GPIO PORT
/// @param   ePORTx Port from which you want to read
/// @return  The whole PORT bits read value
/// @note    Allows you to read an entire port
uint16_t gpioPortRead(port_t ePORTx);

/// @brief   Read single bit from a GPIO PORT
/// @param   ePORTx Port from which you want to read
/// @param   BIT Bit that you want to read
/// @return  The PORT bit read value
/// @note    Simplified version of gpioRead() to read a single bit
bool gpioBitRead(port_t ePORTx, uint16_t BIT);

/// @brief   Read from the selected GPIO PORT bit(s)
/// @param   ePORTx Port from which you want to read
/// @param   BIT bit(s) that you want to read
/// @return  The GPIO PORT bit(s) read value
/// @note    It's possible to read more than 1 bit at a time. Example of multi-
///          bits read: valueRead = gpioRead(ePORTA, (pinRA11|pinRA12|pinRA14));
uint16_t gpioRead(port_t ePORTx, uint16_t BITs);

/// @brief   Write to the whole GPIO PORT
/// @param   ePORTx Port to which you want to write
/// @param   value Value that the port is going to have
/// @return  true if successful, false if failed
/// @note    This function allows you to write an entire Port (be aware that
///          this function overwrites the entire LATx register)
bool gpioPortWrite(port_t ePORTx, uint16_t value);

/// @brief   Write to the selected GPIO PORT bit(s)
/// @param   ePORTx Port to which you want to write
/// @param   BIT Bit(s) that you want to overwrite
/// @param   value Value that the bit is going to have
/// @return  true if successful, false if failed
/// @note    It's possible to write more than 1 bit at a time at the condition
///          that they have the same value. Example of multi-bit write:
///          gpioWrite(ePORTA, (pinRA11|pinRA12|pinRA14), HIGH);
bool gpioBitWrite(port_t ePORTx, uint16_t BIT, uint16_t value);

/// @brief   Configure the whole GPIO PORT TRISx register
/// @param   ePORTx Port you want to configure
/// @param   value Value to assign to the TRISx register
/// @return  true if successful, false if failed
/// @note    This function allows you to configure an entire Port (be aware
///          that this function overwrites the entire TRISx register)
bool gpioPortConfig(port_t ePORTx, uint16_t value);

/// @brief   Configure the selected GPIO PORT bit(s) direction
/// @param   ePORTx Port whose direction you want to configure
/// @param   BIT Bit you want to configure
/// @param   direction Direction of the bit -> Input or Output
/// @return  true if successful, false if failed
/// @note    It's possible to configure more than 1 bit at a time. Example of
///          multi-bits config: gpioBitConfig(ePORTA, (pinRA11|pinRA12|pinRA14), INPUT);
bool gpioBitConfig(port_t ePORTx, uint16_t BIT, uint16_t direction);

/// @brief   Configuration of GPIO External interrupt
/// @param   eINTx INTx that you want to activate
/// @param   edgeSelect Lets you choose if INTx occurs on the rising or falling edge
/// @note    This function allows you to enable any INTx. For INT1 and INT2
///          there is a remapping to the pin pinRA11 and pinRA12
void externInterruptInit(uint16_t eINTx, edge_t edgeSelect);

/// @brief   Enable External interrupt
/// @param   eINTx INTx that you want to activate
/// @note    This function enables INTx.
void externInterruptEnable(extINT_t eINTx);

/// @brief   Disable External interrupt
/// @param   eINTx INTx that you want to activate
/// @note    This function disables INTx.
void externInterruptDisable(extINT_t eINTx);

/// @brief   Register callback of interrupt routines function
/// @param   intx intx that you want to regsiter
/// @param   cbf_pointer Address of the function to register
/// @note    This function allows you to register all external interrupt
///          routines by a callback.
void registerExternCallback(extINT_t intx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
// INT0 interrupt
void __attribute__ ( (__interrupt__) )  _INT0Interrupt( void );
// INT1 interrupt
void __attribute__ ( (__interrupt__) )  _INT1Interrupt( void );
// INT2 interrupt
void __attribute__ ( (__interrupt__) )  _INT2Interrupt( void );
// INT3 interrupt
void __attribute__ ( (__interrupt__) )  _INT3Interrupt( void );
// INT4 interrupt
void __attribute__ ( (__interrupt__) )  _INT4Interrupt( void );

#endif	/* _GPIO_H_ */