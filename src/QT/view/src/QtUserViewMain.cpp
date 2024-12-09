#include "../include/QtUserViewMain.hpp"
#include "../../core/mainwindow.h"
#include "../include/QtViewStyles.hpp"
#include "../include/TopUtilityBar.hpp"
#include "../include/MainViewArea.hpp"
#include "QBoxLayout"
#include "QStackedWidget"


QtUserViewMain::QtUserViewMain(QWidget* parent) : QWidget(parent), m_main_window(parent)
{
    QHBoxLayout* viewLayout = new QHBoxLayout(this);
    viewLayout -> setContentsMargins(0,0,0,0);
    // viewLayout -> setAlignment(Qt::AlignLeft);

    //Different pages view
    SlidingLeftMenu* sliding_left_menu = new SlidingLeftMenu(this, m_main_window);
    MainViewArea* main_view_area = new MainViewArea(this, m_main_window);

    // Stacked Pages container
    // QStackedWidget* stacked_pages = new QStackedWidget(this);
    sliding_left_menu->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    main_view_area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Layout set
    viewLayout -> addWidget(sliding_left_menu);
    viewLayout -> addWidget(main_view_area);
    // viewLayout -> addStretch(1);
}