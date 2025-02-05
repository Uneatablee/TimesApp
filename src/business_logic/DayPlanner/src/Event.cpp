#include <string>
#include "../include/Event.hpp"
#include <limits>
#include <random>

namespace dp_business_logic::DayPlanner
{

    Event::Event(unsigned int id, std::string name, long long start, long long end)
        : BaseEntity(id == 0 ? IdGen() : id), m_name(name), m_event_start_epoch(start), m_event_end_epoch(end)
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

    int Event::IdGen()
    {
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(min, max);  // Losowanie z zakresu [min, max]

        return dis(gen);  // Zwracamy losową liczbę
    }
};