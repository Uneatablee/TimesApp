#include "../include/TasksGroupView.hpp"
#include "QVBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "QIcon"
#include "QPainter"
#include "QRect"

TasksGroupView::TasksGroupView()
{
    auto group_layout = new QVBoxLayout(this);
    group_layout -> setContentsMargins(0,0,0,0);

    auto tasks_group_panel = new QWidget(this);
    tasks_group_panel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tasks_group_panel -> setProperty("class", "tasks-group-view");

    auto pixmap = new QPixmap(16, 16);
    pixmap -> fill(Qt::transparent);
    QPainter painter(pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(pixmap -> rect(), QColor("#d0d0d0"));
    auto icon1 = QIcon(*pixmap);

    //group buttons
    //#d0d4f3
    //#c5bdfe
    //#8474fb
    //#42378f

    auto group_buttons_layout = new QVBoxLayout(tasks_group_panel);

    auto groups_label = new QLabel("Groups", tasks_group_panel);
    groups_label -> setStyleSheet("text-align: left; color: #808080;");

    auto group1 = new QPushButton("Gym");
    group1 -> setProperty("class", "group-button");
    group1 -> setIcon(icon1);

    auto group2 = new QPushButton("Home");
    group2 -> setProperty("class", "group-button");
    painter.fillRect(pixmap -> rect(), QColor("#d0d4f3"));
    auto icon2 = QIcon(*pixmap);
    group2 -> setIcon(icon2);

    auto group3 = new QPushButton("Studies");
    group3 -> setProperty("class", "group-button");
    painter.fillRect(pixmap -> rect(), QColor("#c5bdfe"));
    auto icon3 = QIcon(*pixmap);
    group3 -> setIcon(icon3);

    auto group4 = new QPushButton("Home Activities");
    group4 -> setProperty("class", "group-button");
    painter.fillRect(pixmap -> rect(), QColor("#8474fb"));
    auto icon4 = QIcon(*pixmap);
    group4 -> setIcon(icon4);

    auto group5 = new QPushButton("Work");
    group5 -> setProperty("class", "group-button");
    painter.fillRect(pixmap -> rect(), QColor("#42378f"));
    auto icon5 = QIcon(*pixmap);
    group5 -> setIcon(icon5);

    group_buttons_layout -> addWidget(groups_label);
    group_buttons_layout -> addWidget(group1);
    group_buttons_layout -> addWidget(group2);
    group_buttons_layout -> addWidget(group3);
    group_buttons_layout -> addWidget(group4);
    group_buttons_layout -> addWidget(group5);
    group_buttons_layout -> addStretch();

    group_layout -> addWidget(tasks_group_panel);
}