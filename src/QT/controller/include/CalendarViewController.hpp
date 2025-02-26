#pragma once
#include "IDateTimeGetter.hpp"
#include "IGenericRepository.hpp"
#include "BaseEntity.hpp"
#include "EventManager.hpp"
#include "QTimer"
#include "QObject"
#include <tuple>
#include <map>
#include <string>
#include "../../view/include/CustomCalendarForWeekView.hpp"

using namespace dp_business_logic::DayPlanner;

class CalendarViewController : public QObject
{
    Q_OBJECT
private:
    IDateTimeGetter* m_date_time_getter_api;
    QTimer* m_date_changes_signal_timer;
    uint8_t m_current_day;
    uint8_t m_current_minute;
    uint8_t m_current_hour;
    std::shared_ptr<IGenericRepository<Event>> m_event_generic_repository;
    std::unique_ptr<EventManager> m_event_manager;
    CustomCalendarForWeekView* m_custom_week_calendar;

public:
    CalendarViewController(
        IDateTimeGetter*,
        IGenericRepository<Event>*,
        EventManager*);

    ~CalendarViewController();
    std::tuple<unsigned int, uint8_t, uint8_t> GetDate();
    void CheckDate();
    uint8_t GetWeekDayNumber();
    uint8_t GetDay(int day, int month, int year, int day_offset);
    std::string GetCurrentMonthName(int day_offset = 0);
    unsigned int GetYear(int day_offset = 0);
    std::map<unsigned int, std::string> GenerateWeekMap(int weeks_offset_count);
    std::tuple<uint8_t, uint8_t> GetHourMinute();
    bool SetCustomWeekCalendar(CustomCalendarForWeekView* calendar);
    bool RetrieveDrawableEventsQueue();


public slots:
    bool addEvent(
        QString start_date,
        QString end_date,
        QString start_hour,
        QString end_hour,
        std::string event_name,
        std::string event_group);

signals:
    void DateChanged(int date_value);
    void TimeChanged(int time_value);
};