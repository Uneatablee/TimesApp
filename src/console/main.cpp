#include <iostream>
#include <ctime>
#include <iomanip>
#include <memory>
#include <chrono>
#include "date/tz.h"
#include <filesystem>
#include <cstdlib>

#include "EventManager.hpp"
#include "IGenericRepository.hpp"
// #include "GenericRepository.hpp"
#include "GenericRepositorySQLite.hpp"
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include "Event.hpp"

using namespace dp_business_logic::DayPlanner;
using namespace data_access_layer::dal::sqlite;



void SeedEventRepository(std::unique_ptr<EventManager> &manager)
{
    manager -> Add(std::make_shared<Event>(1, "Banana", 123, 123));
    manager -> Add(std::make_shared<Event>(2, "Apple", 123, 123));
    manager -> Add(std::make_shared<Event>(3, "Orange", 123, 123));
    manager -> Add(std::make_shared<Event>(4, "Granat", 123, 123));
    manager -> Add(std::make_shared<Event>(5, "Strawberry", 123, 123));
    manager -> Add(std::make_shared<Event>(6, "Peach", 123, 123));
}

int main()
{
    auto path = std::getenv("HOME");
    if(!path)
    {
        return -4;
    }
    //add path -> Application Support -> TimesApp Data for local temp DB
    //add Mac and Windows default folder (Win %Appdata%);
    std::shared_ptr<IGenericRepository<Event>> genericEventRepo = std::make_shared<GenericRepository<Event>>("");
    std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>(genericEventRepo);

    for(const auto &elem : eventManager -> GetAll())
    {
        std::cout << elem -> GetId() << "\t" << elem -> GetName() << "\n";
    }

}