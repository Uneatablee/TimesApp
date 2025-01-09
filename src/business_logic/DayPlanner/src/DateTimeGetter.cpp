#include "../include/DateTimeGetter.hpp"
#include <chrono>
#include "date/tz.h"
#include <tuple>
#include <iostream>
#include <string>

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
            auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());
            auto local_time = now.get_local_time();
            return static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));
        }

        std::tuple<unsigned int, uint8_t, uint8_t> DateTimeGetter::GetCurrentYearMonthDay()
        {
            auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());
            auto local_time = now.get_local_time();
            auto ymd = static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time));

            auto year = static_cast<unsigned int>(static_cast<int>(ymd.year()));
            auto month = static_cast<uint8_t>(static_cast<unsigned int>(ymd.month()));
            auto day = static_cast<uint8_t>(static_cast<unsigned int>(ymd.day()));

            return std::make_tuple(year, month, day);
        }

        std::tuple<uint8_t, uint8_t> DateTimeGetter::GetCurrentHourMinute()
        {
            auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());

            auto local_time = now.get_local_time();
            auto current_local_time = date::floor<std::chrono::minutes>(local_time);
            auto days_passed = date::floor<date::days>(local_time);
            auto time = date::make_time(current_local_time - days_passed);

            uint8_t hours = static_cast<uint8_t>(time.hours().count());
            uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

            return {hours, minutes};
        }

        inline uint8_t DateTimeGetter::GetCurrentSecond()
        {
            return  GetSecondsFromEpoch() % 60;
        }

        uint8_t DateTimeGetter::GetCurrentDayNumber()
        {
            auto current_ymd = GetCurrentDate_YMDFormat();
            return (std::chrono::weekday(current_ymd)).iso_encoding();
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

        unsigned int DateTimeGetter::GetOffsetDayDate(std::chrono::year_month_day ymd, unsigned int days_prev_count)
        {
            date::sys_days target_day = ymd;
            std::chrono::year_month_day day_date = target_day + date::days{days_prev_count};
            return static_cast<unsigned int>(static_cast<date::year_month_day>(day_date).day());
        }

        uint8_t DateTimeGetter::GetMonthFromOffset(int days_offset)
        {
            if(days_offset == 0)
            {
                return std::get<1>(GetCurrentYearMonthDay());
            }

            auto curr_date = GetCurrentDate_YMDFormat();
            auto target_date = date::sys_days(curr_date) + date::days(days_offset);
            return static_cast<uint8_t>(static_cast<unsigned int>(static_cast<date::year_month_day>(target_date).month()));
        }

        unsigned int DateTimeGetter::GetYearFromOffset(int days_offset)
        {
            if(days_offset == 0)
            {
                return std::get<0>(GetCurrentYearMonthDay());
            }

            auto curr_date = GetCurrentDate_YMDFormat();
            auto target_date = date::sys_days(curr_date) + date::days(days_offset);
            return static_cast<unsigned int>(static_cast<int>(static_cast<date::year_month_day>(target_date).year()));
        }
}

