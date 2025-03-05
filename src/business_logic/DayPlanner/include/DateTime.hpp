#pragma once
#include <chrono>
#include <time.h>
#include <stdint.h>
#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace dp_business_logic::DayPlanner
{
    class DateTime
    {

    private:
        time_t m_time_point;

    public:
        DateTime();
        DateTime(unsigned int day, unsigned int month, unsigned int year);
        DateTime(std::string date);
        DateTime(std::chrono::year_month_day ymd);

        bool SetTimePoint(time_t time_point);

        long GetSecondsFromEpoch();
        long GetSecondsFromEpochFromString(std::string);
        unsigned int GetOffsetDayDate(unsigned int);
        unsigned int GetYearFromOffset(int days_offset = 0);
        time_t GetCurrentTimeDate();
        std::chrono::year_month_day GetCurrentDate_YMDFormat();
        std::chrono::year_month_day GetYMD();
        std::tuple<unsigned int, uint8_t, uint8_t> GetCurrentYearMonthDay();
        std::tuple<unsigned int, uint8_t, uint8_t> ConvertEpochYearMonthDay(long long);
        std::tuple<uint8_t, uint8_t> GetCurrentHourMinute();
        std::tuple<uint8_t, uint8_t> ConvertEpochHourMinute(long long);
        uint8_t GetCurrentSecond();
        uint8_t GetCurrentDayNumber();
        uint8_t GetMonthFromOffset(int days_offset = 0);
    };
}