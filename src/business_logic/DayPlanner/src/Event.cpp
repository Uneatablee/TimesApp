#include <string>
#include "../include/Event.hpp"
#include <limits>
#include <random>
#include "uuid.h"

namespace dp_business_logic::DayPlanner
{

    Event::Event(std::string id, std::string name, long long start, long long end)
        : BaseEntity(id == "" ? IdGen() : id), m_name(name), m_event_start_epoch(start), m_event_end_epoch(end)
    {}

    long long Event::GetEndEpoch() const
    {
        return m_event_end_epoch;
    }

    long long Event::GetStartEpoch() const
    {
        return m_event_start_epoch;
    }

    std::string Event::GetName() const
    {
        return m_name;
    }

    bool Event::SetName(std::string name)
    {
        m_name = name;
        return true;
    }

    std::string Event::IdGen()
    {
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        std::mt19937 generator(seq);
        uuids::uuid_random_generator gen{generator};

        uuids::uuid const id = gen();
        return uuids::to_string(id);
    }
};