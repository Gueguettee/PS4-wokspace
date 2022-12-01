/**
  ****************************************************************************
  * @file    can.h
  * @author  Lucas Froidevaux
  * @date    13.04.2021
  * @brief   Header file for can.c with definition of the different functions
 *           prototypes and the definition of CAN1 and CAN2.
 * 
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef _CAN_H_
#define	_CAN_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
/* Includes INPUT/OUTPUT and bits name definition and device definition */
#include "definition.h"

/******************************************************************************/
/*                          CAN LIBRARY DEFINITION                            */
/******************************************************************************/

#define NUM_OF_CAN_BUFFERS 32

typedef enum{
    eCAN1,
    eCAN2,
    eNbrOfCAN
}can_t;

typedef enum{
    bits11,
    bits29
}canIdLength_t;

typedef struct{
    uint32_t baud_rate;
    canIdLength_t idLength;
}canParam_t;

typedef union{
    struct{
        /* Word 0 */
        unsigned int IDE    :1;
        unsigned int SRR    :1;
        unsigned int SIDlo  :6;
        unsigned int SIDhi  :5;
        unsigned int        :3;

        /* Word 1 */
        unsigned int EIDmi  :8;
        unsigned int EIDhi  :4;
        unsigned int        :4;

        /* Word 2 */
        unsigned int DLC    :4;
        unsigned int RB0    :1;
        unsigned int        :3;
        unsigned int RB1    :1;
        unsigned int RTR    :1;
        unsigned int EIDlo  :6;

        /* Word 3 */
        unsigned int Byte0  :8;
        unsigned int Byte1  :8;

        /* Word 4 */
        unsigned int Byte2  :8;
        unsigned int Byte3  :8;

        /* Word 5 */
        unsigned int Byte4  :8;
        unsigned int Byte5  :8;

        /* Word 6 */
        unsigned int Byte6  :8;
        unsigned int Byte7  :8;

        /* Word 7 */
        unsigned int        :8;
        unsigned int FILHIT :5;
        unsigned int        :3;
    };
    uint8_t byteBuff[16];
}canMessageBuffer;

typedef canMessageBuffer buffer_t[NUM_OF_CAN_BUFFERS]
__attribute__((aligned(NUM_OF_CAN_BUFFERS * 16)));

/******************************************************************************/
/*                        CANs INITIALIZATION FUNCTION                        */
/******************************************************************************/

/// @brief   CAN Initialization
/// @param   eCANx CAN you want to initialize
/// @param   baud_rate data transfer speed
/// @param   idLength SID or EID frame format (bits11 resp. bits29)
/// @note    Initialize a CAN controller and its two associated DMA channels
void canInit(can_t eCANx, uint32_t baud_rate, canIdLength_t idLength);

/******************************************************************************/
/*                            CANs USER FUNCTIONS                             */
/******************************************************************************/

/// @brief   Send a data frame via CAN
/// @param   eCANx CAN you want to use to send frame
/// @param   ID frame identifier
/// @param   dataLength length of the data field (0-8 bytes)
/// @param   msg data field
/// @note    This function is created to allow to send a data frame
void canWriteData(can_t eCANx, uint32_t ID, uint8_t dataLength, uint8_t* msg);

/// @brief   Send a remote frame via CAN
/// @param   eCANx CAN you want to use to send frame
/// @param   ID frame identifier
/// @param   dataLength length of the expected data (0-8 bytes)
/// @note    This function is created to allow to send a remote frame
void canWriteRemote(can_t eCANx, uint32_t ID, uint8_t dataLength);

/// @brief   Read the most recent receive buffer
/// @param   eCANx from which CAN you want to read the receive buffer
/// @return  byte array containing the receive buffer
/// @note    This function is created to allow to read the last receive buffer
///          as stored in the device RAM
uint8_t* canReadData(can_t eCANx);

/// @brief   Enable interrupts of the CAN
/// @param   eCANx CAN you want to set
/// @note    This function enables the interruption of CAN
void canInterruptEnable(can_t eCANx);

/// @brief   Disable interrupts of the CAN
/// @param   eCANx CAN you want to set
/// @note    This function disables the interruption of CAN
void canInterruptDisable(can_t eCANx);

/// @brief   Register callback of interrupt routines function
/// @param   eCANx the CAN that you want to register
/// @param   cbf_pointer Address of the function to register
/// @note    This function allow to register the CAN interrupt routines by 
///          a callback.
void registerCANxCallback(can_t eCANx, Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/

// CAN1 RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _DMA1Interrupt(void);
// CAN2 RX interrupt
void __attribute__((__interrupt__, __auto_psv__)) _DMA3Interrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/

/// @brief   Automatic calculation of baud rate based on the CAN clock frequency
/// @param   Fbaud Value of desired baud rate in kHz.
/// @param   bestBRPVAL BRP value needed to have the specified baud rate.
/// @param   bestNTQ Number of Time Quanta needed to have the specified baud rate.
/// @param   bestMULT Clock Divider value needed to have the specified baud rate.
/// @private
void genCANBaudParam(uint32_t Fbaud, uint8_t *bestBRPVAL, uint8_t *bestNTQ, uint8_t *bestMULT);

#endif	/* _CAN_H */
