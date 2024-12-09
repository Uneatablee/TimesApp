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
    auto model = new QStandardItemModel(24, 7, this);
    auto tabel = new QTableView(this);

    tabel -> setModel(model);
    tabel -> horizontalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    tabel -> verticalHeader()-> setSectionResizeMode(QHeaderView::Stretch);
    tabel -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    general_layout -> addWidget(tabel);

    this -> setLayout(general_layout);
};