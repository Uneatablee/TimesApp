#include "Task.hpp"
#include <string>

namespace dp_business_logic::DayPlanner
{
    Task::Task(unsigned int id, std::string name) : BaseEntity(id), m_name(name)
    {}

    std::string Task::GetName() const
    {
        return m_name;
    }

    bool Task::SetName(std::string name)
    {
        m_name = name;
        return true;
    }
};