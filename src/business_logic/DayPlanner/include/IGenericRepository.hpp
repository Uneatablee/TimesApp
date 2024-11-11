#pragma once
#include <vector>
#include <type_traits>
#include "Event.hpp"
#include "BaseEntity.hpp"

namespace dp_business_logic::DayPlanner
{
    template<typename T>
    requires std::is_base_of<BaseEntity, T>::value
    class IGenericRepository
    {
    public:
        virtual bool Add(T*) = 0;
        virtual std::vector<T*> GetAll() = 0;
        virtual T* GetById(unsigned int) = 0;
        virtual bool Update(T*) = 0;
        virtual bool Delete(unsigned int) = 0;
    };
}