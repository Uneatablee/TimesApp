#include "../include/CalendarView.hpp"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "QFrame"
#include "QStandardItemModel"
#include "QTableView"
#include "QHeaderView"

CalendarView::CalendarView(QWidget* parent) : QWidget(parent)
{

    QHBoxLayout* general_layout = new QHBoxLayout(this);


    //Calendar view
    auto table = new QTableView(this);

    auto model = new QStandardItemModel(24, 7, this);
    for(int hour = 0; hour < 24; hour++)
    {
        if(hour < 10)
        {
            model -> setHeaderData(hour, Qt::Vertical, QString("0%1:00").arg(hour));
        }
        else
        {
            model -> setHeaderData(hour, Qt::Vertical, QString("%1:00").arg(hour));
        }
    }

    table -> setModel(model);
    for(int hour = 0; hour < 24; hour++)
    {
        table -> setRowHeight(hour, 60);
    }

    table -> horizontalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    table -> verticalHeader()-> setSectionResizeMode(QHeaderView::Fixed);
    table -> horizontalHeader() -> hide();
    table -> verticalHeader() -> setDefaultAlignment(Qt::AlignTop);

    table -> verticalHeader() -> setStyleSheet(
        R"(
            QHeaderView::section
            {
                background-color: #ffffff;
                border: none;
                color: #9c9c9c;
            }
        )"
    );

    table -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    table -> setProperty("class", "calendar-table");


    general_layout -> addWidget(table);

    this -> setLayout(general_layout);
};