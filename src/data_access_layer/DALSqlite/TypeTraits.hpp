#pragma once

#include "Event.hpp"
#include "Task.hpp"
#include <string>


//MetaEvent Datas for Generic Repository --------> Refactor into specific events;
namespace data_access_layer::dal::sqlite
{
    template<typename T>
    struct TypeTraits
    {
        static constexpr const char* table_name = "unknown";
    };

    template<>
    struct TypeTraits<dp_business_logic::DayPlanner::Event>
    {
        static constexpr const char* table_name = "events";
    };

    template<>
    struct TypeTraits<dp_business_logic::DayPlanner::Task>
    {
        static constexpr const char* table_name = "tasks";
    };
}
