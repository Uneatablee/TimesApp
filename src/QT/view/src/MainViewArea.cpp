#include "../include/MainViewArea.hpp"
#include "../include/CalendarView.hpp"
#include "../include/TasksEventsView.hpp"
#include "../include/TasksGroupView.hpp"
#include "../include/MonthView.hpp"
#include "../include/TopUtilityBar.hpp"
#include "QHBoxLayout"


MainViewArea::MainViewArea(QWidget* parent, QWidget* main) : QWidget(parent), main_window(main)
{
    QVBoxLayout* home_page_layout = new QVBoxLayout(this);

    TopUtilityBar* top_utility_bar = new TopUtilityBar(this);
    top_utility_bar -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget* main_area = new QWidget(this);
    main_area  -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout* main_area_layout = new QHBoxLayout(main_area);
    main_area_layout -> setContentsMargins(0,0,0,0);

    //tasks group view
    TasksGroupView* tasks_group_panel = new TasksGroupView(this);
    tasks_group_panel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //calendar and tasks view
    CalendarView* calendar_view = new CalendarView(this);
    calendar_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto right_panel = new QWidget(this);
    auto right_panel_layout = new QVBoxLayout(right_panel);
    right_panel_layout -> setContentsMargins(0,0,0,0);

    TasksEventsView* tasks_view = new TasksEventsView(this);
    tasks_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //month view
    MonthView* month_view = new MonthView(this);
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