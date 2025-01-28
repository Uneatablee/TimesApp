#pragma once
#include "QTableView"
#include "Event.hpp"
#include <tuple>
#include <memory>

class CalendarViewController;

using namespace dp_business_logic::DayPlanner;

class CustomCalendarForWeekView : public QTableView
{
private:

    struct DrawableEvent
    {
        std::tuple<unsigned int, uint8_t, uint8_t> start_date;
        std::tuple<unsigned int, uint8_t, uint8_t> end_date;
        std::tuple<uint8_t, uint8_t> start_time;
        std::tuple<uint8_t, uint8_t> end_time;
        std::string name;
    };

    std::tuple<uint8_t, uint8_t> m_hour_mark;
    std::vector<const DrawableEvent> m_events_print_queue;
    QString m_current_month;
    QString m_current_year;
    CalendarViewController* m_calendar_view_controller;

public:
    CustomCalendarForWeekView(CalendarViewController* calendar_view_controller);
    void paintEvent(QPaintEvent* event) override;
    void addEvent();
    void drawEventTile(int col, int row_start, int row_end, QColor color);
    void drawHourMark();
    bool setHourMark(std::tuple<uint8_t, uint8_t> hour_mark);
    bool setMonthYear(QString month, QString year);
    bool AddDrawableEvent(std::tuple<unsigned int, uint8_t, uint8_t> start_date,
                        std::tuple<unsigned int, uint8_t, uint8_t> end_date,
                        std::tuple<uint8_t, uint8_t> start_time,
                        std::tuple<uint8_t, uint8_t> end_time,
                        std::string event_name);
    bool ClearDrawableEventsQueue();
    uint8_t GetMonthNumber(std::string month_name);
};