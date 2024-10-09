#pragma once
#include <time.h>
#include <chrono>

namespace dp_business_logic::DayPlanner
{

    class Time
    {
    public:

        Time();
        virtual ~Time() = default;

        Time(const Time&) = default;
        Time(Time&&) = default;

        Time& operator=(const Time&) = default;
        Time& operator=(Time&&) = default;

        virtual int GetCurrentDate();
        virtual int GetCurrentTime();

    private:

    };


} // namespace dp_business_logic::DayPlanner
