#include "../include/DateTimeGetter.hpp"
#include <chrono>
#include "date/tz.h"
#include <tuple>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace dp_business_logic::DayPlanner
{

    DateTime DateTimeGetter::GetDateTime()
    {
        return DateTime();
    }

    DateTime DateTimeGetter::GetDateTime(unsigned int day, unsigned int month, unsigned int year)
    {
        return DateTime(day, month, year);
    }

    DateTime DateTimeGetter::GetDateTime(std::string date)
    {
        return DateTime(date);
    }

    DateTime DateTimeGetter::GetDateTime(std::chrono::year_month_day ymd)
    {
        return DateTime(ymd);
    }
}