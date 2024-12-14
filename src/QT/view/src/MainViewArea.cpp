#include "../include/MainViewArea.hpp"
#include "../include/CalendarView.hpp"
#include "../include/TasksEventsView.hpp"
#include "../include/TasksGroupView.hpp"
#include "../include/MonthView.hpp"
#include "../include/TopUtilityBar.hpp"
#include "QHBoxLayout"


MainViewArea::MainViewArea(
    CalendarView* calendar_view,
    MonthView* month_view,
    TasksEventsView* tasks_view,
    TasksGroupView* tasks_group_panel,
    TopUtilityBar* top_utility_bar)
{
    QVBoxLayout* home_page_layout = new QVBoxLayout(this);

    top_utility_bar -> setParent(this);
    top_utility_bar -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget* main_area = new QWidget(this);
    main_area  -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout* main_area_layout = new QHBoxLayout(main_area);
    main_area_layout -> setContentsMargins(0,0,0,0);

    //tasks group view
    tasks_group_panel -> setParent(this);
    tasks_group_panel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //calendar and tasks view
    calendar_view -> setParent(this);
    calendar_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto right_panel = new QWidget(this);
    auto right_panel_layout = new QVBoxLayout(right_panel);
    right_panel_layout -> setContentsMargins(0,0,0,0);

    tasks_view -> setParent(this);
    tasks_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //month view
    month_view -> setParent(this);
    month_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    month_view -> setProperty("class", "tasks-view");

    right_panel_layout -> addWidget(tasks_group_panel);
    right_panel_layout -> addWidget(month_view);
    right_panel_layout -> setStretch(0,7);
    right_panel_layout -> setStretch(1,3);

    main_area_layout -> addWidget(tasks_view);
    main_area_layout -> addWidget(calendar_view);
    main_area_layout -> addWidget(right_panel);

    main_area_layout -> setStretch(0, 1);
    main_area_layout -> setStretch(1, 7);
    main_area_layout -> setStretch(2, 2);

    home_page_layout -> addWidget(top_utility_bar);
    home_page_layout -> addWidget(main_area);

    home_page_layout -> setStretch(0,1);
    home_page_layout -> setStretch(1,9);
}