#include "../include/QtUserViewMain.hpp"
#include "../../core/mainwindow.h"
#include "../include/QtViewStyles.hpp"
#include "../include/TopUtilityBar.hpp"


QtUserViewMain::QtUserViewMain(MainWindow* window) : m_main_app_window(window)
{
    SlidingLeftMenu* sliding_left_menu = new SlidingLeftMenu(window);

}