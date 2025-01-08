#include "../include/CalendarView.hpp"
#include "../include/CalendarCustomHeader.hpp"
#include "../include/CustomCalendarForWeekView.hpp"

#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "QFrame"
#include "QStandardItemModel"
#include "QTableView"
#include "QHeaderView"
#include "QAbstractButton"
#include "QPushButton"
#include "QGraphicsDropShadowEffect"
#include "QColor"

#include <map>
#include <string>

CalendarView::CalendarView(CalendarViewController* calendar_view_controller) : m_calendar_view_controller(calendar_view_controller)
{
    QHBoxLayout* general_layout = new QHBoxLayout(this);
    general_layout -> setContentsMargins(0,0,0,0);

    QWidget* calendar_widget = new QWidget(this);
    calendar_widget -> setProperty("class", "calendar-widget");
    calendar_widget -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout* calendar_layout = new QVBoxLayout(calendar_widget);

    calendar_layout -> setSpacing(0);

    //Calendar view
    auto table = new CustomCalendarForWeekView();
    table -> setParent(this);

    m_model = new QStandardItemModel(24, 7, this);
    for(int hour = 0; hour < 24; hour++)
    {
        if(hour < 10)
        {
            m_model -> setHeaderData(hour, Qt::Vertical, QString("0%1:00").arg(hour));
        }
        else
        {
            m_model -> setHeaderData(hour, Qt::Vertical, QString("%1:00").arg(hour));
        }
    }

    table -> setModel(m_model);
    for(int hour = 0; hour < 24; hour++)
    {
        table -> setRowHeight(hour, 70);
    }

    table -> setCornerButtonEnabled(false);
    table -> horizontalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    table -> verticalHeader()-> setSectionResizeMode(QHeaderView::Fixed);
    table -> verticalHeader() -> setDefaultAlignment(Qt::AlignTop);
    table -> horizontalHeader() -> setHighlightSections(false);
    table -> verticalHeader() -> setHighlightSections(false);


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
                outline: none;
            }
    )";

    table -> verticalHeader() -> setStyleSheet(vertical_header_style);
    table -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    table -> setProperty("class", "calendar-table");

    table -> setStyleSheet(
    R"(

        QTableView
        {
            background-color: #ffffff;
        }

        QTableCornerButton::section
        {
            background: transparent;
            border: none;
        }

    )"
    );

    //calendar options bar

    auto calendar_options_bar = new QWidget(this);
    calendar_options_bar -> setProperty("class", "calendar-options-bar");
    calendar_options_bar -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto calendar_options_bar_layout = new QHBoxLayout(calendar_options_bar);
    calendar_options_bar_layout -> setSpacing(0);

    auto week_back_button = new QPushButton(calendar_options_bar);
    week_back_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    week_back_button -> setProperty("class", "calendar-top-bar-buttons");
    week_back_button -> setMaximumWidth(30);
    week_back_button -> setMaximumHeight(30);
    week_back_button -> setMinimumHeight(30);

    week_back_button -> setIcon(QIcon(":/icons/arrow_right.png"));
    week_back_button -> setIconSize(QSize(12,12));


    auto today_button = new QPushButton("Today", calendar_options_bar);
    today_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    today_button -> setProperty("class", "calendar-top-bar-buttons");
    today_button -> setMaximumWidth(70);
    today_button -> setMaximumHeight(30);
    today_button -> setMinimumHeight(30);
    today_button -> setEnabled(true);

    auto next_week_button = new QPushButton(calendar_options_bar);
    next_week_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    next_week_button -> setProperty("class", "calendar-top-bar-buttons");
    next_week_button -> setMaximumWidth(30);
    next_week_button -> setIcon(QIcon(":/icons/arrow_left.png"));
    next_week_button -> setIconSize(QSize(12,12));
    next_week_button -> setMaximumHeight(30);
    next_week_button -> setMinimumHeight(30);

    m_month_label = new QLabel(calendar_options_bar);
    m_month_label -> setProperty("class", "month-label");
    auto current_month_name = QString((m_calendar_view_controller -> GetCurrentMonthName()).c_str());
    m_month_label -> setText(current_month_name);

    m_year_label = new QLabel(calendar_options_bar);
    m_year_label -> setProperty("class", "year-label");
    auto current_year = QString(std::to_string(m_calendar_view_controller -> GetYear()).c_str());
    m_year_label -> setText(current_year);

    calendar_options_bar_layout -> addWidget(m_month_label);
    calendar_options_bar_layout -> addWidget(m_year_label);
    calendar_options_bar_layout -> addStretch();
    calendar_options_bar_layout -> addWidget(week_back_button);
    calendar_options_bar_layout -> addWidget(today_button);
    calendar_options_bar_layout -> addWidget(next_week_button);

    calendar_layout -> addWidget(calendar_options_bar);
    calendar_layout -> addWidget(table);
    calendar_layout -> setStretch(0,1);
    calendar_layout -> setStretch(1,15);
    general_layout -> addWidget(calendar_widget);
    this -> setLayout(general_layout);

    m_custom_header = new CalendarCustomHeader(7);
    table -> setHorizontalHeader(m_custom_header);
    table -> horizontalHeader() -> setStyleSheet(horizontal_header_style);
    table -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    WeekViewUpdate();

    //controller and buttons connection
    connect(m_calendar_view_controller, &CalendarViewController::DateChanged, this, &CalendarView::OnDateChanged);
    connect(today_button, &QPushButton::clicked, this, &CalendarView::CurrentWeekInsert);
    connect(next_week_button, &QPushButton::clicked, this, &CalendarView::NextWeekInsert);
    connect(week_back_button, &QPushButton::clicked, this, &CalendarView::PreviousWeekInsert);

};

