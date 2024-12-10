#include "../include/TasksGroupView.hpp"
#include "QVBoxLayout"


TasksGroupView::TasksGroupView(QWidget* parent) : QWidget(parent), m_parent(parent)
{
    auto group_layout = new QVBoxLayout(this);
    group_layout -> setContentsMargins(0,0,0,0);

    auto tasks_group_panel = new QWidget(this);
    tasks_group_panel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tasks_group_panel -> setProperty("class", "tasks-group-view");

    group_layout -> addWidget(tasks_group_panel);
}