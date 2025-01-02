#pragma once
#include "QWidget"

class TasksEventsView : public QWidget
{
    Q_OBJECT
public:

    TasksEventsView();
private:
    QWidget* m_parent;
};