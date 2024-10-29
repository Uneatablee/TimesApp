#pragma once
#include <time.h>
#include <chrono>
#include <stdint.h>
#include <string>

namespace dp_business_logic::DayPlanner
{
    class IDateTimeGetter
    {

    public:
        virtual time_t GetCurrentTimeDate() = 0;

        virtual uint8_t GetCurrentHour() = 0;
        virtual uint8_t GetCurrentMinute() = 0;
        virtual uint8_t GetCurrentSecond() = 0;

        virtual unsigned int GetCurrentYear() = 0;
        virtual uint8_t GetCurrentMonth() = 0;
        virtual uint8_t GetCurrentDay() = 0;

        virtual std::string GetDayName() = 0;
        virtual unsigned int GetYear() = 0;
        virtual uint8_t GetMonth() = 0;
        virtual uint8_t GetDay() = 0;
    };

}
