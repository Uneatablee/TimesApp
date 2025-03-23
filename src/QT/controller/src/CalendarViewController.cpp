#include "../include/CalendarViewController.hpp"
#include "../../view/include/CalendarView.hpp"

#include <tuple>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <filesystem>

#include "IDateTimeGetter.hpp"
#include "IGenericRepository.hpp"
//#include "GenericRepository.hpp"
#include "DateTime.hpp"


CalendarViewController::CalendarViewController(
    IDateTimeGetter* date_time_getter_api,
    IGenericRepository<Event>* event_generic_repository,
    EventManager* event_manager)
        : m_date_time_getter_api(date_time_getter_api),
        m_event_generic_repository(event_generic_repository),
        m_event_manager(event_manager)
{
    m_date_time = m_date_time_getter_api -> GetCurrentLocalDateTime();
    m_current_day = std::get<2>(m_date_time.GetYearMonthDay());
    m_current_minute = std::get<1>(m_date_time.GetHourMinute());
    m_current_hour = std::get<0>(m_date_time.GetHourMinute());

    m_date_changes_signal_timer = new QTimer(this);
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

void CalendarViewController::CheckDate()
{
    auto date_time = m_date_time_getter_api -> GetCurrentLocalDateTime();
    auto date_fetched = std::get<2>(date_time.GetYearMonthDay());
    auto time_fetched_minute = std::get<1>(date_time.GetHourMinute());
    auto time_fetched_hour = std::get<0>(date_time.GetHourMinute());

    if(m_current_day != date_fetched)
    {
        m_current_day = date_fetched;
        emit DateChanged(m_current_day);
    }

    if(m_current_minute != time_fetched_minute || m_current_hour != time_fetched_hour)
    {
        m_current_minute = time_fetched_minute;
        m_current_hour = time_fetched_hour;
        emit TimeChanged(m_current_minute);
    }
}

uint8_t CalendarViewController::GetWeekDayNumber()
{
    return m_date_time.GetDayNumber();
}

uint8_t CalendarViewController::GetDay(int day_change_count = 0, int day = 0, int month = 0, int year = 0)
{
    auto date = DateTime(day, month, year);
    auto current_date = m_date_time_getter_api -> GetCurrentLocalDateTime();
    if(year != 0)
    {
        return date.GetOffsetDayDate(day_change_count);
    }

    if(day_change_count == 0)
    {
        return std::get<2>(current_date.GetYearMonthDay());
    }

    return current_date.GetOffsetDayDate(day_change_count);
}

std::map<unsigned int, std::string> CalendarViewController::GenerateWeekMap(int weeks_offset_count = 0)
{
    auto day_number = m_date_time.GetDayNumber();
    std::string week_day_names[] = {"Mon\n", "Tue\n", "Wed\n", "Thu\n", "Fri\n", "Sat\n", "Sun\n"};
    std::map<unsigned int, std::string> week;
    unsigned int day_key = 0;
    for(int curr_day = -day_number + 1; curr_day <= 7 - day_number; curr_day++)
    {
        week[day_key] = (week_day_names[day_key] + std::to_string(GetDay(curr_day + weeks_offset_count * 7)));
        day_key++;
    }

    return week;
}

std::string CalendarViewController::GetCurrentMonthName(int day_offset)
{
    auto month_number = m_date_time.GetMonthFromOffset(day_offset);

    switch(month_number)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "October";
        case 10:
            return "September";
        case 11:
            return "November";
        case 12:
            return "December";
    }
        return std::string();
}

unsigned int CalendarViewController::GetYear(int day_offset)
{
    if(day_offset == 0)
    {
        return std::get<0>(m_date_time.GetYearMonthDay());
    }

    return m_date_time.GetYearFromOffset(day_offset);
}

bool CalendarViewController::addEvent(
    QString start_date,
    QString end_date,
    QString start_hour,
    QString end_hour,
    std::string event_name,
    std::string event_group)
{
    std::string start = (start_date.toStdString() + " " + start_hour.toStdString());
    std::string end = (end_date.toStdString() + " " + end_hour.toStdString());
    auto sec_start = m_date_time.GetSecondsFromEpochFromString(start);
    auto sec_end = m_date_time.GetSecondsFromEpochFromString(end);

    //event add
    auto event = std::make_shared<Event>("", event_name, sec_start, sec_end);
    m_event_manager -> Add(event);
    return true;
}

std::tuple<uint8_t, uint8_t> CalendarViewController::GetHourMinute()
{
    return m_date_time.GetHourMinute();
}

bool CalendarViewController::SetCustomWeekCalendar(CustomCalendarForWeekView* calendar)
{
    m_custom_week_calendar = calendar;
    return true;
}

bool CalendarViewController::RetrieveDrawableEventsQueue()
{
    auto events = m_event_manager -> GetAll();
    m_custom_week_calendar -> ClearDrawableEventsQueue();
    for(auto &elem : events)
    {
        auto start_date = m_date_time.ConvertEpochYearMonthDay(elem -> GetStartEpoch());
        auto end_date = m_date_time.ConvertEpochYearMonthDay(elem -> GetEndEpoch());
        auto start_time = m_date_time.ConvertEpochHourMinute(elem -> GetStartEpoch());
        auto end_time = m_date_time.ConvertEpochHourMinute(elem -> GetEndEpoch());

        m_custom_week_calendar -> AddDrawableEvent(start_date, end_date, start_time, end_time, elem -> GetName());
    }

    return true;
}