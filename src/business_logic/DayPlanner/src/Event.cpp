#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{
    Event::Event(unsigned int id, std::string name, int start, int end)
        : BaseEntity(id), m_name(name), m_event_start_epoch(start), m_event_end_epoch(end)
    {}

    int Event::GetStartEpoch() const
    {
        return m_start_sec_from_epoch;
    }

    bool Event::SetStartEpoch(int start_sec_epoch)
    {
        m_start_sec_from_epoch = start_sec_epoch;
        return true;
    }

    int Event::GetStartEpoch() const
    {
        return m_event_start_epoch;
    }

    int Event::GetEndEpoch() const
    {
        return m_event_end_epoch;
    }
};