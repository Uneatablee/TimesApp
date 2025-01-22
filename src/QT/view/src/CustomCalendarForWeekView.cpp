#include "../include/CustomCalendarForWeekView.hpp"
#include "QPainter"


CustomCalendarForWeekView::CustomCalendarForWeekView()
{
    this -> setStyleSheet
    (
        R"(
            QTableView
            {
                background-color: #ffffff;
                border: none;
            }

            QTableCornerButton::section
            {
                background: transparent;
                border: none;
            }
        )"
    );
}

void CustomCalendarForWeekView::paintEvent(QPaintEvent* event)
{
    QTableView::paintEvent(event);

    for(auto &elem : m_events_print_queue)
    {
        //drawEventTile(1,1,4, QColor("#d0d4f3"));
    }

    drawHourMark();
}

void CustomCalendarForWeekView::drawEventTile(int column_index, int event_cell_start_index, int event_cell_end_index, QColor color)
{
    QPainter painter(this -> viewport());

    painter.setRenderHint(QPainter::Antialiasing);

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
    painter.setPen(QColor(color));
    painter.setBrush(QColor(color));
    painter.drawRoundedRect(rect, 10, 10);
    painter.setPen(QColor("#ffffff"));
    painter.setFont(font);
    painter.drawText(rect.topLeft().x() + 7, rect.topLeft().y() + 17 ,"New Event");
    painter.restore();
}

bool CustomCalendarForWeekView::setHourMark(std::tuple<uint8_t, uint8_t> hour_mark)
{
    m_hour_mark = hour_mark;
    return true;
}

void CustomCalendarForWeekView::drawHourMark()
{
    QPainter painter(this -> viewport());
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor("#8474fb"));
    pen.setWidth(1);
    painter.setPen(pen);

    auto row_height = rowHeight(1);
    QRect rect{};
    for(int col = 0; col < 7; col++)
    {
        QRect cell_rect = visualRect(model() -> index(std::get<0>(m_hour_mark), col));
        rect = rect.united(cell_rect);
    }

    double minutes_in_pixels = row_height / 60.0;
    auto offset = minutes_in_pixels * std::get<1>(m_hour_mark);

    painter.drawLine(rect.left(), rect.top() + offset, rect.right(), rect.top() + offset);
}

bool CustomCalendarForWeekView::AddDrawableEvent(
    std::string name, unsigned int year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute)
    {
        DrawableEvent new_drawable_event = {
            name,
            year,
            month,
            day,
            hour,
            minute
        };
        m_events_print_queue.emplace_back(new_drawable_event);

        return true;
    }