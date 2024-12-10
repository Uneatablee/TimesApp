#include "../include/TasksEventsView.hpp"
#include "QVBoxLayout"
#include "QPushButton"

TasksEventsView::TasksEventsView(QWidget* parent) : QWidget(parent), m_parent(parent)
{
    auto tasks_main_layout = new QVBoxLayout(this);
    tasks_main_layout -> setContentsMargins(0,0,0,5);

    auto tasks_view = new QWidget(this);
    tasks_view -> setProperty("class", "tasks-view");

    auto tasks_layout = new QVBoxLayout(tasks_view);

    auto add_event_button = new QPushButton("Add Event");
    tasks_layout -> addWidget(add_event_button);

    auto edit_event_button = new QPushButton("Edit Event");
    tasks_layout -> addWidget(edit_event_button);

    tasks_layout -> addStretch();
    tasks_layout -> setAlignment(Qt::AlignLeft);

    tasks_main_layout -> addWidget(tasks_view);
}