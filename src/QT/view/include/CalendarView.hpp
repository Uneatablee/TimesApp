#pragma once
#include "QWidget"

#include "../../controller/include/CalendarViewController.hpp"

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(CalendarViewController*);

public slots:
    void OnDateChanged(int changed_date);

private:

    CalendarViewController* m_calendar_view_controller;
    uint8_t m_current_day;
    uint8_t m_weekday_number;
};
