#pragma once
#include "QWidget"

class MonthView : public QWidget
{
    Q_OBJECT

public:
    MonthView(QWidget* parent);
private:
    QWidget* m_parent;

};