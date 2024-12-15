#include "../include/CalendarViewController.hpp"
#include "IDateTimeGetter.hpp"
#include "../../view/include/CalendarView.hpp"

CalendarViewController::CalendarViewController(IDateTimeGetter* date_time_getter_api, CalendarView* calendar_view)
    : m_date_time_getter_api(date_time_getter_api), m_calendar_view(calendar_view)
{

}