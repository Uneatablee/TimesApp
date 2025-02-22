#pragma once
#include <string>

namespace dp_business_logic::DayPlanner
{
    class BaseEntity
    {

    public:

        BaseEntity(unsigned int id)
            : m_id(id){};

        virtual ~BaseEntity() = default;

        virtual unsigned int GetId() const
        {
            return m_id;
        }

        virtual long long GetEndSecEpoch() const
        {
            return m_end_sec_from_epoch;
        }

        virtual std::string GetName() const
        {
            return m_name;
        }

    private:
        unsigned int m_id;
        long long m_end_sec_from_epoch;
        std::string m_name;
    };
    //For common Task, Event and Reminder implementations + GenericRepo base
}