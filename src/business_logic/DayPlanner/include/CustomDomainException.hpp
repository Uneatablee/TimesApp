#pragma once
#include <exception>

namespace dp_business_logic::DayPlanner
{
    class CustomDomainException : std::exception
    {
    public:
        CustomDomainException() = default;
        CustomDomainException(const char* message) : m_message(message){};
        virtual ~CustomDomainException() = default;
        const char* what() const noexcept override
        {
            return m_message;
        }

    private:
        const char* m_message;
    };
}