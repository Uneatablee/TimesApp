#pragma once
#include "CustomDomainException.hpp"

namespace dp_business_logic::DayPlanner
{
    class IdFormatErrorException final : public CustomDomainException
    {
    public:
        IdFormatErrorException()
        {
            m_exception_message = "Base entity Id's format is invalid";
        }

        IdFormatErrorException(char* message) : m_exception_message(message){}

        const char* what() const noexcept override
        {
            return m_exception_message;
        }

    private:
        const char* m_exception_message;
    };
}