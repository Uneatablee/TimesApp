#include "../include/MainViewArea.hpp"
#include "../include/CalendarView.hpp"
#include "../include/TasksEventsView.hpp"
#include "../include/TasksGroupView.hpp"
#include "../include/MonthView.hpp"
#include "QHBoxLayout"


MainViewArea::MainViewArea(QWidget* parent, QWidget* main) : QWidget(parent), main_window(main)
{
    QHBoxLayout* main_area_layout = new QHBoxLayout(this);

    //tasks group view
    TasksGroupView* tasks_group_panel = new TasksGroupView(this);
    tasks_group_panel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //calendar and tasks view
    CalendarView* calendar_view = new CalendarView(this);
    calendar_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto right_panel = new QWidget(this);
    auto right_panel_layout = new QVBoxLayout(right_panel);
    right_panel_layout -> setContentsMargins(0,0,0,0);
    right_panel_layout -> setSpacing(0);

    TasksEventsView* tasks_view = new TasksEventsView(this);
    tasks_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //month view
    MonthView* month_view = new MonthView(this);
    month_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    month_view -> setProperty("class", "tasks-view");

    right_panel_layout -> addWidget(tasks_view);
    right_panel_layout -> addWidget(month_view);
    right_panel_layout -> setStretch(0,8);
    right_panel_layout -> setStretch(1,2);

    main_area_layout -> addWidget(tasks_group_panel);
    main_area_layout -> addWidget(calendar_view);
    main_area_layout -> addWidget(right_panel);

    main_area_layout -> setStretch(0, 2);
    main_area_layout -> setStretch(1, 7);
    main_area_layout -> setStretch(2, 1);
}