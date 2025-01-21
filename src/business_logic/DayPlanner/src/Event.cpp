#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{

    Event::Event(unsigned int id, std::string name, int start, int end)
        : BaseEntity(id), m_name(name), m_event_start_epoch(start), m_event_end_epoch(end)
    {}

    int Event::GetEndEpoch() const
    {
        return m_event_end_epoch;
    }

    int Event::GetStartEpoch() const
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