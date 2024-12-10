#pragma once
#include "QWidget"

class TasksEventsView : public QWidget
{
    Q_OBJECT
public:

    TasksEventsView(QWidget* parent);
private:
    QWidget* m_parent;
};