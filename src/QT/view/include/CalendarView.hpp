#pragma once
#include "QWidget"
#include "QStandardItemModel"
#include "QLabel"

#include "../../controller/include/CalendarViewController.hpp"
#include "CalendarCustomHeader.hpp"

#include <map>
#include <string>

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(CalendarViewController*);
    void NextDayInsert();
    void PreviousDayInsert();
    void WeekViewUpdate();

public slots:
    void OnDateChanged(int changed_date);

private:

    CalendarViewController* m_calendar_view_controller;
    std::map<unsigned int, std::string> m_weekday_map;
    QStandardItemModel* m_model;
    QLabel* m_month_label;
    CalendarCustomHeader* m_custom_header;
    //QTableView* m_table;
};
