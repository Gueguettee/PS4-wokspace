/**
  ****************************************************************************
  * @file    rtc.c
  * @author  Martin Marguerat
  * @date    21.04.2022
  * @brief   Implementation of RTC initialization functions
  * 
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "rtc.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_rtc_pointer = 0;

/******************************************************************************/
/*                              Global variables                              */
/******************************************************************************/


/******************************************************************************/
/*                 RTC INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/
void rtcInit(void)
{
    __builtin_write_OSCCONL(OSCCON | 0x02); // set LOPCEN bit to enable secondary oscillator
    PMD3bits.RTCCMD = 0;
    
    RCFGCALbits.RTCOE = 0;  // Output enable
    
    /* DRIFT CALIBRATION BITS
     * - 01111111 adds 508 RTCC clock pulses every one minute
     * - 00000001 adds 4 RTCC clock pulses every one minute
     * - 00000000 No adjustment
     * - 11111111 subtracts 4 RTCC clock pulses every one minute
     * - 10000000 subtracts 512 RTCC clock pulses every one minute */
    RCFGCALbits.CAL = 0x00;
    
    PADCFG1bits.RTSECSEL = 1;   // RTCC seconds clock output (RTCC alarm is selected)
    ALCFGRPTbits.ALRMEN = 0;    // Alarm is disabled
    ALCFGRPTbits.CHIME = 0;     // Chime is disabled (ARPT<7:0> bits stop once they reach 0x00)
    ALCFGRPTbits.AMASK = 0x0;   // Alarm mask configuration (0000 = Every half second)
    ALCFGRPTbits.ARPT = 0x00;   // Alarm repeat counter (00000000 = Alarm will not repeat)
    
    __builtin_write_RTCWEN();
    
    RCFGCALbits.RTCEN = 1;  // Enable RTC
    
    RCFGCALbits.RTCWREN = 0;    // Disable write
}

/******************************************************************************/
/*                      RTC USER FUNCTIONS Implementation                     */
/******************************************************************************/
void rtcWriteTime(time_t time)
{
    __builtin_write_RTCWEN();
    RCFGCALbits.RTCEN = 0;  // Disable RTC for the write
    
    unsigned int yearVal = ((time.year/10) << 4) + (time.year%10);
    unsigned int monthDayVal = ((time.month/10) << 12) + ((time.month%10) << 8)
            + ((time.day/10) << 4) + (time.day%10);
    unsigned int wdayHourVal = ((time.weekday) << 8)
            + ((time.hour/10) << 4) + (time.hour%10);
    unsigned int minuteSecondVal = ((time.minute/10) << 12) + ((time.minute%10) << 8)
            + ((time.second/10) << 4) + (time.second%10);
    
    RTCVAL = yearVal;   // YEAR VALUE REGISTER
    RTCVAL = monthDayVal;   // MONTH AND DAY VALUE REGISTER
    RTCVAL = wdayHourVal;   // WEEKDAY AND HOURS VALUE REGISTER
    RTCVAL = minuteSecondVal;   // MINUTES AND SECONDS REGISTER
    
    RCFGCALbits.RTCEN = 1;  // Enable RTC
    RCFGCALbits.RTCWREN = 0;    // Disable write
    rtcAlarmEnable();
}

