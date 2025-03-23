#include "../include/BaseEntity.hpp"
#include <string>
#include "../include/HelperFunctions.hpp"
#include <regex>
#include "../include/IdFormatErrorException.hpp"


namespace dp_business_logic::DayPlanner
{
    BaseEntity::BaseEntity(std::string id, std::string name, long long end_epoch)
        : m_name(name), m_end_epoch(end_epoch)
    {
        m_id = id == "" ? IdGen() : id;
        ValidateId(m_id);
    }

    std::string BaseEntity::GetId() const
    {
        return m_id;
    }

    bool BaseEntity::SetId(std::string id)
    {
        ValidateId(id);
        m_id = id;
        return true;
    }

    long long BaseEntity::GetEndEpoch() const
    {
        return m_end_epoch;
    }

    std::string BaseEntity::GetName() const
    {
        return m_name;
    }

    bool BaseEntity::SetName(std::string name)
    {
        m_name = name;
        return true;
    }

    void BaseEntity::ValidateId(std::string id)
    {
        const std::regex uuid_template("^[a-zA-Z0-9]{8}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{12}$");
        if(!std::regex_match(id, uuid_template))
        {
            throw IdFormatErrorException();
        }
    }
}