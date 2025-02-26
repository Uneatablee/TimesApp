#include "../include/BaseEntity.hpp"
#include <string>
#include "uuid.h"


namespace dp_business_logic::DayPlanner
{
    BaseEntity::BaseEntity(std::string id, std::string name, long long end_epoch)
        : m_id(id == "" ? IdGen() : id), m_name(name), m_end_epoch(end_epoch)
    {}

    std::string BaseEntity::GetId() const
    {
        return m_id;
    }

    bool BaseEntity::SetId(std::string id)
    {
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

    std::string BaseEntity::IdGen()
    {
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        std::mt19937 generator(seq);
        uuids::uuid_random_generator gen{generator};

        uuids::uuid const id = gen();
        return uuids::to_string(id);
    }
}