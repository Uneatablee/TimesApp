#include "../include/CalendarViewController.hpp"
#include "../../view/include/CalendarView.hpp"

#include <tuple>
#include <string>
#include <iostream>
#include <map>

#include "IDateTimeGetter.hpp"
#include "IGenericRepository.hpp"
#include "GenericRepository.hpp"


CalendarViewController::CalendarViewController(
    IDateTimeGetter* date_time_getter_api)
        : m_date_time_getter_api(date_time_getter_api)
{
    m_current_day = std::get<2>(m_date_time_getter_api -> GetCurrentYearMonthDay());
    m_current_minute = std::get<1>(m_date_time_getter_api -> GetCurrentHourMinute());
    m_current_hour = std::get<0>(m_date_time_getter_api -> GetCurrentHourMinute());

    m_date_changes_signal_timer = new QTimer();
    connect(m_date_changes_signal_timer, &QTimer::timeout, this, &CalendarViewController::CheckDate);
    m_date_changes_signal_timer -> start(1000);

    m_event_generic_repository = std::make_shared<data_access_layer::dal::memory::GenericRepository<Event>>();
    m_event_manager = std::make_unique<EventManager>(m_event_generic_repository);
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
    auto date_fetched = std::get<2>(m_date_time_getter_api -> GetCurrentYearMonthDay());
    auto time_fetched_minute = std::get<1>(m_date_time_getter_api -> GetCurrentHourMinute());
    auto time_fetched_hour = std::get<0>(m_date_time_getter_api -> GetCurrentHourMinute());

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
    return m_date_time_getter_api -> GetCurrentDayNumber();
}

uint8_t CalendarViewController::GetDay(int day_change_count = 0, int day = 0, int month = 0, int year = 0)
{
    auto current_ymd = m_date_time_getter_api -> GetCurrentDate_YMDFormat();
    if(year != 0)
    {
        return m_date_time_getter_api -> GetOffsetDayDate(m_date_time_getter_api -> GetYMD(day, month, year), day_change_count);
    }

    if(day_change_count == 0)
    {
        return std::get<2>(m_date_time_getter_api -> GetCurrentYearMonthDay());
    }

    return m_date_time_getter_api -> GetOffsetDayDate(current_ymd, day_change_count);
}

std::map<unsigned int, std::string> CalendarViewController::GenerateWeekMap(int weeks_offset_count = 0)
{

    auto day_number = m_date_time_getter_api -> GetCurrentDayNumber();
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
    auto month_number = m_date_time_getter_api -> GetMonthFromOffset(day_offset);

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
        return std::get<0>(m_date_time_getter_api -> GetCurrentYearMonthDay());
    }

    return m_date_time_getter_api -> GetYearFromOffset(day_offset);
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
    auto sec_start = m_date_time_getter_api -> GetSecondsFromEpochFromString(start);
    auto sec_end = m_date_time_getter_api -> GetSecondsFromEpochFromString(end);

    //event add
    m_event_manager -> Add(std::make_shared<Event>(0, event_name, sec_start, sec_end));
    return true;
}

std::tuple<uint8_t, uint8_t> CalendarViewController::GetHourMinute()
{
    return m_date_time_getter_api -> GetCurrentHourMinute();
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
        auto start_date = m_date_time_getter_api -> ConvertEpochYearMonthDay(elem -> GetStartEpoch());
        auto end_date = m_date_time_getter_api -> ConvertEpochYearMonthDay(elem -> GetEndEpoch());
        auto start_time = m_date_time_getter_api -> ConvertEpochHourMinute(elem -> GetStartEpoch());
        auto end_time = m_date_time_getter_api -> ConvertEpochHourMinute(elem -> GetEndEpoch());
        m_custom_week_calendar -> AddDrawableEvent(start_date, end_date, start_time, end_time, elem -> GetName());
    }
        qDebug() << "Events Retrieved";

    return true;
}