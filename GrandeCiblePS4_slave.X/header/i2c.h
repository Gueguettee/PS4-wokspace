/**
  ****************************************************************************
  * @file    i2c.h
  * @author  Michel Bovet
  * @date    20.04.2020
  * @brief   Header file for i2c.c with definition of the different functions
 *           prototypes and the definition of I2C1 and I2C2.
 *           For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _I2C_H_
#define	_I2C_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition and device definition */

/******************************************************************************/
/*                          I2C LIBRARY DEFINITION                          */
/******************************************************************************/

typedef enum{
  eI2C1,
  eI2C2,
  eNbrOfI2C
} i2c_t;

typedef enum {
    bits7,
    bits10
}i2cAddrLength_t;

typedef struct {
    i2c_t eI2Cx;
    uint16_t fscl;
    i2cAddrLength_t slave_addr_length;
    pullup_on_off_t ePullUp;
} i2c_args;

/******************************************************************************/
/*                        I2Cs INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   Initialization of I2C
/// @param   eI2Cx Select the I2C 
/// @param   SCL1 frequency in kHz
/// @param   Select 7/10 bits slave address
/// @param   pullup [optional] Internal pullup ON/OFF
/// @note    By default, internal pullup are not connected. If they are 
///          connected, I2C module can work at low speed (? 100 kbit/s)
///          - Valid function call examples:
///            void i2cInit(i2c_t eI2Cx, uint16_t fscl, i2cAddrLength_t slave_addr_length);
///            void i2cInit(i2c_t eI2Cx, uint16_t fscl, i2cAddrLength_t slave_addr_length, pullup_on_off_t ePullUp);
void var_i2cInit(i2c_args in);
#define i2cInit(...) var_i2cInit((i2c_args){__VA_ARGS__});

/******************************************************************************/
/*                            I2Cs USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Write out a single data byte to the I2C device
/// @param   data_out - A single data byte to be written to the I2C bus device
/// @param   eI2Cx - I2C you want to use to send a data byte
/// @return  The return value is -1 if there was a write collision else it returns a 0
int8_t masterWriteI2C(i2c_t eI2Cx, uint8_t data_out);

/// @brief   Read a single byte from I2C device
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @return  The return value is the data byte read from the I2C bus device
uint8_t masterReadI2C(i2c_t eI2Cx);

/// @brief   Generates I2C Bus Start condition
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function generates a I2C Bus Start condition.
void startI2C(i2c_t eI2Cx);

/// @brief   Generates I2C Bus Restart condition.
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function generates an I2C Bus Restart condition.
void restartI2C(i2c_t eI2Cx);

/// @brief   Generates I2C Bus Stop condition.
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function generates a I2C Bus Stop condition.
void stopI2C(i2c_t eI2Cx);

/// @brief   Generates I2C bus Acknowledge condition.
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function generates an I2C bus Acknowledge condition
void ackI2C(i2c_t eI2Cx);

/// @brief   Generates I2C bus Not Acknowledge condition during Master Receive.
/// @param   I2Cx - I2C you want to use to receive a data byte
/// @note    This function generates an I2C bus Not Acknowledge condition.
void notAckI2C(i2c_t eI2Cx);

/// @brief   This function generates Wait condition until I2C bus is Idle.
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function will be in a wait state until Start Condition Enable bit,
///          Stop Condition Enable bit, Receive Enable bit, Acknowledge Sequence
///          Enable bit of I2C Control register and Transmit Status bit I2C Status
///          register are clear. The IdleI2C function is required since the hardware
///          I2C peripheral does not allow for spooling of bus sequence. The I2C
///          peripheral must be in Idle state before an I2C operation can be initiated
///          or write collision will be generated.
void idleI2C(i2c_t eI2Cx);

/// @brief   This function provides status back to user if the I2CRCV register
///          contains data.
/// @param   eI2Cx - I2C you want to use to receive a data byte
/// @note    This function determines if there is any byte to read from the
///          I2CRCV register
uint8_t dataRdyI2C(i2c_t eI2Cx);

/// @brief   Enable interrupts of the I2C
/// @param   eI2Cx I2C you want to set
/// @note    This function enables the interruption of the selected I2C
void i2cInterruptEnable(i2c_t eI2Cx);

/// @brief   Disable interrupts of the I2C
/// @param   eI2Cx I2C you want to set
/// @note    This function disables the interruption of the selected I2C
void i2cInterruptDisable(i2c_t eI2Cx);

/// @brief   Register callback of interrupt routines function
/// @param   i2c The I2C that you want to regsiter
/// @param   cbf_pointer Address of the function to register
/// @note    This function allows you to register the I2C interrupt routines by 
///          a callback.
void registerI2CxCallback(i2c_t eI2Cx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
// I2C1interrupt
void __attribute__((__interrupt__, __auto_psv__)) _MI2C1Interrupt(void);
// I2C2interrupt
void __attribute__((__interrupt__, __auto_psv__)) _MI2C2Interrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of baud rate based on the I2C clock frequency
/// @param   Frequency Value of desired serial clock frequency in kHz.
/// @return  Return the value needed to achieve the desired baud rate
/// @private
uint16_t genI2CBaudParam(uint16_t fscl);

#endif	/* _I2C_H_ */