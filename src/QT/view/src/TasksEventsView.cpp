#include "../include/TasksEventsView.hpp"
#include "QVBoxLayout"
#include "QPushButton"
#include "QLabel"

TasksEventsView::TasksEventsView()
{
    auto tasks_main_layout = new QVBoxLayout(this);
    tasks_main_layout -> setContentsMargins(0,0,0,0);

    auto tasks_view = new QWidget(this);
    tasks_view -> setContentsMargins(0,0,0,0);
    tasks_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tasks_view -> setProperty("class", "tasks-view");

    auto tasks_layout = new QVBoxLayout(tasks_view);

    auto calendar_options_label = new QLabel("Calendar");
    calendar_options_label -> setProperty("class", "event-options-label");
    tasks_layout -> addWidget(calendar_options_label);

    auto add_event_button = new QPushButton("Add event");
    add_event_button -> setProperty("class", "event-option-buttons");
    add_event_button -> setIcon(QIcon(":/icons/plus_circle_icon.png"));
    add_event_button -> setIconSize(QSize(12,12));
    add_event_button -> setMinimumSize(10,10);
    tasks_layout -> addWidget(add_event_button);

    auto edit_event_button = new QPushButton("Edit event");
    edit_event_button -> setProperty("class", "event-option-buttons");
    edit_event_button -> setIcon(QIcon(":/icons/minus_circle_icon.png"));
    edit_event_button -> setIconSize(QSize(12,12));
    edit_event_button -> setMinimumSize(10,10);
    tasks_layout -> addWidget(edit_event_button);

    tasks_layout -> addStretch();

    tasks_main_layout -> addWidget(tasks_view);
}