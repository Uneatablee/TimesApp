#pragma once

class IDateTimeGetter;
class CalendarView;

class CalendarViewController
{
public:
    CalendarViewController(IDateTimeGetter* date_time_getter_api, CalendarView* calendar_view);

private:
    IDateTimeGetter* m_date_time_getter_api;
    CalendarView* m_calendar_view;
};