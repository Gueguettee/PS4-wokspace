/**
  ****************************************************************************
  * @file    spi.h
  * @author  Michel Bovet
  * @date    27.02.2020
  * @brief   Header file for spi.c with definition of the different functions
 *           prototypes and the definition of SPI3.
 *           For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SPI_H_
#define	_SPI_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "definition.h"    /* Includes INPUT/OUTPUT and bits name definition and device definition */

/******************************************************************************/
/*                          SPI LIBRARY DEFINITION                          */
/******************************************************************************/

// SPI definition
#define _SS3 LATGbits.LATG13

typedef enum {
    byte8,
    word16
}spiDataLength_t;

typedef enum {
    RxEnd,
    RxMiddle
}spiSdiSample_t;

typedef enum {
    TxMode0,
    TxMode1,
    TxMode2,
    TxMode3
}spiMode_t;

/******************************************************************************/
/*                        SPI3 INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   Initialize SPI 3
/// @param   SCK3 frequency in kHz
/// @param   Select SPI3 Word/Byte Communication
/// @param   Select SPI3 Data Input Sample Phase
/// @param   Select SPI3 Transmission Mode
/// @note    SPI3 is in master mode
void spi3Init(uint16_t fsck, spiDataLength_t data_length, spiMode_t mode, spiSdiSample_t sdi_sample);

/******************************************************************************/
/*                            SPI3 USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Send a single data via SPI3
/// @param   TxData data that is sent
/// @note    This function is created to allow to send a single data
void spi3Write(uint16_t TxData);

/// @brief   Read a single data via SPI3
/// @return  byte/word16 data value read from SPI Rx buffer
/// @note    This function is created to allow to read a single data.
uint16_t spi3Read(void);

/// @brief   Enable interrupt of the SPI3
/// @note    This function enables the interruption of SPI3
void spi3InterruptEnable(void);

/// @brief   Disable interrupt of the SPI3
/// @note    This function disables the interruption of SPI3
void spi3InterruptDisable(void);

/// @brief   Register callback of interrupt routines function
/// @param   cbf_pointer Adress of the function to register
/// @note    This function allow to register the SPI3 interrupt routines by 
///          a callback.
void registerSPI3Callback(Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/

// SPI3 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _SPI3Interrupt(void);


/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of primary & secondary prescaler based on the SPI clock frequency
/// @param   Frequency Value of desired serial clock frequency in kHz.
/// @param   Primary Prescale bits Value needed to have the specified serial clock frequency.
/// @param   Secondary Prescale bits Value needed to have the specified serial clock frequency.
/// @private
void genSpiPrescaleParam(uint16_t fsck, uint8_t *pprescale, uint8_t *sprescale);

#endif	/* _SPI_H_ */