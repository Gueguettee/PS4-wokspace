/**
  ****************************************************************************
  * @file    can.h
  * @author  Martin Marguerat
  * @date    08.04.2022
  * @brief   Header file for rtc.c with definition of the different functions
 *           prototypes and the definition of RTCC.
 * 
  ****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef _RTC_H_
#define	_RTC_H_

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
/* Includes INPUT/OUTPUT and bits name definition and device definition */
#include "definition.h"

/******************************************************************************/
/*                          RTC LIBRARY DEFINITION                            */
/******************************************************************************/
typedef enum {
    monday = 0,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
}weekday_t;

typedef enum {
    eTime,
    eAlarm
}rtctype_t;

typedef enum {
    eHalfSec = 0,   // Every half second
    eSec,           // Every second
    e10Sec,         // Every 10 seconds
    eMin,           // Every minute
    e10Min,         // Every 10 minutes
    eHour,          // Every hour
    eDay,           // Once a day
    eWeek,          // Once a week
    eMonth,         // Once a month
    eYear           // Once a year (when February 29, once every 4 years)
}alarmmask_t;

typedef struct {
    uint8_t year;   // between 0 and 99 for years from 2000 to 2099
    uint8_t month;
    weekday_t weekday;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}time_t;

/******************************************************************************/
/*                         RTC INITIALIZATION FUNCTION                        */
/******************************************************************************/
/// @brief   RTC Initialization
/// @note    Initialize the internal RTC
void rtcInit(void);

/******************************************************************************/
/*                             RTC USER FUNCTIONS                             */
/******************************************************************************/
/// @brief   RTC Write time to RTC registers
/// @param   time time you want to set
/// @note    This function is created to allow setting time
void rtcWriteTime(time_t time);

/// @brief   RTC Write Alarm to RTC registers
/// @param   time alarm's date and time
/// @param   mask alarm's frequency
/// @param   chime allow or disallow roll over of ARPT<7:0>
/// @note    This function is created to allow alarm configuration
void rtcWriteAlarm(time_t time, alarmmask_t mask, bool chime);

/// @brief   RTC Read time from RTC registers
/// @return  time in the RTC registers
/// @param   type choose between time read or alarm read
/// @note    This function is created to allow time or alarm read
time_t rtcRead(rtctype_t type);

/// @brief   Enable alarm of the RTC
/// @note    This function enables the alarm of RTC
void rtcAlarmEnable(void);

/// @brief   Disable alarm of the RTC
/// @note    This function disables the alarm of RTC
void rtcAlarmDisable(void);

/// @brief   Enable interrupts of the RTC
/// @note    This function enables the interruption of RTC
void rtcInterruptEnable(void);

/// @brief   Disable interrupts of the RTC
/// @note    This function disables the interruption of RTC
void rtcInterruptDisable(void);

/// @brief   Register callback of interrupt routines function
/// @param   cbf_pointer Address of the function to register
/// @note    This function allow to register the RTC interrupt routines by 
///          a callback.
void registerRTCCallback(Callback_t cbf_pointer);

/******************************************************************************/
/*                           IRQ Routine Prototypes                           */
/******************************************************************************/
// RTC interrupt
void __attribute__((__interrupt__, __auto_psv__)) _RTCCInterrupt(void);

/******************************************************************************/
/*                            LIBRARY USED FUNCTION                           */
/******************************************************************************/
void rtcWriteEnable();

#endif	/* _CAN_H */
