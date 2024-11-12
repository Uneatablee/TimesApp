#pragma once

namespace dp_business_logic::DayPlanner
{
    class Event;

    class BaseEntity
    {

    public:
        BaseEntity(unsigned int id) : m_id(id){};

        virtual ~BaseEntity() = default;
        virtual unsigned int GetId() const
        {
            return m_id;
        }

    private:
        unsigned int m_id;
    };
    //For common Task and Event implementations
}