#include "../include/CustomCalendarForWeekView.hpp"
#include "QPainter"

void CustomCalendarForWeekView::paintEvent(QPaintEvent* event)
{
    QTableView::paintEvent(event);
    QPainter painter(this -> viewport());

    painter.setRenderHint(QPainter::Antialiasing);

    //Drawing mechanics --- QLabel/Rounded Rectangle
}