#include "catch2/catch_test_macros.hpp"
#include "fakeit.hpp"
#include "Event.hpp"
#include "HelperFunctions.hpp"
#include <string>
#include "IdFormatErrorException.hpp"

using namespace dp_business_logic::DayPlanner;

TEST_CASE("Event can generate unique id")
{
    //Arrange
    auto event = Event("", "event", 8, 12);

    //Act
    auto result = event.GetId();

    //Assert
    auto test_id = IdGen();
    REQUIRE(result != test_id);
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
    auto event = Event("", "event_first", 8, 12);

    //Act
    auto result = event.SetName("new_name");

    //Assert
    REQUIRE(result == true);
}

TEST_CASE("Event can return its id")
{
    //Arrange
    auto event = Event("00000000-0000-0000-0000-000000000001", "event_first", 8, 12);

    //Act
    auto result = event.GetId();
    auto expected_result = "00000000-0000-0000-0000-000000000001";

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event can set its id")
{
    //Arrange
    auto event = Event("", "event_first", 8, 12);

    //Act
    auto result = event.SetId("00000000-0000-0000-0000-000000000001");

    //Assert
    REQUIRE(result == true);
}

TEST_CASE("Event can return its end_seconds from epoch")
{
    //Arrange
    auto event = Event("", "event_first", 8, 1211);

    //Act
    auto result = event.GetEndEpoch();
    auto expected_result = 1211;

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event can return its start_seconds from epoch")
{
    //Arrange
    auto event = Event("", "event_first", 1231, 1211);

    //Act
    auto result = event.GetStartEpoch();
    auto expected_result = 1231;

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("Event throws exception if given id is in invalid format")
{
    //Arrange
    auto CreateEvent = [](){return Event("test_id", "event_first", 1231, 1211);};

    //Assesrt
    REQUIRE_THROWS_AS(CreateEvent(), IdFormatErrorException);
}

TEST_CASE("Event::SetId throws exception if id is in invalid format")
{
    //Arrange
    auto event = Event("", "event_first", 1231, 1211);

    //Assesrt
    REQUIRE_THROWS_AS(event.SetId("test_id"), IdFormatErrorException);
}


