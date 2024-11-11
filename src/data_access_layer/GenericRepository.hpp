#pragma once
#include "IGenericRepository.hpp"
#include "Event.hpp"
#include "BaseEntity.hpp"
#include <vector>
#include <type_traits>
#include <memory>

//REFACTOR TO A SMART POINTERS

using namespace dp_business_logic::DayPlanner;

namespace data_access_layer
{
    template<typename T>
    concept IsBase = std::is_base_of<BaseEntity, T>::value;

    template<IsBase T>
    class GenericRepository : virtual public dp_business_logic::DayPlanner::IGenericRepository<T>
    {

    public:

        bool Add(T*) override;
        bool Delete(unsigned int) override;
        bool Update(T*) override;
        std::vector<T*> GetAll() override;
        T* GetById(unsigned int) override;
    private:

        std::vector<T*> m_events_data{};
    };


    //DEFINITIONS----------------->
    template<IsBase T>
    bool GenericRepository<T>::Add(T* event)
    {
        m_events_data.push_back(event);
        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Delete(unsigned int id)
    {
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](const BaseEntity* event)
        {return event -> GetId() == id;});

        auto index = iter - m_events_data.begin();
        m_events_data.erase(m_events_data.begin() + index);
        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Update(T* event)
    {
        auto id = event -> GetId();
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](const BaseEntity* event)
        {return event -> GetId() == id;});

        *iter = event;

        return true;
    }

    template<IsBase T>
    std::vector<T*> GenericRepository<T>::GetAll()
    {
        return m_events_data;
    }

    template<IsBase T>
    T* GenericRepository<T>::GetById(unsigned int id)
    {
        auto iter = std::find_if(m_events_data.begin(), m_events_data.end(), [id](const BaseEntity* event)
        {return event -> GetId() == id;});


        return *iter;
    }
}
