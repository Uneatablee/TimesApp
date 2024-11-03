#include "../include/DateTimeGetter.hpp"
#include <chrono>
#include "date/tz.h"

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

        uint8_t DateTimeGetter::GetCurrentHour()
        {
            auto hours_since_epoch = GetSecondsFromEpoch() / 3600;
            return static_cast<uint8_t>(hours_since_epoch % 24);
        }

        uint8_t DateTimeGetter::GetCurrentMinute()
        {
            auto minutes_since_epoch = GetSecondsFromEpoch() / 60;
            return static_cast<uint8_t>(minutes_since_epoch % 60);
        }

        uint8_t DateTimeGetter::GetCurrentSecond()
        {
            return static_cast<uint8_t>(GetSecondsFromEpoch() % 60);
        }

        unsigned int DateTimeGetter::GetCurrentYear()
        {
            auto seconds_from_epoch = GetSecondsFromEpoch();
            return static_cast<unsigned int>((static_cast<double>(seconds_from_epoch) / 86400) / 365.24 + 1970);
        }

        uint8_t DateTimeGetter::GetCurrentMonth()
        {

            return uint8_t();
        }

        uint8_t DateTimeGetter::GetCurrentDay()
        {
            return uint8_t();
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

