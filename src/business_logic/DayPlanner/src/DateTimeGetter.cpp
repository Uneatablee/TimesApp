#include "../include/DateTimeGetter.hpp"
#include <chrono>
#include <ctime>

namespace dp_business_logic::DayPlanner
{
        time_t DateTimeGetter::GetCurrentTimeDate() //---> Function without testing
        {
            auto current_moment = std::chrono::system_clock::now();
            return std::chrono::system_clock::to_time_t(current_moment);
        }

        uint8_t DateTimeGetter::GetCurrentHour()
        {
            auto current_time = std::chrono::system_clock::now();
            auto hours_since_epoch = std::chrono::duration_cast<std::chrono::hours>(current_time.time_since_epoch()).count();
            return static_cast<uint8_t>(hours_since_epoch % 24);
        }

        uint8_t DateTimeGetter::GetCurrentMinute()
        {
            return uint8_t();
        }

        uint8_t DateTimeGetter::GetCurrentSecond()
        {
            return uint8_t();
        }

        unsigned int DateTimeGetter::GetCurrentYear()
        {
            return 0;
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

