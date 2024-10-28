#include <string>
#include "../include/Event.hpp"

namespace dp_business_logic::DayPlanner
{
    Event::Event(unsigned int id) : m_id(id)
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

    unsigned int Event::GetId() const
    {
        return m_id;
    }
};