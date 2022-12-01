/******************************************************************************
  * @file    uart.h
  * @author  Andrea Enrile
  * @date    16.11.2019
  * @brief   Header file for uart.c with definition of the different functions
 *           prototypes and the definition of UART2 and UART3. UART1 is not used
 *           on the cible CIBLEPS4 and UART4 is reserved to the XBee.
 *           For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _UART_H_
#define	_UART_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition  */
 
/******************************************************************************/
/*                          UART LIBRARY DEFINITION                           */
/******************************************************************************/

typedef enum{
#ifdef ML180V3
  eUART1,
#endif
  eUART2,
  eUART3,
  eNbrOfUART
}uart_t;

/******************************************************************************/
/*                       UARTs INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   UART Initialization
/// @param   eUARTx UART you want to initialize
/// @note    Initialize an UART
void uartInit(uart_t eUARTx, uint32_t baud);

/******************************************************************************/
/*                            UARTs USER FUNCTIONS                            */
/******************************************************************************/

/// @brief   Send a single char via UART
/// @param   c Character that must be sent
/// @param   eUARTx UART you want to use to send char
/// @note    This function is created to be used by the UARTSend function and
///          allows you to send a single char
void uartWriteChar(uart_t eUARTx, char c);

/// @brief   Read a single char via UART
/// @param   eUARTx UART you want to use to read the char
/// @return  The char value read from UART Rx buffer
/// @note    This function is created to be used by the UARTRead function and
///          allows you to read a single char.
char uartReadChar(uart_t eUARTx);

/// @brief   Enable interrupts of the UART
/// @param   eUARTx UART you want to set
/// @param   rxtx Specifies if this is the reception (eRX) or emission (eTX)
///          interruption
/// @note    This function enables the selected interruption of UART
void uartInterruptEnable(uart_t eUARTx, rx_tx_t rxtx);

/// @brief   Disable interrupts of the UART
/// @param   eUARTx UART you want to Set
/// @param   rxtx Specifies if this is the reception (eRX) or emission (eTX)
///          interruption
/// @note    This function disables the selected interruption of UART
void uartInterruptDisable(uart_t eUARTx, rx_tx_t rxtx);

/// @brief   Register callback of interrupt routines function
/// @param   eUARTx The UART that you want to register
/// @param   rxtx The communication's direction (eRX->reception and eTX-sending)
/// @param   cbf_pointer Address of the function to register
/// @note    This function allows you to register the UART interrupt routines by 
///          a callback.
void registerUARTxCallback(uart_t eUARTx, rx_tx_t rxtx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
#ifdef ML180V3
// U1TX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U1TXInterrupt(void);
// U1RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U1RXInterrupt(void);
#endif
// U2TX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U2TXInterrupt(void);
// U2RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U2RXInterrupt(void);
// U3TX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U3TXInterrupt(void);
// U3RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _U3RXInterrupt(void);


/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Generate the required parameters to get the closest baud rate
/// @param   baud value of the desired baud rate
/// @param   High Baud Rate Enable bit setting (high/Standard-Speed mode)
/// @param   Baud Rate Register value to get the closest baudrate
/// @private
void genUartBaudParam(uint32_t baud, uint8_t *BRGH_bit, uint16_t *BRG_val);

#endif	/* _UART_H_ */