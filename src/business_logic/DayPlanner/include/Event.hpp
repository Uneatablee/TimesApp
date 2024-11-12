#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Event final : virtual public BaseEntity
    {
    public:

        Event(unsigned int id, std::string name);
        Event(unsigned int);
        std::string GetName() const;
        bool SetName(std::string);
    private:
        std::string m_name;
    };
}