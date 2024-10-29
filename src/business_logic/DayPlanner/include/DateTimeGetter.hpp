#pragma once
#include <time.h>
#include <chrono>
#include <stdint.h>
#include <string>

namespace dp_business_logic::DayPlanner
{
    namespace DateTimeGetter
    {
        time_t GetCurrentTime();

        uint8_t GetCurrentHours();
        uint8_t GetCurrentMinutes();
        uint8_t GetCurrentSeconds();

        unsigned int GetCurrentYear();
        uint8_t GetCurrentMonth();
        uint8_t GetCurrentDay();

        std::string GetDayName();
        unsigned int GetYear();
        uint8_t GetMonth();
        uint8_t GetDay();
    }
} // namespace dp_business_logic::DayPlanner
