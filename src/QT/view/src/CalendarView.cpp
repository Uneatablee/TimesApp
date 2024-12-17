#include "../include/CalendarView.hpp"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "QFrame"
#include "QStandardItemModel"
#include "QTableView"
#include "QHeaderView"
#include "QAbstractButton"

#include <map>
#include <string>

CalendarView::CalendarView(CalendarViewController* calendar_view_controller) : m_calendar_view_controller(calendar_view_controller)
{
    QHBoxLayout* general_layout = new QHBoxLayout(this);
    general_layout -> setContentsMargins(0,0,0,0);

    //Calendar view
    auto table = new QTableView(this);

    auto model = new QStandardItemModel(24, 7, this);
    for(int hour = 0; hour < 24; hour++)
    {
        if(hour < 10)
        {
            model -> setHeaderData(hour, Qt::Vertical, QString("0%1:00").arg(hour));
        }
        else
        {
            model -> setHeaderData(hour, Qt::Vertical, QString("%1:00").arg(hour));
        }
    }

    auto week_days = m_calendar_view_controller -> GenerateWeekMap();

    for(int day = 0; day < 7; day++)
    {
        model -> setHeaderData(day, Qt::Horizontal, week_days[day].c_str());
    }

    table -> setModel(model);
    for(int hour = 0; hour < 24; hour++)
    {
        table -> setRowHeight(hour, 60);
    }

    table -> setCornerButtonEnabled(false);
    table -> horizontalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    table -> verticalHeader()-> setSectionResizeMode(QHeaderView::Fixed);
    table -> verticalHeader() -> setDefaultAlignment(Qt::AlignTop);

    const char* vertical_header_style = R"(
            QHeaderView::section
            {
                background-color: #ffffff;
                border: none;
                color: #9c9c9c;
                outline: none;
            }
    )";

    const char* horizontal_header_style = R"(
            QHeaderView::section
            {
                background-color: #ffffff;
                border: none;
                color: #9c9c9c;
                font-size: 16px;
                outline: none;
            }
    )";

    table -> verticalHeader() -> setStyleSheet(vertical_header_style);
    table -> horizontalHeader() -> setStyleSheet(horizontal_header_style);
    table -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    table -> setProperty("class", "calendar-table");

    general_layout -> addWidget(table);
    this -> setLayout(general_layout);

    //controller connection
    connect(m_calendar_view_controller, &CalendarViewController::DateChanged, this, &CalendarView::OnDateChanged);

};

void CalendarView::OnDateChanged(int changed_date)
{
    qDebug() << "\n" << "Changed!!!!!";
}

