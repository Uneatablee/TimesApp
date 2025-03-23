#include "catch2/catch_test_macros.hpp"
#include "fakeit.hpp"
#include "IGenericRepository.hpp"

#include <Event.hpp>
#include <memory>
#include <vector>
#include <EventManager.hpp>

using namespace dp_business_logic::DayPlanner;

TEST_CASE("EventManager::Get can return event by id")
{
    //Arrange
    auto event = std::make_shared<const Event>("00000000-0000-0000-0000-000000000003", "third", 1, 2);

    fakeit::Mock<IGenericRepository<Event>> mock;
    fakeit::When(Method(mock, GetById)).Return(event);
    IGenericRepository<Event>* repo_mock = &mock.get();
    EventManager manager(std::shared_ptr<IGenericRepository<Event>>(repo_mock, [](IGenericRepository<Event>*) {}));

    //Act
    auto expected_result = event;
    auto result = manager.Get("00000000-0000-0000-0000-000000000003");

    //Assert
    REQUIRE(result == expected_result);
}

TEST_CASE("EventManager::Add can manage event adding behaviour for existing repository")
{
    //Arrange
    std::vector<std::shared_ptr<const Event>> events_list
    {
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000001", "first", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000002", "second", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000003", "third", 1, 2)
    };

    fakeit::Mock<IGenericRepository<Event>> mock;
    fakeit::When(Method(mock, GetAll)).AlwaysReturn(events_list);
    fakeit::When(Method(mock, Add)).AlwaysReturn(true);
    IGenericRepository<Event>* repo_mock = &mock.get();
    EventManager manager(std::shared_ptr<IGenericRepository<Event>>(repo_mock, [](IGenericRepository<Event>* ){}));

    SECTION("EventManager is adding when id is not duplicated")
    {
        //Arrange
        auto event = std::make_shared<const Event>("00000000-0000-0000-0000-000000000004", "fourth", 1, 2);

        //Act
        bool result = manager.Add(event);

        //Assert
        REQUIRE(result == true);
    }


    SECTION("EventManager is not adding when id is duplicated")
    {
        //Arrange
        auto event = std::make_shared<const Event>("00000000-0000-0000-0000-000000000002", "third_again", 4, 7);

        //Act
        bool result = manager.Add(event);

        //Assert
        REQUIRE(result == false);
    }
}

TEST_CASE("EventManager::GetAll can return event_lists from existing repository")
{
    //Arrange
    std::vector<std::shared_ptr<const Event>> events_list
    {
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000001", "first", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000002", "second", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000003", "third", 1, 2)
    };

    fakeit::Mock<IGenericRepository<Event>> mock;
    fakeit::When(Method(mock, GetAll)).Return(events_list);
    IGenericRepository<Event>* repo_mock = &mock.get();
    EventManager manager(std::shared_ptr<IGenericRepository<Event>>(repo_mock, [](IGenericRepository<Event>*){}));

    //Act
    auto result = manager.GetAll();

    //Assert
    REQUIRE(result == events_list);

}

TEST_CASE("EventManager::Update can update event in existing events repository")
{
    //Arrange
    std::vector<std::shared_ptr<const Event>> events_list
    {
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000001", "first", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000002", "second", 1, 2),
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000003", "third", 1, 2)
    };

    fakeit::Mock<IGenericRepository<Event>> mock;
    fakeit::When(Method(mock, GetAll)).AlwaysReturn(events_list);
    fakeit::When(Method(mock, Update)).AlwaysReturn(true);
    IGenericRepository<Event>* repo_mock = &mock.get();
    EventManager manager(std::shared_ptr<IGenericRepository<Event>>(repo_mock, [](IGenericRepository<Event>* ){}));

    SECTION("EventManager is updating when id exists in repository")
    {
        //Arrange
        auto event = std::make_shared<const Event>("00000000-0000-0000-0000-000000000002", "third_again", 4, 7);

        //Act
        bool result = manager.Update(event);

        //Assert
        REQUIRE(result == true);
    }


    SECTION("EventManager is not updating when id does not exists in repository")
    {
        //Arrange
        auto event = std::make_shared<const Event>("00000000-0000-0000-0000-000000000004", "fourth", 1, 2);

        //Act
        bool result = manager.Update(event);

        //Assert
        REQUIRE(result == false);
    }
}

TEST_CASE("EventManager::Delete can delete event existing in repository")
{
    //Arrange
    std::vector<std::shared_ptr<const Event>> events_list
    {
        std::make_shared<const Event>("00000000-0000-0000-0000-000000000001", "first", 1, 2),
        std::make_shared<const Event>("", "second", 1, 2),
        std::make_shared<const Event>("", "third", 1, 2)
    };

    fakeit::Mock<IGenericRepository<Event>> mock;
    fakeit::When(Method(mock, GetAll)).AlwaysReturn(events_list);
    fakeit::When(Method(mock, Delete)).AlwaysReturn(true);
    IGenericRepository<Event>* repo_mock = &mock.get();
    EventManager manager(std::shared_ptr<IGenericRepository<Event>>(repo_mock, [](IGenericRepository<Event>* ){}));

    SECTION("Manager is deleting if event with given id exists in repository")
    {
        //Act
        bool result = manager.Delete("00000000-0000-0000-0000-000000000001");

        //Assert
        REQUIRE(result == true);
    }

    SECTION("Manager is not deleting if event with given id does not exist in repository")
    {
        //Act
        bool result = manager.Delete("00000000-0000-0000-0000-000000000002");

        //Assert
        REQUIRE(result == false);
    }
}