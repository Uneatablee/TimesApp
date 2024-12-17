#pragma once
#include "IDateTimeGetter.hpp"
#include "QTimer"
#include "QObject"
#include <tuple>
#include <map>

using namespace dp_business_logic::DayPlanner;

class CalendarViewController : public QObject
{
    Q_OBJECT
public:
    CalendarViewController(IDateTimeGetter* date_time_getter_api);
    ~CalendarViewController();
    std::tuple<unsigned int, uint8_t, uint8_t> GetDate();
    void CheckDate();
    uint8_t GetWeekDayNumber();
    uint8_t GetDay(int);
    std::map<unsigned int, std::string> GenerateWeekMap();
signals:
    void DateChanged(int date_value);
private:
    IDateTimeGetter* m_date_time_getter_api;
    QTimer* m_date_changes_signal_timer;
    uint8_t m_current_day;
};