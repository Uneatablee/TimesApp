#pragma once
#include <vector>
#include "Event.hpp"
#include "IEventRepository.hpp"

namespace dp_business_logic::DayPlanner
{
    class EventManager
    {
    public:
        EventManager(IEventRepository* events_repository) : m_events_repository(events_repository){};
        bool Add(Event event) const;
        bool Update(Event event) const;
        std::vector<Event> GetAll() const;

    private:
        IEventRepository* const m_events_repository;
    };

}