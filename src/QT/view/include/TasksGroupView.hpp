#pragma once
#include "QWidget"

class TasksGroupView : public QWidget
{
    Q_OBJECT
public:
    TasksGroupView();
private:
    QWidget* m_parent;
};