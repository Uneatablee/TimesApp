#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{
    Event::Event(unsigned int id, std::string name, int epoch_start, int epoch_end)
        : BaseEntity(id, epoch_end, name), m_start_sec_from_epoch(epoch_start)
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
};