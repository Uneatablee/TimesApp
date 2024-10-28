#pragma once
#include <string>

namespace dp_business_logic::DayPlanner
{
    class Event
    {
    public:
        Event(unsigned int);
        std::string GetName() const;
        bool SetName(std::string);
        unsigned int GetId() const;
    private:
        std::string m_name = "elo";
        unsigned int m_id;
    };
}