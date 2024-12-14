#include "../include/MonthView.hpp"
#include "QVBoxLayout"

MonthView::MonthView()
{
    auto month_layout = new QVBoxLayout(this);
    month_layout -> setContentsMargins(0,0,0,0);

    auto month_widget = new QWidget(this);
    month_widget -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    month_widget -> setProperty("class", "month-view");

    month_layout -> addWidget(month_widget);
}