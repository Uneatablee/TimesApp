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

    DateTime DateTimeGetter::GetCurrentUTCDateTime()
    {
        std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
        auto current_time_t = std::chrono::system_clock::to_time_t(current_time);
        return DateTime(current_time_t);
    }

    DateTime DateTimeGetter::GetCurrentLocalDateTime()
    {
        std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
        auto current_time_t = std::chrono::system_clock::to_time_t(current_time);
        return DateTime(current_time_t, date::current_zone());
    }
}