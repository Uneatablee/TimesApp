#include "../include/QtUserViewMain.hpp"
#include "../../core/mainwindow.h"
#include "../include/QtViewStyles.hpp"
#include "../include/TopUtilityBar.hpp"
#include "QBoxLayout"


QtUserViewMain::QtUserViewMain(QWidget* parent) : QWidget(parent), m_main_window(parent)
{
    QHBoxLayout* viewLayout = new QHBoxLayout(this);
    viewLayout -> setContentsMargins(0,0,0,0);
    viewLayout -> setAlignment(Qt::AlignLeft);

    SlidingLeftMenu* sliding_left_menu = new SlidingLeftMenu(this, m_main_window);

    viewLayout -> addWidget(sliding_left_menu);
    viewLayout -> addStretch(1);

}