#include "../include/CustomCalendarForWeekView.hpp"
#include "QPainter"
#include "QHeaderView"
#include <QString>

#include "../../controller/include/CalendarViewController.hpp"

CustomCalendarForWeekView::CustomCalendarForWeekView(CalendarViewController* calendar_view_controller) : m_calendar_view_controller(calendar_view_controller)
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

            QTableView::item:selected
            {
                background-color: #ffffff;
            }
        )"
    );
}

void CustomCalendarForWeekView::paintEvent(QPaintEvent* event)
{
    QTableView::paintEvent(event);

    auto week_day = std::stoi(((horizontalHeader() -> model() -> headerData(0, Qt::Horizontal).toString()).section("\n", 1, 1)).toStdString());
    auto start_day_for_drawing = week_day;
    auto curr_month = GetMonthNumber(m_current_month.toStdString());
    auto month_increased =  false;

    for(auto &elem : m_events_print_queue)
    {
        for(int day_number = 0; day_number < 7; day_number++)
        {
            if(std::get<2>(elem.start_date) < week_day)
            {
                curr_month++;
                month_increased = true;
            }

            if(std::get<0>(elem.start_date) == static_cast<unsigned int>(m_current_year.toInt())
            && std::get<1>(elem.start_date) == curr_month
            && std::get<2>(elem.start_date) == m_calendar_view_controller -> GetDay(day_number, week_day, month_increased ? curr_month - 1 : curr_month, m_current_year.toInt()))
            {
                if(!month_increased)
                {
                    drawEventTile(std::get<2>(elem.start_date) - start_day_for_drawing, std::get<0>(elem.start_time), std::get<0>(elem.end_time) - 1, QColor("#8474fb"), elem.name);
                }
                else
                {
                    auto last_day = m_calendar_view_controller -> GetDay(6, week_day, curr_month - 1, m_current_year.toInt());
                    auto diff = last_day - std::get<2>(elem.start_date);
                    drawEventTile(6 - diff, std::get<0>(elem.start_time), std::get<0>(elem.end_time) - 1, QColor("#d0d4f3"), elem.name);
                }
            }

            if(month_increased)
            {
                curr_month--;
            }
        }

        month_increased = false;
    }

    drawHourMark();
}

void CustomCalendarForWeekView::drawEventTile(int column_index, int event_cell_start_index, int event_cell_end_index, QColor color, std::string name)
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
    painter.drawText(rect.topLeft().x() + 7, rect.topLeft().y() + 17 , name.c_str());
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

bool CustomCalendarForWeekView::setMonthYear(QString month, QString year)
{
    m_current_month = month;
    m_current_year = year;
    return true;
}

uint8_t CustomCalendarForWeekView::GetMonthNumber(std::string month_name)
{
    if (month_name == "January")
        return 1;
    else if (month_name == "February")
        return 2;
    else if (month_name == "March")
        return 3;
    else if (month_name == "April")
        return 4;
    else if (month_name == "May")
        return 5;
    else if (month_name == "June")
        return 6;
    else if (month_name == "July")
        return 7;
    else if (month_name == "August")
        return 8;
    else if (month_name == "September")
        return 9;
    else if (month_name == "October")
        return 10;
    else if (month_name == "November")
        return 11;
    else if (month_name == "December")
        return 12;

    return 0;
}

bool CustomCalendarForWeekView::ClearDrawableEventsQueue()
{
    m_events_print_queue.clear();
    return true;
}