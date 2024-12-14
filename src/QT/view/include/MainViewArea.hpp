#pragma once
#include "QWidget"
#include "CalendarView.hpp"
#include "MonthView.hpp"
#include "TasksEventsView.hpp"
#include "TasksGroupView.hpp"
#include "TopUtilityBar.hpp"

class MainViewArea : public QWidget
{
    Q_OBJECT
public:

    MainViewArea(CalendarView*, MonthView*, TasksEventsView*, TasksGroupView*, TopUtilityBar*);

private:
};