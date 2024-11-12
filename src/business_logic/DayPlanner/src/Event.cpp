#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{
    Event::Event(unsigned int id, std::string name) : BaseEntity(id), m_name(name)
    {}

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