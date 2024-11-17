#pragma once
#include <SQLiteCpp/SQLiteCpp.h>
#include "IGenericRepository.hpp"

namespace data_access_layer::dal::sqlite
{
    template<typename T>
    concept IsBase = std::is_base_of<BaseEntity, T>::value;

    template<IsBase T>
    class GenericRepository : public virtual dp_business_logic::DayPlanner::IGenericRepository<T>
    {
    public:
        GenericRepository(std::string path);



    private:
        SQLite::Database database;   ///< Database connection
    };
}