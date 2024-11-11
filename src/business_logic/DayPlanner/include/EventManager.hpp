#pragma once
#include <vector>
#include "Event.hpp"
#include "IGenericRepository.hpp"
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    class EventManager
    {
    public:
        EventManager(IGenericRepository<Event>* events_repository) : m_events_repository(events_repository){};
        bool Add(Event* event) const;
        bool Update(Event* event) const;
        std::vector<Event*> GetAll() const;
        Event* Get(unsigned int id);

    private:
        IGenericRepository<Event>* const m_events_repository;
    };

}