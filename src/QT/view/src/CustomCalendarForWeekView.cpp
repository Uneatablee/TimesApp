#include "../include/CustomCalendarForWeekView.hpp"
#include "QPainter"

void CustomCalendarForWeekView::paintEvent(QPaintEvent* event)
{
    QTableView::paintEvent(event);
    QPainter painter(this -> viewport());

    painter.setRenderHint(QPainter::Antialiasing);

    int event_cell_start_index = 1;
    int event_cell_end_index = 4;
    int column_index = 1;

    QRect rect{};
    for(int row = event_cell_start_index; row <= event_cell_end_index; row++)
    {
        QRect cell_rect = visualRect(model() -> index(row, column_index));
        rect = rect.united(cell_rect);
    }

    QFont font{};
    font.setBold(1);
    font.setWeight(QFont::DemiBold);
    font.setPointSize(12);

    rect.adjust(2,2,-2,-2);

    painter.save();
    painter.setPen(QColor("#8474fb"));
    painter.setBrush(QColor("#8474fb"));
    painter.drawRoundedRect(rect, 10, 10);
    painter.setPen(QColor("#ffffff"));
    painter.setFont(font);
    painter.drawText(rect.topLeft().x() + 7, rect.topLeft().y() + 17 ,"New Event");
    painter.restore();

}