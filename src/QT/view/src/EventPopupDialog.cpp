#include "../include/EventPopupDialog.hpp"

#include "QPushButton"
#include "QVBoxLayout"
#include "QLabel"
#include "QGraphicsBlurEffect"
#include "QLineEdit"
#include "QComboBox"
#include "QDateEdit"

EventPopupDialog::EventPopupDialog(QWidget* parent, CalendarViewController* controller) : QDialog(parent), m_controller(controller)
{
    auto widget_layout = new QVBoxLayout(this);
    widget_layout -> setSpacing(0);

    auto content_widget = new QWidget(this);
    auto content_layout = new QHBoxLayout(content_widget);
    content_layout -> setSpacing(0);

    auto dialog_left = new QWidget(this);
    auto dialog_right = new QWidget(this);

    auto dialog_layout_left = new QVBoxLayout(dialog_left);
    auto dialog_layout_right = new QVBoxLayout(dialog_right);
    this -> setModal(true);

    setStyleSheet
    (
        R"(
            background-color: #f6f6f6;
        )"
    );
    move(750,215);
    resize(300,250);

    auto dialog_label = new QLineEdit(this);
    dialog_label -> setPlaceholderText("NewEvent");
    dialog_label -> setStyleSheet
    (R"(
        font-weight: bold;
        font-size: 18px;
        color: #808080;
        border: none;

    )");

    QString date_edit_style
    {
        R"(
            QDateEdit
            {
                border:none;
            }
        )"
    };

    auto date_start_label = new QLabel("Start: ", this);
    auto date_end_label = new QLabel("End: ", this);
    auto group_label = new QLabel("Group: ", this);

    auto add_event_button = new QPushButton("Add Event");
    add_event_button -> setProperty("class", "button-style");

    auto start_widget = new QWidget(dialog_right);
    auto start_widget_layout = new QHBoxLayout(start_widget);

        auto date_start_input = new QDateEdit(start_widget);
        date_start_input -> setCalendarPopup(true);
        date_start_input -> setDate(QDate::currentDate());
        date_start_input -> setStyleSheet(date_edit_style);

        auto hour_start_input = new QTimeEdit(start_widget);
        hour_start_input -> setDisplayFormat("hh:mm");

    start_widget_layout -> addWidget(date_start_input);
    start_widget_layout -> addWidget(hour_start_input);

    auto end_widget = new QWidget(dialog_right);
    auto end_widget_layout = new QHBoxLayout(end_widget);

        auto date_end_input = new QDateEdit(end_widget);
        date_end_input -> setCalendarPopup(true);
        date_end_input -> setDate(QDate::currentDate());
        date_end_input -> setStyleSheet(date_edit_style);

        auto hour_end_input = new QTimeEdit(end_widget);
        hour_end_input -> setDisplayFormat("hh:mm");

    end_widget_layout -> addWidget(date_end_input);
    end_widget_layout -> addWidget(hour_end_input);

    auto group_input = new QComboBox(dialog_right);

    widget_layout -> addWidget(dialog_label);
    widget_layout -> addWidget(content_widget);
    widget_layout -> addWidget(add_event_button);

    content_layout -> addWidget(dialog_left);
    content_layout -> addWidget(dialog_right);

    dialog_layout_left -> addWidget(date_start_label);
    dialog_layout_left -> addWidget(date_end_label);
    dialog_layout_left -> addWidget(group_label);

    dialog_layout_right -> addWidget(start_widget);
    dialog_layout_right -> addWidget(end_widget);
    dialog_layout_right -> addWidget(group_input);

    //connectors
    connect(add_event_button, &QPushButton::clicked, m_controller,
    [this, date_start_input, date_end_input, hour_start_input, hour_end_input, dialog_label]()
    {
        emit NewEventSignal(
            QString(date_start_input -> text()),
            QString(date_end_input -> text()),
            QString(hour_start_input -> text()),
            QString(hour_end_input -> text()),
            (dialog_label -> text()).toStdString(),
            "red");
    });
    connect(this, &EventPopupDialog::NewEventSignal, m_controller, &CalendarViewController::addEvent);
    connect(add_event_button, &QPushButton::clicked, m_controller, &CalendarViewController::RetrieveDrawableEventsQueue);
    connect(add_event_button, &QPushButton::clicked, this, &EventPopupDialog::close);

}