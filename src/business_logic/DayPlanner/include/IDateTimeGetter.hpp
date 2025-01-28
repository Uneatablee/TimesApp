#pragma once
#include <time.h>
#include <chrono>
#include <stdint.h>
#include <string>
#include <tuple>

namespace dp_business_logic::DayPlanner
{
    class IDateTimeGetter
    {

    public:
        IDateTimeGetter() = default;
        virtual ~IDateTimeGetter() = default;

        IDateTimeGetter(const IDateTimeGetter& object) = default;
        IDateTimeGetter& operator=(const IDateTimeGetter& object) = default;

        IDateTimeGetter(IDateTimeGetter&& object) = default;
        IDateTimeGetter& operator=(IDateTimeGetter && object) = default;


        virtual time_t GetCurrentTimeDate() = 0;
        virtual long GetSecondsFromEpoch() = 0;
        virtual long GetSecondsFromEpochFromString(std::string) = 0;
        virtual std::chrono::year_month_day GetCurrentDate_YMDFormat() = 0;
        virtual std::tuple<uint8_t, uint8_t> GetCurrentHourMinute() = 0;
        virtual uint8_t GetCurrentSecond() = 0;

        virtual std::chrono::year_month_day GetYMD(int, int, int) = 0;
        virtual std::tuple<unsigned int, uint8_t, uint8_t> GetCurrentYearMonthDay() = 0;
        virtual uint8_t GetCurrentDayNumber() = 0;
        virtual std::tuple<unsigned int, uint8_t, uint8_t> ConvertEpochYearMonthDay(long long) = 0;
        virtual std::tuple<uint8_t, uint8_t> ConvertEpochHourMinute(long long) = 0;

        virtual unsigned int GetOffsetDayDate(std::chrono::year_month_day, unsigned int) = 0;
        virtual uint8_t GetMonthFromOffset(int) = 0;
        virtual unsigned int GetYearFromOffset(int) = 0;
    };

}
