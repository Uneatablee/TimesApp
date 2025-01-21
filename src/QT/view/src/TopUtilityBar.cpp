#include "../include/TopUtilityBar.hpp"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"



TopUtilityBar::TopUtilityBar()
{
    auto main_top_bar_layout = new QVBoxLayout(this);
    main_top_bar_layout -> setContentsMargins(0, 0, 0, 0);

    auto top_bar = new QWidget(this);

    auto bar_tiles_layout = new QHBoxLayout(top_bar);
    bar_tiles_layout -> setContentsMargins(0, 0, 0, 0);

    //widget 1
    auto widget_1 = new QWidget();
    bar_tiles_layout -> addWidget(widget_1);
    widget_1 -> setProperty("class", "top-bar-widget1");

    auto layout_w_1 = new QHBoxLayout(widget_1);
    auto lab_1 = new QLabel(widget_1);
    layout_w_1 -> addWidget(lab_1);
    lab_1 -> setProperty("class", "year-label");

    //widget 2
    auto widget_2 = new QWidget();
    bar_tiles_layout -> addWidget(widget_2);
    widget_2 -> setProperty("class", "top-bar-widget2");

    //widget 3
    auto widget_3 = new QWidget();
    bar_tiles_layout -> addWidget(widget_3);
    widget_3 -> setProperty("class", "top-bar-widget3");

    //widget 4
    auto widget_4 = new QWidget();
    bar_tiles_layout -> addWidget(widget_4);
    widget_4 -> setProperty("class", "top-bar-widget4");

    auto layout_w_4 = new QHBoxLayout(widget_4);
    auto lab_4 = new QLabel(widget_4);
    layout_w_4 -> addWidget(lab_4);
    lab_4 -> setProperty("class", "year-label");

    main_top_bar_layout -> addWidget(top_bar);
    main_top_bar_layout -> setStretch(0,1);
    main_top_bar_layout -> setStretch(1,1);
    main_top_bar_layout -> setStretch(2,1);
    main_top_bar_layout -> setStretch(3,1);
}