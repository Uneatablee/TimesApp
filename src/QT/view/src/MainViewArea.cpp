#include "../include/MainViewArea.hpp"
#include "../include/CalendarView.hpp"
#include "QHBoxLayout"


MainViewArea::MainViewArea(QWidget* parent, QWidget* main) : QWidget(parent), main_window(main)
{
    QHBoxLayout* main_area_layout = new QHBoxLayout(this);
    CalendarView* calendar_view = new CalendarView(this);
    calendar_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    main_area_layout -> addWidget(calendar_view);
    // main_area_layout -> addStretch();
}