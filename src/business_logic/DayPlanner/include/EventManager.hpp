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
        EventManager(std::shared_ptr<IGenericRepository<Event>> events_repository) : m_events_repository(events_repository){};
        bool Add(std::shared_ptr<Event> event) const;
        bool Update(std::shared_ptr<Event> event) const;
        std::vector<std::shared_ptr<Event>> GetAll() const;
        std::shared_ptr<Event> Get(unsigned int id);
        bool Delete(unsigned int id) const;

    private:
        std::shared_ptr<IGenericRepository<Event>> const m_events_repository;
    };

}