// #include "../include/EventManager.hpp"
// #include "../include/IEventRepository.hpp"
// #include <vector>

// namespace dp_business_logic::DayPlanner
// {
//     std::vector<Event> EventManager::GetAll() const
//     {
//         std::vector<Event> events = m_events_repository -> GetAll();
//         return events;
//     }

//     bool EventManager::Add(Event event) const
//     {
//         auto id = event.GetId();
//         for(const auto &elem : m_events_repository->GetAll())
//         {
//             auto existing_id = elem.GetId();
//             if(id == existing_id)
//             {
//                 return false;
//             }
//         }

//         m_events_repository->Add(event);
//         return true;
//     }

//     bool EventManager::Update(Event event) const
//     {
//         auto id = event.GetId();

//         return true;
//     }
// }
