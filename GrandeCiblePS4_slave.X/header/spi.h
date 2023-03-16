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
/*                           SPI LIBRARY DEFINITION                           */
/******************************************************************************/

// SPI definition
#define _SS2 LATDbits.LATD12
#define _SS3 LATGbits.LATG13

typedef enum{
#ifdef ML180V3
  eSPI2,
#endif
  eSPI3,
  eNbrOfSPI
}spi_t;

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
/// @param   eSPIx SPI you want to initialize
/// @param   SCK3 frequency in kHz
/// @param   Select SPI3 Word/Byte Communication
/// @param   Select SPI3 Data Input Sample Phase
/// @param   Select SPI3 Transmission Mode
/// @note    SPI3 is in master mode
void spiInit(spi_t eSPIx, uint16_t fsck, spiDataLength_t data_length, spiMode_t mode, spiSdiSample_t sdi_sample);

/******************************************************************************/
/*                            SPI3 USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Send a single data via SPI3
/// @param   eSPIx SPI want to use to write data
/// @param   TxData data that is sent
/// @note    This function is created to send a single data
void spiWrite(spi_t eSPIx, uint16_t TxData);

/// @brief   Read a single data via SPI3
/// @param   eSPIx SPI want to use to read data
/// @return  byte/word16 data value read from SPI Rx buffer
/// @note    This function is created to read a single data.
uint16_t spiRead(spi_t eSPIx);

/// @brief   Enable interrupt of the SPI3
/// @param   eSPIx SPI want to set
/// @note    This function enables the interruption of SPI3
void spiInterruptEnable(spi_t eSPIx);

/// @brief   Disable interrupt of the SPI3
/// @param   eSPIx SPI want to set
/// @note    This function disables the interruption of SPI3
void spiInterruptDisable(spi_t eSPIx);

/// @brief   Register callback of interrupt routines function
/// @param   eSPIx SPI want to register
/// @param   cbf_pointer Address of the function to register
/// @note    This function allows you to register the SPI3 interrupt routines by 
///          a callback.
void registerSPIxCallback(spi_t eSPIx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
#ifdef ML180V3
// SPI2 interrupt
void __attribute__((__interrupt__, __auto_psv__)) _SPI2Interrupt(void);
#endif
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