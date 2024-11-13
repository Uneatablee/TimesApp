#include <iostream>
#include <ctime>
#include <iomanip>
#include <memory>
#include <chrono>
#include "date/tz.h"

#include "EventManager.hpp"
#include "IGenericRepository.hpp"
#include "GenericRepository.hpp"
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include "Event.hpp"

using namespace dp_business_logic::DayPlanner;
using namespace data_access_layer;


void SeedEventRepository(std::unique_ptr<EventManager> &manager)
{
    manager -> Add(std::make_shared<Event>(1, "Banana"));
    manager -> Add(std::make_shared<Event>(2, "Apple"));
    manager -> Add(std::make_shared<Event>(3, "Orange"));
    manager -> Add(std::make_shared<Event>(4, "Granat"));
    manager -> Add(std::make_shared<Event>(5, "Strawberry"));
    manager -> Add(std::make_shared<Event>(6, "Peach"));
}


int main()
{
    std::shared_ptr<IGenericRepository<Event>> genericEventRepo = std::make_shared<GenericRepository<Event>>();
    std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>(genericEventRepo);

    SeedEventRepository(eventManager);
    for(const auto &elem : eventManager -> GetAll())
    {
        std::cout << elem -> GetId() << "\t" << elem -> GetName() << "\n";
    }

}