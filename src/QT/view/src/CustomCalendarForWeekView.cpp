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
        // drawEventTile(1,1,4, QColor("#d0d4f3"));
    }

        drawEventTile(4,7,9, QColor("#d0d4f3"));
        drawEventTile(5,7,9, QColor("#c5bdfe"));
        drawEventTile(7,9,12, QColor("#c5bdfe"));
        drawEventTile(6,12,14, QColor("#c5bdfe"));
        drawEventTile(2,8,13, QColor("#c5bdfe"));
        drawEventTile(2,14,16, QColor("#d0d4f3"));
        drawEventTile(3,9,14, QColor("#c5bdfe"));
        drawEventTile(0,7,15, QColor("#d0d4f3"));
        drawEventTile(1,12,14, QColor("#d0d4f3"));
        drawEventTile(4,12,13, QColor("#42378f"));
        drawEventTile(4,14,17, QColor("#c5bdfe"));
        drawEventTile(5,12,14, QColor("#d0d4f3"));
        drawEventTile(1,6,8, QColor("#42378f"));

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
    pen.setWidth(2);
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
    std::tuple<unsigned int, uint8_t, uint8_t> start_date,
    std::tuple<unsigned int, uint8_t, uint8_t> end_date,
    std::tuple<uint8_t, uint8_t> start_time,
    std::tuple<uint8_t, uint8_t> end_time,
    std::string event_name)
    {
        DrawableEvent new_event{start_date, end_date, start_time, end_time, event_name};
        m_events_print_queue.emplace_back(new_event);
        return true;
    }