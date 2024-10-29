#pragma once
#include "IDateTimeGetter.hpp"

namespace dp_business_logic::DayPlanner
{
    class DateTimeGetter : virtual public IDateTimeGetter
    {

    public:
        time_t GetCurrentTimeDate() override;

        uint8_t GetCurrentHour() override;
        uint8_t GetCurrentMinute() override;
        uint8_t GetCurrentSecond() override;

        unsigned int GetCurrentYear() override;
        uint8_t GetCurrentMonth() override;
        uint8_t GetCurrentDay() override;

        std::string GetDayName() override;
        unsigned int GetYear() override;
        uint8_t GetMonth() override;
        uint8_t GetDay() override;
    };
}
