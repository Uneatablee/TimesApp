#include "../include/CalendarViewController.hpp"
#include "IDateTimeGetter.hpp"
#include "../../view/include/CalendarView.hpp"
#include <tuple>

CalendarViewController::CalendarViewController(IDateTimeGetter* date_time_getter_api)
    : m_date_time_getter_api(date_time_getter_api)
{
    m_current_day = std::get<2>(GetDate());

    m_date_changes_signal_timer = new QTimer();
    connect(m_date_changes_signal_timer, &QTimer::timeout, this, &CalendarViewController::CheckDate);
    m_date_changes_signal_timer -> start(1000);
}

CalendarViewController::~CalendarViewController()
{
    if(m_date_changes_signal_timer)
    {
        delete m_date_changes_signal_timer;
        m_date_changes_signal_timer = nullptr;
    }
}

std::tuple<unsigned int, uint8_t, uint8_t> CalendarViewController::GetDate()
{
    return m_date_time_getter_api -> GetCurrentYearMonthDay();
}

void CalendarViewController::CheckDate()
{
    auto date_fetched = std::get<2>(GetDate());
    if(m_current_day != date_fetched)
    {
        m_current_day = date_fetched;
        emit DateChanged(m_current_day);
    }
}

uint8_t CalendarViewController::GetWeekDayNumber()
{
    return m_date_time_getter_api -> GetCurrentDayNumber();
}

std::map<unsigned int, const char*> CalendarViewController::GenerateWeekMap()
{
    //Generating starting map for entire week
    return std::map<unsigned int, const char*>();
}