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
    auto date_fetched = std::get<2>(m_date_time_getter_api -> GetCurrentYearMonthDay());
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

uint8_t CalendarViewController::GetDay(int day_change_count)
{
    auto current_ymd = m_date_time_getter_api -> GetCurrentDate_YMDFormat();
    if(day_change_count == 0)
    {
        return std::get<2>(m_date_time_getter_api -> GetCurrentYearMonthDay());
    }

    if(day_change_count < 0)
    {
        return m_date_time_getter_api -> GetPastDayDate(current_ymd, day_change_count * -1);
    }

    return m_date_time_getter_api -> GetFutureDayDate(current_ymd, day_change_count);
}

std::map<unsigned int, std::string> CalendarViewController::GenerateWeekMap()
{
    auto day_number = m_date_time_getter_api -> GetCurrentDayNumber();
    std::string week_day_names[] = {"Mon\n", "Tue\n", "Wed\n", "Thu\n", "Fri\n", "Sat\n", "Sun\n"};
    std::map<unsigned int, std::string> week;
    unsigned int day_key = 0;
    for(int curr_day = -day_number + 1; curr_day <= 7 - day_number; curr_day++)
    {
        week[day_key] = (week_day_names[day_key] + std::to_string(GetDay(curr_day)));
        day_key++;
    }

    return week;
}