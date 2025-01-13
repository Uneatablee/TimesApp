#pragma once
#include <string>

namespace dp_business_logic::DayPlanner
{
    class BaseEntity
    {

    public:
        BaseEntity(unsigned int id, int epoch_end, std::string name)
            : m_id(id), m_end_sec_from_epoch(epoch_end), m_name(name){};
        virtual ~BaseEntity() = default;

        virtual unsigned int GetId() const
        {
            return m_id;
        }

        virtual int GetEndSecEpoch() const
        {
            return m_end_sec_from_epoch;
        }

        virtual std::string GetName() const
        {
            return m_name;
        }

    private:
        unsigned int m_id;
        int m_end_sec_from_epoch;
        std::string m_name;
    };
    //For common Task, Event and Reminder implementations + GenericRepo base
}