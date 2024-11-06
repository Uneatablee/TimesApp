#include "../include/DateTimeGetter.hpp"
#include <chrono>
#include "date/tz.h"
#include <tuple>
#include <iostream>

namespace dp_business_logic::DayPlanner
{
        time_t DateTimeGetter::GetCurrentTimeDate()
        {
            auto current_moment = std::chrono::system_clock::now();
            return std::chrono::system_clock::to_time_t(current_moment);
        }

        long DateTimeGetter::GetSecondsFromEpoch()
        {
            auto current_time = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::seconds>(current_time.time_since_epoch()).count();
        }

        std::chrono::year_month_day DateTimeGetter::GetCurrentDate_YMDFormat()
        {
            auto current_time_point_in_seconds = std::chrono::sys_seconds(std::chrono::seconds(GetSecondsFromEpoch()));
            return std::chrono::floor<std::chrono::days>(current_time_point_in_seconds);
        }

        std::tuple<unsigned int, uint8_t, uint8_t> DateTimeGetter::GetCurrentYearMonthDay()
        {
            auto year_month_day = GetCurrentDate_YMDFormat();

            auto year = static_cast<unsigned int>(static_cast<int>(year_month_day.year()));
            auto month = static_cast<uint8_t>(static_cast<unsigned int>(year_month_day.month()));
            auto day = static_cast<uint8_t>(static_cast<unsigned int>(year_month_day.day()));

            return {year, month, day};
        }

        std::tuple<uint8_t, uint8_t> DateTimeGetter::GetCurrentHourMinute()
        {
            auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());

            auto current_local_time = date::floor<std::chrono::minutes>(now.get_local_time());
            auto days_passed = date::floor<date::days>(now.get_local_time());
            auto time = date::make_time(current_local_time - days_passed);

            uint8_t hours = static_cast<uint8_t>(time.hours().count());
            uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

            return {hours, minutes};
        }

        inline uint8_t DateTimeGetter::GetCurrentSecond()
        {
            return  GetSecondsFromEpoch() % 60;
        }

        std::string DateTimeGetter::GetDayName()
        {
            return "";
        }

        unsigned int DateTimeGetter::GetYear()
        {
            return 0;
        }

        uint8_t DateTimeGetter::GetMonth()
        {
            return uint8_t();
        }

        uint8_t DateTimeGetter::GetDay()
        {
            return uint8_t();
        }
}

