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

        DateTime GetDateTime();
        DateTime GetDateTime(unsigned int, unsigned int, unsigned int);
        DateTime GetDateTime(std::string);
        DateTime GetDateTime(std::chrono::year_month_day);

    };
}
