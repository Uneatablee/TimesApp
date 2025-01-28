#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{

    Event::Event(unsigned int id, std::string name, long long start, long long end)
        : BaseEntity(id == 0 ? ++m_event_auto_id : id), m_name(name), m_event_start_epoch(start), m_event_end_epoch(end)
    {}

    long long Event::GetEndEpoch() const
    {
        return m_event_end_epoch;
    }

    long long Event::GetStartEpoch() const
    {
        return m_event_start_epoch;
    }

    std::string Event::GetName() const
    {
        return m_name;
    }

    bool Event::SetName(std::string name)
    {
        m_name = name;
        return true;
    }
};