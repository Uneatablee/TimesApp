#pragma once
#include "CustomDomainException.hpp"

namespace dp_business_logic::DayPlanner
{
    class IdFormatErrorException final : public CustomDomainException
    {
    public:
        IdFormatErrorException() : CustomDomainException(){}
        IdFormatErrorException(const char* message) : CustomDomainException(message){}

    private:
    };
}