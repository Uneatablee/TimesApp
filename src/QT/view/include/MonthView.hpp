#pragma once
#include "QWidget"

class MonthView : public QWidget
{
    Q_OBJECT

public:
    MonthView();
private:
    QWidget* m_parent;

};