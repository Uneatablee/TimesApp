#pragma once
#include <string>

namespace dp_business_logic::DayPlanner
{
    class IHappening
    {
    public:

        IHappening() = default;
        virtual ~IHappening() = default;

        IHappening(const IHappening& obj) = default;
        IHappening& operator=(const IHappening& obj) = default;

        IHappening(IHappening&& obj) = default;
        IHappening& operator=(IHappening&& obj) = default;

        virtual std::string IdGen() = 0;
        virtual bool SetId(std::string) = 0;
        virtual std::string GetId() const = 0;
    };
}