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

using namespace dp_business_logic::DayPlanner;

class CalendarViewController : public QObject
{
    Q_OBJECT
private:
    IDateTimeGetter* m_date_time_getter_api;
    EventManager* m_event_manager;
    QTimer* m_date_changes_signal_timer;
    uint8_t m_current_day;

public:
    CalendarViewController(
        IDateTimeGetter* date_time_getter_api,
        EventManager* manager);

    ~CalendarViewController();
    std::tuple<unsigned int, uint8_t, uint8_t> GetDate();
    void CheckDate();
    uint8_t GetWeekDayNumber();
    uint8_t GetDay(int day_offset);
    std::string GetCurrentMonthName(int day_offset = 0);
    unsigned int GetYear(int day_offset = 0);
    std::map<unsigned int, std::string> GenerateWeekMap(int weeks_offset_count);
    bool addEvent();

signals:
    void DateChanged(int date_value);
};