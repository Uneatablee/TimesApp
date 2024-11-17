#pragma once
#include "QWidget"
#include "QEvent"
#include "QPushButton"
#include "QMessageBox"
#include "QPropertyAnimation"

#include "SlidingLeftMenu.hpp"

class MainWindow;

class QtUserViewMain : public QWidget
{
    Q_OBJECT

public:

    QtUserViewMain(MainWindow* window);


private:
    MainWindow* m_main_app_window;
};
