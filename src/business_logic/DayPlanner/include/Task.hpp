#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Task : virtual public BaseEntity
    {
    public:

        Task(unsigned int id, std::string name);
        Task(unsigned int);
        std::string GetName() const;
        bool SetName(std::string);
    private:
        std::string m_name;
    };
}