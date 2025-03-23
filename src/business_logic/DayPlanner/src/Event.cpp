#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{
    Event::Event(std::string id, std::string name, long long start, long long end)
        : BaseEntity(id, name, end), m_event_start_epoch(start)
    {}

    long long Event::GetStartEpoch() const
    {
        return m_event_start_epoch;
    }
};