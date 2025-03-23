#pragma once
#include <chrono>
#include <time.h>
#include <stdint.h>
#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "date/tz.h"
#include <memory>

namespace dp_business_logic::DayPlanner
{
    class DateTime
    {

    private:
        time_t m_time_point;
        const date::time_zone* m_zone;

    public:
        DateTime(time_t time_point, const date::time_zone* zone);
        DateTime(time_t time_point);
        DateTime(unsigned int day, unsigned int month, unsigned int year);
        DateTime(std::string date);
        DateTime(std::chrono::year_month_day ymd);
        DateTime() = default;

        DateTime& operator=(const DateTime&) = default;
        DateTime(const DateTime&) = default;

        DateTime& operator=(DateTime&&) = default;
        DateTime(DateTime&&) = default;

        // bool SetTimePoint(time_t time_point);

        long GetSecondsFromEpoch();
        long GetSecondsFromEpochFromString(std::string);
        unsigned int GetOffsetDayDate(unsigned int days);
        unsigned int GetYearFromOffset(int days_offset = 0);
        time_t GetCurrentTimeDate();
        std::chrono::year_month_day GetDate_YMDFormat();
        std::chrono::year_month_day GetYMD();
        std::tuple<unsigned int, uint8_t, uint8_t> GetYearMonthDay();
        std::tuple<unsigned int, uint8_t, uint8_t> ConvertEpochYearMonthDay(long long);
        std::tuple<uint8_t, uint8_t> GetHourMinute();
        std::tuple<uint8_t, uint8_t> ConvertEpochHourMinute(long long);
        uint8_t GetDayNumber();
        uint8_t GetMonthFromOffset(int days_offset = 0);
    };
}