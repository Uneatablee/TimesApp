#pragma once
#include "QWidget"
#include "QDialog"
#include "QObject"
#include "../../controller/include/CalendarViewController.hpp"

#include <string>

class EventPopupDialog : public QDialog
{
    Q_OBJECT
private:
    CalendarViewController* m_controller;
signals:
    void NewEventSignal(
        QString start_date,
        QString end_date,
        QString hour_start,
        QString hour_end,
        std::string event_name,
        std::string event_group);
public:
    EventPopupDialog(QWidget* parent, CalendarViewController* controller);
};