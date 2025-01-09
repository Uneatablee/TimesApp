#pragma once
#include "QTableView"

class CustomCalendarForWeekView : public QTableView
{
private:

public:
    CustomCalendarForWeekView();
    void paintEvent(QPaintEvent* event) override;
    void addEvent();

};