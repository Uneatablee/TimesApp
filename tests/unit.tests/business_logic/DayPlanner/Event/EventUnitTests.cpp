#include "catch2/catch_test_macros.hpp"
#include "fakeit.hpp"
#include "Event.hpp"
#include "HelperFunctions.hpp"
#include <string>

using namespace dp_business_logic::DayPlanner;

TEST_CASE("Event can generate unique id")
{
    //Arrange
    auto event = Event("", "event", 8, 12);

    //Act
    auto result = event.GetId();

    //Assert
    for(int i = 0; i < 1000; i++)
    {
        auto test_id = IdGen();
        REQUIRE(result != test_id);
    }
}

TEST_CASE("Event can return its name")
{
    //Arrange
    auto event = Event("", "event_first", 8, 12);

    //Act
    auto result = event.GetName();
    auto expected_result = "event_first";

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event can set its name")
{
    //Arrange
    auto event = Event("test_id", "event_first", 8, 12);

    //Act
    auto result = event.SetName("new_name");

    //Assert
    REQUIRE(result == true);
}

TEST_CASE("Event can return its id")
{
    //Arrange
    auto event = Event("test_id", "event_first", 8, 12);

    //Act
    auto result = event.GetId();
    auto expected_result = "test_id";

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event can set its id")
{
    //Arrange
    auto event = Event("test_id", "event_first", 8, 12);

    //Act
    auto result = event.SetId("changed");

    //Assert
    REQUIRE(result == true);
}

TEST_CASE("Event can return its end_secondss from epoch")
{
    //Arrange
    auto event = Event("test_id", "event_first", 8, 1211);

    //Act
    auto result = event.GetEndEpoch();
    auto expected_result = 1211;

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event can return its start_seconds from epoch")
{
    //Arrange
    auto event = Event("test_id", "event_first", 1231, 1211);

    //Act
    auto result = event.GetStartEpoch();
    auto expected_result = 1231;

    //Assert
    REQUIRE(result == expected_result);
}



