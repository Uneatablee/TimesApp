#pragma once
#include "IDateTimeGetter.hpp"
#include <string>
#include <chrono>
#include <tuple>

namespace dp_business_logic::DayPlanner
{
    class DateTimeGetter : virtual public IDateTimeGetter
    {

    public:
        time_t GetCurrentTimeDate() override;
        long GetSecondsFromEpoch() override;
        long GetSecondsFromEpochFromString(std::string) override;
        std::chrono::year_month_day GetCurrentDate_YMDFormat() override;

        std::tuple<uint8_t, uint8_t> GetCurrentHourMinute() override;
        uint8_t GetCurrentSecond() override;

        std::tuple<unsigned int, uint8_t, uint8_t> GetCurrentYearMonthDay() override;

        uint8_t GetCurrentDayNumber() override;
        virtual std::tuple<unsigned int, uint8_t, uint8_t> ConvertEpochYearMonthDay(int) override;
        virtual std::tuple<uint8_t, uint8_t> ConvertEpochHourMinute(int) override;

        unsigned int GetOffsetDayDate(std::chrono::year_month_day, unsigned int) override;
        uint8_t GetMonthFromOffset(int days_offset = 0) override;
        unsigned int GetYearFromOffset(int days_offset = 0) override;
    };
}
