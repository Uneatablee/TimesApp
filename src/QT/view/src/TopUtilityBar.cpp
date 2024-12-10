#include "../include/TopUtilityBar.hpp"
#include "QHBoxLayout"
#include "QVBoxLayout"



TopUtilityBar::TopUtilityBar(QWidget* parent) : QWidget(parent)
{
    auto main_top_bar_layout = new QVBoxLayout(this);
    main_top_bar_layout -> setContentsMargins(0, 0, 0, 0);

    auto top_bar = new QWidget(this);

    auto bar_tiles_layout = new QHBoxLayout(top_bar);
    bar_tiles_layout -> setContentsMargins(0, 0, 0, 0);

    auto widget_1 = new QWidget();
    bar_tiles_layout -> addWidget(widget_1);
    widget_1 -> setProperty("class", "top-bar-widget1");

    auto widget_2 = new QWidget();
    bar_tiles_layout -> addWidget(widget_2);
    widget_2 -> setProperty("class", "top-bar-widget2");

    auto widget_3 = new QWidget();
    bar_tiles_layout -> addWidget(widget_3);
    widget_3 -> setProperty("class", "top-bar-widget3");

    auto widget_4 = new QWidget();
    bar_tiles_layout -> addWidget(widget_4);
    widget_4 -> setProperty("class", "top-bar-widget4");

    main_top_bar_layout -> addWidget(top_bar);
}