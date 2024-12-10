#include "../include/MainViewArea.hpp"
#include "../include/CalendarView.hpp"
#include "../include/TasksEventsView.hpp"
#include "QHBoxLayout"


MainViewArea::MainViewArea(QWidget* parent, QWidget* main) : QWidget(parent), main_window(main)
{
    QHBoxLayout* main_area_layout = new QHBoxLayout(this);

    CalendarView* calendar_view = new CalendarView(this);
    calendar_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto right_panel = new QWidget(this);
    auto right_panel_layout = new QVBoxLayout(right_panel);
    right_panel_layout -> setSpacing(0);

    TasksEventsView* tasks_view = new TasksEventsView(this);
    tasks_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto month_view = new QWidget(this);
    month_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    month_view -> setProperty("class", "tasks-view");


    right_panel_layout -> addWidget(tasks_view);
    right_panel_layout -> addWidget(month_view);

    main_area_layout -> addWidget(calendar_view);
    main_area_layout -> addWidget(right_panel);

    main_area_layout -> setStretch(0, 9);
    main_area_layout -> setStretch(1, 1);
}