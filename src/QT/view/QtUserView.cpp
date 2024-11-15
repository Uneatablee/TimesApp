#include "QtUserView.hpp"
#include "../core/mainwindow.h"
#include "QtViewStyles.hpp"
#include "QWidget"
#include "QPushButton"
#include "QMessageBox"
#include "QPropertyAnimation"
#include "QPushButton"


QtUserView::QtUserView(MainWindow* window) : m_main_app_window(window)
{
    QPushButton* central_button = new QPushButton("Click me", m_main_app_window);
    central_button -> setGeometry(10,10,150,50);
    central_button -> move(640 - 75,360 - 25);
    central_button -> setProperty("class", "button-style");
}