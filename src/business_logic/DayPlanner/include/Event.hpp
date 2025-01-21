#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Event final : virtual public BaseEntity
    {
    public:

        Event(unsigned int id, std::string name, int start, int end);
        Event(unsigned int);
        std::string GetName() const;
        int GetStartEpoch() const;
        int GetEndEpoch() const;
        bool SetName(std::string);
    private:
        std::string m_name;
        int m_event_start_epoch;
        int m_event_end_epoch;
    };
}