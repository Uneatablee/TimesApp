#include "QtUserViewMain.hpp"
#include "../core/mainwindow.h"
#include "QtViewStyles.hpp"
#include "QWidget"
#include "QPushButton"
#include "QMessageBox"
#include "QPropertyAnimation"
#include "QSequentialAnimationGroup"


QtUserViewMain::QtUserViewMain(MainWindow* window) : m_main_app_window(window)
{
    SlidingLeftMenu* sliding_left_menu = new SlidingLeftMenu(window);
}