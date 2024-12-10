#pragma once
#include "QWidget"

class TasksGroupView : public QWidget
{
    Q_OBJECT
public:
    TasksGroupView(QWidget* parent);
private:
    QWidget* m_parent;
};