void CalendarView::OnDateChanged()
{
    if(m_isViewMoved)
    {
        return;
    }

    CurrentWeekInsert();
    //forcing current day highlighting to immidiately change
    this -> resize(this -> width(), this -> height() + 1);
    this -> resize(this -> width(), this -> height() - 1);
}

void CalendarView::NextWeekInsert()
{
    m_weeks_offset++;
    WeekViewUpdate(m_weeks_offset);
}

void CalendarView::PreviousWeekInsert()
{
    m_weeks_offset--;
    WeekViewUpdate(m_weeks_offset);
}

void CalendarView::CurrentWeekInsert()
{
    m_weeks_offset = 0;
    WeekViewUpdate();
}

void CalendarView::WeekViewUpdate(int weeks_offset_count)
{
    m_weekday_map = m_calendar_view_controller -> GenerateWeekMap(weeks_offset_count);
    //GetWeekDayNumber() - 1 because of weekday iso_encoding, no highlighting: setDayHighlight(-1);
    if(weeks_offset_count == 0)
    {
        auto current_month_name = QString((m_calendar_view_controller -> GetCurrentMonthName()).c_str());
        auto current_year = QString(std::to_string(m_calendar_view_controller -> GetYear()).c_str());
        m_month_label -> setText(current_month_name);
        m_year_label -> setText(current_year);
        m_custom_header -> setDayHighlight(m_calendar_view_controller -> GetWeekDayNumber() - 1);
    }
    else
    {
        auto current_month_name = QString((m_calendar_view_controller -> GetCurrentMonthName(weeks_offset_count * 7)).c_str());
        auto current_year = QString((std::to_string(m_calendar_view_controller -> GetYear(weeks_offset_count * 7))).c_str());
        m_month_label -> setText(current_month_name);
        m_year_label -> setText(current_year);
        m_custom_header -> setDayHighlight(-1);
    }

    for(int day = 0; day < 7; day++)
    {
        m_model -> setHeaderData(day, Qt::Horizontal, m_weekday_map[day].c_str());
    }
}

//Touchpad sliding:
// void CalendarView::NextDayInsert()
// {
//     QList<QStandardItem*> new_column;
//     for(int row = 0; row < m_model -> rowCount(); row++)
//     {
//         new_column.append(new QStandardItem());
//     }

//     //auto next_day_data = m_calendar_view_controller -> GetDay();
//     m_model -> removeColumns(0,1);
//     m_model -> appendColumn(new_column);

//     //m_model -> setHeaderData(m_model -> columnCount() - 1, Qt::Horizontal, header_name);
// }

// void CalendarView::PreviousDayInsert()
// {

// }

