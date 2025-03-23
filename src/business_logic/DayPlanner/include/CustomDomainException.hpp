#pragma once
#include <exception>

namespace dp_business_logic::DayPlanner
{
    class CustomDomainException : std::exception
    {
    public:
        CustomDomainException() = default;
        virtual ~CustomDomainException() = default;
        virtual const char* what() const noexcept = 0;
    };
}