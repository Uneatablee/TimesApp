#pragma once
#include "QWidget"
#include "QStandardItemModel"
#include "QLabel"
#include "QPushButton"

#include "../../controller/include/CalendarViewController.hpp"
#include "CalendarCustomHeader.hpp"

#include <map>
#include <string>

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(CalendarViewController*);
    void NextWeekInsert();
    void PreviousWeekInsert();
    void CurrentWeekInsert();
    void WeekViewUpdate(int weeks_offset_count = 0);
    // void NextDayInsert();
    // void PreviousDayInsert();
    void NewEventDialog();


public slots:
    void OnDateChanged();

private:

    CalendarViewController* m_calendar_view_controller;
    std::map<unsigned int, std::string> m_weekday_map;
    QStandardItemModel* m_model;
    QLabel* m_month_label;
    QLabel* m_year_label;
    CalendarCustomHeader* m_custom_header;
    bool m_isViewMoved = false;
    int m_weeks_offset = 0;
    QPushButton* m_week_view_button;
    QPushButton* m_day_view_button;
    QPushButton* m_month_view_button;
};
