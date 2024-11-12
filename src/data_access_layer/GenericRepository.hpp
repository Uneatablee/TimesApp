#pragma once
#include "IGenericRepository.hpp"
#include "Event.hpp"
#include "BaseEntity.hpp"
#include <vector>
#include <type_traits>
#include <memory>

using namespace dp_business_logic::DayPlanner;

namespace data_access_layer
{
    template<typename T>
    concept IsBase = std::is_base_of<BaseEntity, T>::value;

    template<IsBase T>
    class GenericRepository : public virtual dp_business_logic::DayPlanner::IGenericRepository<T>
    {

    public:

        bool Add(std::shared_ptr<T>) override;
        bool Delete(unsigned int) override;
        bool Update(std::shared_ptr<T>) override;
        std::vector<std::shared_ptr<T>> GetAll() override;
        std::shared_ptr<T> GetById(unsigned int) override;
    private:

        std::vector<std::shared_ptr<T>> m_events_data{};
    };


    //DEFINITIONS----------------->
    template<IsBase T>
    bool GenericRepository<T>::Add(std::shared_ptr<T> event)
    {
        m_events_data.emplace_back(event);
        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Delete(unsigned int id)
    {
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](std::shared_ptr<T> event)
        {return event -> GetId() == id;});

        auto index = iter - m_events_data.begin();
        m_events_data.erase(m_events_data.begin() + index);
        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Update(std::shared_ptr<T> event)
    {
        auto id = event -> GetId();
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](std::shared_ptr<T> event)
        {return event -> GetId() == id;});

        *iter = event;

        return true;
    }

    template<IsBase T>
    std::vector<std::shared_ptr<T>> GenericRepository<T>::GetAll()
    {
        return m_events_data;
    }

    template<IsBase T>
    std::shared_ptr<T> GenericRepository<T>::GetById(unsigned int id)
    {
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](std::shared_ptr<T> event)
        {return event -> GetId() == id;});


        return *iter;
    }
}
