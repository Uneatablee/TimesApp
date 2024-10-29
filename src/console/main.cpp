#include <iostream>
#include "EventManager.hpp"
#include "EventRepository.hpp"

using namespace dp_business_logic::DayPlanner;
using namespace data_access_layer;


int main()
{
    EventRepository* event_repository = new EventRepository;
    EventManager event_manager(event_repository);

    event_manager.GetAll();
    event_manager.Add(Event(7));
    for(const auto &elem : event_manager.GetAll())
    {
        std::cout << elem.GetName() << "\t";
    }

    std::cout << std::endl;

    for(const auto &elem : event_manager.GetAll())
    {
        std::cout << elem.GetName() << "\t";
    }

    event_manager.Update(Event(1));

    std::cout <<std::endl<<std::endl;
    for(const auto &elem : event_manager.GetAll())
    {
        std::cout << elem.GetName() << "\t";
    }

}