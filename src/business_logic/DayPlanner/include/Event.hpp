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
        std::string m_name = "objekt";
        unsigned int m_id;
    };
}