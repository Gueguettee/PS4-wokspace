/**
  ****************************************************************************
  * @file    xbee.h
  * @author  Andrea Enrile
  * @date    16.11.2019
  * @brief   Header file for xbee.c with definition of the different functions
 *           prototypes and the definition of UART4 that is reserved to the XBee.
 *           For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _XBEE_H_
#define	_XBEE_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition  */

/******************************************************************************/
/*                       XBEE INITIALIZATION FUNCTION                         */
/******************************************************************************/

/// @brief   Initialize UART4 (xbee comunication))
/// @param   baud value of the desired baud rate
void xbeeInit(uint32_t baud);


/******************************************************************************/
/*                            XBEE USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Send a single char via UART4
/// @param   c Character that must be send
/// @note    This function is created to be used by the UARTSend functions and
///          allows you to send a single char
void xbeeWriteChar(char c);

/// @brief   Read a single char via UART4
/// @return  The char value read from UART Rx buffer
/// @note    This function is created to be used by the UARTRead function and
///          allows you to read a single char.
char xbeeReadChar(void);

/// @brief   Enable interrupts of the XBee
/// @param   rxtx Specifies if this is the reception (eRX) or emission (eTX)
///          interruption
/// @note    This function enables the selected interruption of XBee
void xbeeInterruptEnable(rx_tx_t rxtx);

/// @brief   Disable interrupts of the XBee
/// @param   rxtx Specifies if this is the reception (eRX) or emission (eTX)
///          interruption
/// @note    This function disables the selected interruption of XBee
void xbeeInterruptDisable(rx_tx_t rxtx);

/// @brief   Register callback of interrupt routines function
/// @param   rxtx The communication's direction (eRX->reception and eTX-sending)
/// @param   cbf_pointer Address of the function to register
/// @note    This function allows you to register the XBee interrupt routine by 
///          a callback.
void registerXbeeCallback(rx_tx_t rxtx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
// U4TX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U4TXInterrupt(void);
// U4RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U4RXInterrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Generate the required parameters to get the closest baud rate
/// @param   baud value of the desired baud rate
/// @param   High Baud Rate Enable bit setting (high/Standard-Speed mode)
/// @param   Baud Rate Register value to get the closest baudrate
/// @private
void genXbeeBaudParam(uint32_t baud, uint8_t *BRGH_bit, uint16_t *BRG_val);

#endif	/* _XBEE_H_ */