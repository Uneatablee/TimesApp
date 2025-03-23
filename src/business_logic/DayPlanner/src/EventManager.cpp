#include "../include/EventManager.hpp"
#include "../include/IEventRepository.hpp"
#include <vector>
#include <algorithm>

namespace dp_business_logic::DayPlanner
{
    std::shared_ptr<const Event> EventManager::Get(std::string id)
    {
        auto event = m_events_repository -> GetById(id);
        return event;
    }

    std::vector<std::shared_ptr<const Event>> EventManager::GetAll() const
    {
        std::vector<std::shared_ptr<const Event>> events = m_events_repository -> GetAll();
        return events;
    }

    bool EventManager::Add(std::shared_ptr<const Event> event) const
    {
        auto id = event -> GetId();
        auto events_collection = m_events_repository -> GetAll();
        auto iter = std::find_if(events_collection.begin(), events_collection.end(), [id](std::shared_ptr<const Event> event_lambda)
        {return event_lambda -> GetId() == id;});

        if(iter == events_collection.end())
        {
            m_events_repository->Add(event);
            return true;
        }
        return false;
    }

    bool EventManager::Update(std::shared_ptr<const Event> event) const
    {
        auto id = event -> GetId();
        auto events_collection = m_events_repository -> GetAll();
        auto iter = std::find_if(events_collection.begin(), events_collection.end(), [id](std::shared_ptr<const Event> event_lambda)
        {return event_lambda -> GetId() == id;});

        if(iter != events_collection.end())
        {
            m_events_repository -> Update(event);
            return true;
        }

        return false;
    }

    bool EventManager::Delete(std::string id) const
    {
        auto events_collection = m_events_repository -> GetAll();
        auto iter = std::find_if(events_collection.begin(), events_collection.end(), [id](std::shared_ptr<const Event> event_lambda)
        {return event_lambda -> GetId() == id;});

        if(iter != events_collection.end())
        {
            m_events_repository -> Delete(id);
            return true;
        }

        return false;
    }
}
