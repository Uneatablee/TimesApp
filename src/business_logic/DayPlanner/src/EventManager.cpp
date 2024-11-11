#include "../include/EventManager.hpp"
#include "../include/IEventRepository.hpp"
#include <vector>

namespace dp_business_logic::DayPlanner
{
    std::shared_ptr<Event> EventManager::Get(unsigned int id)
    {
        auto event = m_events_repository -> GetById(id);
        return event;
    }

    std::vector<std::shared_ptr<Event>> EventManager::GetAll() const
    {
        std::vector<std::shared_ptr<Event>> events = m_events_repository -> GetAll();
        return events;
    }

    bool EventManager::Add(std::shared_ptr<Event> event) const
    {
        auto id = event -> GetId();
        for(const auto &elem : m_events_repository->GetAll())
        {
            auto existing_id = elem -> GetId();
            if(id == existing_id)
            {
                return false;
            }
        }

        m_events_repository->Add(event);
        return true;
    }

    bool EventManager::Update(std::shared_ptr<Event> event) const
    {
        auto id = event -> GetId();

        //End function
        return true;
    }
}
