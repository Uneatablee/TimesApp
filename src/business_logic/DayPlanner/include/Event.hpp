#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Event final : virtual public BaseEntity
    {
    public:

        Event() = delete;
        Event(std::string id, std::string name, long long start, long long end);
        long long GetStartEpoch() const;

    private:
        long long m_event_start_epoch;
    };
}