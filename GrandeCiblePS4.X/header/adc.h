/**
  ****************************************************************************
  * @file    adc.h
  * @author  Andrea Enrile & Simone Varischetti
  * @date    20.11.2019
  * @brief   Header file for adc.c with definition of the different function 
  *          prototypes and the definition of ADC1
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _ADC_H_
#define	_ADC_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition  */

/******************************************************************************/
/*                           ADC LIBRARY DEFINITION                           */
/******************************************************************************/

typedef enum{
  b10,
  b12
}resolution_t;

typedef struct {
    uint32_t        period;
    resolution_t    resolution;
} adc_args;

typedef enum{
#ifdef ML180V3
  AN0 = 0x0000,   //PIC pin name: AN0
  AN1 = 0x0001,   //PIC pin name: AN1
  AN2 = 0x0002,   //PIC pin name: AN2
  AN3 = 0x0003,   //PIC pin name: AN3
  AN4 = 0x0004,   //PIC pin name: AN4
  AN5 = 0x0005,   //PIC pin name: AN5
  AN6 = 0x0006,   //PIC pin name: AN6
  AN7 = 0x0007,   //PIC pin name: AN7
  A0  = 0x0008,   //PIC pin name: AN8
  A1  = 0x000B,   //PIC pin name: AN11
  A2  = 0x0018,   //PIC pin name: AN24
  A3  = 0x001C,   //PIC pin name: AN28
  A4  = 0x001E,   //PIC pin name: AN30
  A5  = 0x001F,   //PIC pin name: AN31
#else
#ifdef ML180V2
  AN0 = 0x0005,   //PIC pin name: AN5
  AN1 = 0x0004,   //PIC pin name: AN4
  AN2 = 0x0003,   //PIC pin name: AN3
  AN3 = 0x0002,   //PIC pin name: AN2
  AN4 = 0x0001,   //PIC pin name: AN1
  AN5 = 0x0000,   //PIC pin name: AN0
  AN6 = 0x0018,   //PIC pin name: AN24
  AN7 = 0x001C,   //PIC pin name: AN28
  A0  = 0x000B,   //PIC pin name: AN11
  A1  = 0x0006,   //PIC pin name: AN6
  A2  = 0x0007,   //PIC pin name: AN7
  A3  = 0x0008,   //PIC pin name: AN8
  A4  = 0x001E,   //PIC pin name: AN30
  A5  = 0x001F,   //PIC pin name: AN31
#endif
#endif
}analog_t;

/// @private
typedef struct{
  uint16_t AN0;
  uint16_t AN1;
  uint16_t AN2;
  uint16_t AN3;
  uint16_t AN4;
  uint16_t AN5;
  uint16_t AN6;
  uint16_t AN7;
  uint16_t A0;
  uint16_t A1;
  uint16_t A2;
  uint16_t A3;
  uint16_t A4;
  uint16_t A5;
}analog_read_t;

/******************************************************************************/
/*                        ADC INITIALIZATION FUNCTION                         */
/******************************************************************************/
/// @brief   Initialization of the ADC1
/// @param   period Period in us at which timer3 triggers the ADC conversion
/// @param   resolution ADC Resolution (b10 or b12)
/// @note    - 10/12-bits, unsigned integer format, Vref -> AVdd & AVss,
///            conversion trigger: Timer3. With no parameters: 1000us & 12bits
///            by default; with period only: 12-bits is used by default
///          - Valid function call examples:
///            void adc1Init();
///            void adc1Init(uint32_t period);
///            void adc1Init(uint32_t period, resolution_t adcRes);
///          - e.g. call with default period, but 10 bits resolution:
///            adc1Init(.resolution=b10);
void var_adc1Init(adc_args in);
#define adc1Init(...) var_adc1Init((adc_args){__VA_ARGS__});

//TODO void adc1Start(void);

/******************************************************************************/
/*                             ADC USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Read ADC value of ANx channel
/// @param   ANx AN channel that you want to read
/// @return  return the ADC read value
/// @note    This function allows you to read the ADC value of an AN channel
uint16_t adcChannelRead(analog_t ANx);

/// @brief   Convert ADC value in mV of ANx channel
/// @param   ANx AN channel that you want to read
/// @return  return the ADC read value converted in mV
/// @note    This function allows you to read the value of an AN channel in mV
uint16_t adcChannelReadmV(analog_t ANx);

/// @brief   Enable ADC1 interrupt
/// @note    This function enables the ADC1 interrupt
void adc1InterruptEnable(void);

/// @brief   Disable ADC1 interrupt
/// @note    This function disables the ADC1 interrupt
void adc1InterruptDisable(void);

/// @brief   Register callback of interrupt routine function
/// @param   cbf_pointer Adress of the function to register
/// @note    This function allows you to register the ADC1 routine by a callback
void registerADC1Callback(Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
//ADC1 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _AD1Interrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of ADCx Conversion Clock Select value
/// @return  Returns the value needed for the Conversion Clock Select bits field
/// @private
uint16_t genADCSParam(void);

/// @brief   Counts number of '1' bit(s) of the value passed in parameter
/// @param   val Value in which the number of '1' bit(s) must be counted
/// @return  Returns the number of '1' bit(s) of the value passed as parameter
/// @note    This value can be a word up to 16 bits
/// @private
uint8_t countSetBits(uint16_t val);

/// @brief   Configuration of the timer3 used by the ADC
/// @param   period period at which timer 3 runs
/// @private
void timer3Init(uint32_t period);

/// @brief   Automatic calculation of the prescaler & PRx value based on the period
/// @param   period Value of the desired period in us
/// @param   prescaler Value of the prescaler needed to have the specified period
/// @param   PRx Value of the PRx register needed to have the specified period
/// @private
void genTimer3PeriodParam(uint32_t period, uint8_t *prescaler, uint16_t *PRx);

#endif	/* _ADC_H_ */
