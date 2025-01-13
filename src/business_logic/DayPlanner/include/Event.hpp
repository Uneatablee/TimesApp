#pragma once
#include <string>
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class Event final : virtual public BaseEntity
    {
    public:

        Event(unsigned int id, std::string name, int sec_epoch_start, int sec_epoch_end);
        Event(unsigned int);
        int GetStartEpoch() const;
        bool SetStartEpoch(int start_epoch);

    private:
        int m_start_sec_from_epoch;

    };
}