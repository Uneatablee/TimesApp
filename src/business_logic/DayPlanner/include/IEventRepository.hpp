#pragma once
#include <vector>
#include "Event.hpp"

namespace dp_business_logic::DayPlanner
{
    class IEventRepository
    {
    public:
        virtual bool Add(Event) = 0;
        virtual std::vector<Event> GetAll() = 0;
        virtual bool Update(Event) = 0;
        virtual bool Delete() = 0;
    };
}