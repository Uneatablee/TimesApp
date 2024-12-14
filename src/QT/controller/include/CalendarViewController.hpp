#pragma once

class DateTimeGetter;
class CalendarView;

class CalendarViewController
{
public:
    CalendarViewController(DateTimeGetter* date_time_getter_api, CalendarView* calendar_view);

private:
    DateTimeGetter* m_date_time_getter_api;
    CalendarView* m_calendar_view;
};