#include "catch2/catch_test_macros.hpp"
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include "fakeit.hpp"
#include <chrono>
#include <memory>

using namespace dp_business_logic::DayPlanner;

TEST_CASE("Time can return current Hour")
{
    //Arrange

    std::unique_ptr<IDateTimeGetter> date_time_getter = std::make_unique<DateTimeGetter>();
    int utc_normalizator = 1;

    auto excpected_result = std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now().time_since_epoch()).count() % 24 + utc_normalizator;
    auto result = date_time_getter -> GetCurrentHour() + 1;
    //Act

    //Assert
    REQUIRE(result == excpected_result);
}