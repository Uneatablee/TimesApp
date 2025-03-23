#pragma once
#include <time.h>
#include <chrono>
#include <stdint.h>
#include <string>
#include <tuple>


namespace dp_business_logic::DayPlanner
{
    class DateTime;
    class IDateTimeGetter
    {

    public:
        IDateTimeGetter() = default;
        virtual ~IDateTimeGetter() = default;

        IDateTimeGetter(const IDateTimeGetter& object) = default;
        IDateTimeGetter& operator=(const IDateTimeGetter& object) = default;

        IDateTimeGetter(IDateTimeGetter&& object) = default;
        IDateTimeGetter& operator=(IDateTimeGetter && object) = default;

        virtual DateTime GetCurrentUTCDateTime() = 0;
        virtual DateTime GetCurrentLocalDateTime() = 0;
    };

}
