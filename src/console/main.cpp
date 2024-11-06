#include <iostream>
#include "EventManager.hpp"
#include "EventRepository.hpp"
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include <ctime>
#include <iomanip>

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

    std::unique_ptr<IDateTimeGetter> date_time_getter = std::make_unique<DateTimeGetter>();

    auto now = date_time_getter -> GetCurrentTimeDate();
    std::cout << std::ctime(&now);

    auto hour_minute = date_time_getter -> GetCurrentHourMinute();

    std::cout << "\nHOUR: " << static_cast<int>(std::get<0>(hour_minute));
    std::cout << "\nMINUTE: " << static_cast<int>(std::get<1>(hour_minute));
    std::cout << "\nSECOND: " << static_cast<int>(date_time_getter -> GetCurrentSecond());
}