#include "../include/CalendarView.hpp"
#include "../include/CalendarCustomHeader.hpp"

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
#include "QDialog"

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
    m_table = new CustomCalendarForWeekView(m_calendar_view_controller);
    m_table -> setParent(this);
    m_calendar_view_controller -> SetCustomWeekCalendar(m_table);

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

    m_table -> setModel(m_model);
    for(int hour = 0; hour < 24; hour++)
    {
        m_table -> setRowHeight(hour, 70);
    }

    m_table -> setCornerButtonEnabled(false);
    m_table -> horizontalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    m_table -> verticalHeader()-> setSectionResizeMode(QHeaderView::Fixed);
    m_table -> verticalHeader() -> setDefaultAlignment(Qt::AlignTop);
    m_table -> horizontalHeader() -> setHighlightSections(false);
    m_table -> verticalHeader() -> setHighlightSections(false);


    const char* vertical_header_style = R"(
            QHeaderView::section
            {
                background-color: #ffffff;
                border: none;
                color: #9c9c9c;
                outline: none;
            }
    )";

    m_table -> verticalHeader() -> setStyleSheet(vertical_header_style);
    m_table -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_table -> setProperty("class", "calendar-m_table");

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

    m_week_view_button = new QPushButton("Week", calendar_options_bar);
    m_week_view_button -> setProperty("class", "calendar-top-bar-buttons");
    m_week_view_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_week_view_button -> setMaximumWidth(60);
    m_week_view_button -> setMaximumHeight(30);
    m_week_view_button -> setMinimumHeight(30);

    m_day_view_button = new QPushButton("Day", calendar_options_bar);
    m_day_view_button -> setProperty("class", "calendar-top-bar-buttons");
    m_day_view_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_day_view_button -> setMaximumWidth(60);
    m_day_view_button -> setMaximumHeight(30);
    m_day_view_button -> setMinimumHeight(30);

    m_month_view_button = new QPushButton("Month", calendar_options_bar);
    m_month_view_button -> setProperty("class", "calendar-top-bar-buttons");
    m_month_view_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_month_view_button -> setMaximumWidth(60);
    m_month_view_button -> setMaximumHeight(30);
    m_month_view_button -> setMinimumHeight(30);

    auto add_event_button = new QPushButton(calendar_options_bar);
    add_event_button -> setProperty("class", "calendar-top-bar-buttons");
    add_event_button -> setIcon(QIcon(":/icons/plus_icon.png"));
    add_event_button -> setIconSize(QSize(12,12));
    add_event_button -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    add_event_button -> setMaximumWidth(30);
    add_event_button -> setMaximumHeight(30);
    add_event_button -> setMinimumHeight(30);

    calendar_options_bar_layout -> addWidget(m_month_label);
    calendar_options_bar_layout -> addWidget(m_year_label);
    calendar_options_bar_layout -> addStretch();
    calendar_options_bar_layout -> addWidget(m_month_view_button);
    calendar_options_bar_layout -> addWidget(m_week_view_button);
    calendar_options_bar_layout -> addWidget(m_day_view_button);
    calendar_options_bar_layout -> addStretch();
    calendar_options_bar_layout -> addWidget(week_back_button);
    calendar_options_bar_layout -> addWidget(today_button);
    calendar_options_bar_layout -> addWidget(next_week_button);
    calendar_options_bar_layout -> addWidget(add_event_button);

    calendar_layout -> addWidget(calendar_options_bar);
    calendar_layout -> addWidget(m_table);
    calendar_layout -> setStretch(0,1);
    calendar_layout -> setStretch(1,15);

    general_layout -> addWidget(calendar_widget);
    this -> setLayout(general_layout);

    m_custom_header = new CalendarCustomHeader(7);
    m_table -> setHorizontalHeader(m_custom_header);

    WeekViewUpdate();
    DrawTimeMarker();

    //controller and buttons connection
    connect(m_calendar_view_controller, &CalendarViewController::DateChanged, this, &CalendarView::OnDateChanged);
    connect(m_calendar_view_controller, &CalendarViewController::TimeChanged, this, &CalendarView::OnTimeChanged);
    connect(today_button, &QPushButton::clicked, this, &CalendarView::CurrentWeekInsert);
    connect(next_week_button, &QPushButton::clicked, this, &CalendarView::NextWeekInsert);
    connect(week_back_button, &QPushButton::clicked, this, &CalendarView::PreviousWeekInsert);
    connect(add_event_button, &QPushButton::clicked, this, &CalendarView::NewEventDialog);
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

void CalendarView::OnTimeChanged()
{
    DrawTimeMarker();
}

void CalendarView::NextWeekInsert()
{
    m_weeks_offset++;
    WeekViewUpdate(m_weeks_offset);
    if(m_weeks_offset == 0)
    {
        m_isViewMoved = false;
        return;
    }

    m_isViewMoved = true;
}

void CalendarView::PreviousWeekInsert()
{
    m_weeks_offset--;
    WeekViewUpdate(m_weeks_offset);
    if(m_weeks_offset == 0)
    {
        m_isViewMoved = false;
        return;
    }

    m_isViewMoved = true;
}

void CalendarView::CurrentWeekInsert()
{
    m_weeks_offset = 0;
    WeekViewUpdate();
}

void CalendarView::WeekViewUpdate(int weeks_offset_count)
{
    //Calendar drawing
    m_weekday_map = m_calendar_view_controller -> GenerateWeekMap(weeks_offset_count);
    //GetWeekDayNumber() - 1 because of weekday iso_encoding, no highlighting: setDayHighlight(-1);
    if(weeks_offset_count == 0)
    {
        auto current_month_name = QString((m_calendar_view_controller -> GetCurrentMonthName()).c_str());
        auto current_year = QString(std::to_string(m_calendar_view_controller -> GetYear()).c_str());
        m_month_label -> setText(current_month_name);
        m_year_label -> setText(current_year);
        m_table -> setMonthYear(current_month_name, current_year);
        m_custom_header -> setDayHighlight(m_calendar_view_controller -> GetWeekDayNumber() - 1);
    }
    else
    {
        auto current_month_name = QString((m_calendar_view_controller -> GetCurrentMonthName(weeks_offset_count * 7)).c_str());
        auto current_year = QString((std::to_string(m_calendar_view_controller -> GetYear(weeks_offset_count * 7))).c_str());
        m_month_label -> setText(current_month_name);
        m_year_label -> setText(current_year);
        m_table -> setMonthYear(current_month_name, current_year);
        m_custom_header -> setDayHighlight(-1);
    }

    for(int day = 0; day < 7; day++)
    {
        m_model -> setHeaderData(day, Qt::Horizontal, m_weekday_map[day].c_str());
    }

    m_calendar_view_controller -> RetrieveDrawableEventsQueue();
    //Current time marker drawing
    DrawTimeMarker();
}

void CalendarView::NewEventDialog()
{
    m_event_popup = new EventPopupDialog(this, m_calendar_view_controller);
    m_event_popup -> show();
}

void CalendarView::DrawTimeMarker()
{
    m_table -> setHourMark(m_calendar_view_controller -> GetHourMinute());
    m_table -> repaint();
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

