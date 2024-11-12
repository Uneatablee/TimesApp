#include <iostream>
#include "EventManager.hpp"
#include "GenericRepository.hpp"
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include <ctime>
#include <iomanip>

using namespace dp_business_logic::DayPlanner;
using namespace data_access_layer;


// void SeedEventRepository(GenericRepository* repo)
// {
//     repo -> Add(Event{1, "Banana"});
//     repo -> Add(Event{2, "Apple"});
//     repo -> Add(Event{3, "Orange"});
//     repo -> Add(Event{4, "Granat"});
//     repo -> Add(Event{5, "Strawberry"});
// }


int main()
{
    // std::unique_ptr<IDateTimeGetter> date_time_getter = std::make_unique<DateTimeGetter>();

    // auto now = date_time_getter -> GetCurrentTimeDate();
    // std::cout << std::ctime(&now);

    // auto hour_minute = date_time_getter -> GetCurrentHourMinute();

    // std::cout << "\nHOUR: " << static_cast<int>(std::get<0>(hour_minute));
    // std::cout << "\nMINUTE: " << static_cast<int>(std::get<1>(hour_minute));
    // std::cout << "\nSECOND: " << static_cast<int>(date_time_getter -> GetCurrentSecond());


}