#pragma once
#include "IEventRepository.hpp"
#include <vector>

using namespace dp_business_logic::DayPlanner;

namespace data_access_layer
{

    class EventRepository : virtual public dp_business_logic::DayPlanner::IEventRepository
    {

    public:

        bool Add(Event) override;
        bool Delete() override;
        bool Update(Event) override;
        std::vector<dp_business_logic::DayPlanner::Event> GetAll() override;
    private:

        std::vector<Event> m_events_data{Event(1), Event(2), Event(3), Event(4), Event(5)};
    };

}
