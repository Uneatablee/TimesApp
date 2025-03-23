#pragma once
#include <string>

namespace dp_business_logic::DayPlanner
{
    class BaseEntity
    {

    protected:
        BaseEntity(std::string id, std::string name, long long end_epoch);

    public:

        virtual ~BaseEntity() = default;
        bool SetId(std::string id);
        std::string GetId() const;

        long long GetEndEpoch() const;
        std::string GetName() const;
        bool SetName(std::string name);

    private:
        std::string m_id;
        std::string m_name;
        long long m_end_epoch;

        void ValidateId(std::string);
};
    //For common Task, Event and Reminder implementations + GenericRepo base
}