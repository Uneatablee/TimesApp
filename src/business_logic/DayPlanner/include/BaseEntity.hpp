#pragma once
#include <string>
#include "IHappening.hpp"

namespace dp_business_logic::DayPlanner
{
    class BaseEntity : virtual public IHappening
    {

    protected:
        BaseEntity(std::string id, std::string name, long long end_epoch);

    public:

        virtual ~BaseEntity() = default;
        bool SetId(std::string id) override;
        std::string GetId() const override;
        std::string IdGen() override;

        long long GetEndEpoch() const;
        std::string GetName() const;
        bool SetName(std::string name);

    private:
        std::string m_id;
        std::string m_name;
        long long m_end_epoch;
    };
    //For common Task, Event and Reminder implementations + GenericRepo base
}