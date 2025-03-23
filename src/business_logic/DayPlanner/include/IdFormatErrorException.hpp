#pragma once
#include "CustomDomainException.hpp"

namespace dp_business_logic::DayPlanner
{
    class IdFormatErrorException final : public CustomDomainException
    {
    public:
        IdFormatErrorException() : CustomDomainException("Base entity has invalid id form."){}
        IdFormatErrorException(const char* message) : CustomDomainException(message){}

    private:
    };
}