#include "../include/QtUserViewMain.hpp"
#include "../../core/mainwindow.h"
#include "../include/QtViewStyles.hpp"
#include "../include/TopUtilityBar.hpp"
#include "../include/MainViewArea.hpp"
#include "QBoxLayout"
#include "QStackedWidget"


QtUserViewMain::QtUserViewMain(MainViewArea* main_view_area, SlidingLeftMenu* sliding_left_menu)
{
    QHBoxLayout* viewLayout = new QHBoxLayout(this);
    viewLayout -> setContentsMargins(0,0,0,0);
    viewLayout -> setSpacing(0);
    //viewLayout -> setAlignment(Qt::AlignLeft);

    //Different pages view
    sliding_left_menu -> setParent(this);
    sliding_left_menu -> setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    main_view_area -> setParent(this);
    main_view_area -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Stacked Pages container
    // QStackedWidget* stacked_pages = new QStackedWidget(this);

    //Layout set
    viewLayout -> addWidget(sliding_left_menu);
    viewLayout -> addWidget(main_view_area);
    //viewLayout -> addStretch(1);
}