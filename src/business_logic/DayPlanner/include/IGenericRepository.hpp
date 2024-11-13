#pragma once
#include <vector>
#include <type_traits>
#include "Event.hpp"
#include "BaseEntity.hpp"
#include <memory>

namespace dp_business_logic::DayPlanner
{
    template<typename T>
    requires std::is_base_of<BaseEntity, T>::value
    class IGenericRepository
    {
    public:

        virtual ~IGenericRepository() = default; //constants restriction
        virtual bool Add(std::shared_ptr<const T>) = 0;
        virtual std::vector<std::shared_ptr<const T>> GetAll() const = 0;
        virtual std::shared_ptr<const T> GetById(unsigned int) const = 0;
        virtual bool Update(std::shared_ptr<const T>) = 0;
        virtual bool Delete(unsigned int) = 0;
    };
}