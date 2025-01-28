#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Event final : virtual public BaseEntity
    {
    public:

        Event(unsigned int id, std::string name, long long start, long long end);
        Event(unsigned int);
        std::string GetName() const;
        long long GetStartEpoch() const;
        long long GetEndEpoch() const;
        bool SetName(std::string);
    private:
        std::string m_name;
        long long m_event_start_epoch;
        long long m_event_end_epoch;
        static inline unsigned int m_event_auto_id = 0;
    };
}