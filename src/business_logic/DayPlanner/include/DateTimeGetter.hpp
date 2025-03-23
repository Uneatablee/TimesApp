#pragma once
#include <string>
#include <chrono>
#include <tuple>
#include "IDateTimeGetter.hpp"
#include "DateTime.hpp"

namespace dp_business_logic::DayPlanner
{
    class DateTimeGetter : virtual public IDateTimeGetter
    {

    public:

        DateTime GetCurrentUTCDateTime();
        DateTime GetCurrentLocalDateTime();
    };
}
