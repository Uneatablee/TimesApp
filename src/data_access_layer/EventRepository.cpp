#include "EventRepository.hpp"
#include "Event.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace dp_business_logic::DayPlanner;

namespace data_access_layer
{

    bool EventRepository::Add(Event event)
    {
        m_events_data.push_back(event);
        return true;
    }

    bool EventRepository::Delete()
    {
        m_events_data.pop_back();
        return true;
    }

    bool EventRepository::Update(Event event)
    {
        auto id = event.GetId();
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](const Event &event)
        {return event.GetId() == id;});

        *iter = event;

        return true;
    }

    std::vector<Event> EventRepository::GetAll()
    {
        return m_events_data;
    }
}