void rtcWriteAlarm(time_t time, alarmmask_t mask, bool chime)
{
    __builtin_write_RTCWEN();
    RCFGCALbits.RTCEN = 0;  // Disable RTC for the write
    
    unsigned int yearVal = ((time.year/10) << 4) + (time.year%10);
    unsigned int monthDayVal = ((time.month/10) << 12) + ((time.month%10) << 8)
            + ((time.day/10) << 4) + (time.day%10);
    unsigned int wdayHourVal = ((time.weekday) << 8)
            + ((time.hour/10) << 4) + (time.hour%10);
    unsigned int minuteSecondVal = ((time.minute/10) << 12) + ((time.minute%10) << 8)
            + ((time.second/10) << 4) + (time.second%10);
            RCFGCALbits.RTCPTR = 0b11;
    
    ALCFGRPTbits.ALRMPTR = 0b10;
    ALRMVAL = yearVal;  // YEAR VALUE REGISTER
    ALRMVAL = monthDayVal;   // MONTH AND DAY VALUE REGISTER
    ALRMVAL = wdayHourVal;   // WEEKDAY AND HOURS VALUE REGISTER
    ALRMVAL = minuteSecondVal;   // MINUTES AND SECONDS REGISTER
////////////// ISSUE : ALARM IS NOT WORKING FOR MASK > 0001...
    ALCFGRPTbits.CHIME = chime; //1 = Chime is enabled; ARPT<7:0> bits are allowed to roll over from 0x00 to 0xFF
    ALCFGRPTbits.AMASK = mask;   // Alarm mask configuration (0010 = Every 10 seconds)
    
    RCFGCALbits.RTCEN = 1;  // Enable RTC
    ALCFGRPTbits.ALRMEN = 1;    // Enable Alarm
    RCFGCALbits.RTCWREN = 0;    // Disable write
    
    rtcInterruptEnable();
}

time_t rtcRead(rtctype_t type)
{
    unsigned int yearVal, monthDayVal, wdayHourVal, minuteSecondVal;
    time_t time;
    while(RCFGCALbits.RTCSYNC == 1);
    
    switch(type)
    {
        case eTime:
            RCFGCALbits.RTCPTR = 0b11;
            yearVal = RTCVAL;   // YEAR VALUE REGISTER
            monthDayVal = RTCVAL;   // MONTH AND DAY VALUE REGISTER
            wdayHourVal = RTCVAL;   // WEEKDAY AND HOURS VALUE REGISTER
            minuteSecondVal = RTCVAL;   // MINUTES AND SECONDS REGISTER
            break;
        case eAlarm:
            ALCFGRPTbits.ALRMPTR = 0b10;
            yearVal = ALRMVAL;   // YEAR VALUE REGISTER
            monthDayVal = ALRMVAL;   // MONTH AND DAY VALUE REGISTER
            wdayHourVal = ALRMVAL;   // WEEKDAY AND HOURS VALUE REGISTER
            minuteSecondVal = ALRMVAL;   // MINUTES AND SECONDS REGISTER
            break;
        default:
            break;
    }
    time.year = ((yearVal&0x00f0)>>4)*10 + (yearVal&0x000f);
    time.month = ((monthDayVal&0x1000)>>12)*10 + ((monthDayVal&0x0f00)>>8);
    time.day = ((monthDayVal&0x0030)>>4)*10 + (monthDayVal&0x000f);
    time.weekday = ((wdayHourVal&0x0700)>>8);
    time.hour = ((wdayHourVal&0x0030)>>4)*10 + (wdayHourVal&0x000f);
    time.minute = ((minuteSecondVal&0x3000)>>12)*10 + ((minuteSecondVal&0x0f00)>>8);
    time.second = ((minuteSecondVal&0x0030)>>4)*10 + (minuteSecondVal&0x000f);
    
    return time;
}

void rtcAlarmEnable(void)
{
    ALCFGRPTbits.ALRMEN = 1;
}

void rtcAlarmDisable(void)
{
    ALCFGRPTbits.ALRMEN = 0;
}

void rtcInterruptEnable(void)
{
    IFS3bits.RTCCIF = 0;    // clear flag
    IEC3bits.RTCCIE = 0x1;  // Enable RTC interrupt
}

void rtcInterruptDisable(void)
{
    IEC3bits.RTCCIE = 0x0;  // Disable RTC interrupt
    IFS3bits.RTCCIF = 0;    // clear flag
}

void registerRTCCallback(Callback_t cbf_pointer)
{
    cbf_rtc_pointer = cbf_pointer;
}

void __attribute__((__interrupt__, __auto_psv__)) _RTCCInterrupt(void)
{
    IFS3bits.RTCCIF = 0;        // clear interrupt flag
    if (0!=cbf_rtc_pointer)
    {
        cbf_rtc_pointer();
    }
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
