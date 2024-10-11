#pragma once
#include <time.h>
#include <chrono>

namespace dp_business_logic::DayPlanner
{

    class Time final
    {
    public:

       int GetCurrentDate();
       int GetCurrentTime();

    private:
        Time();
    };


} // namespace dp_business_logic::DayPlanner
