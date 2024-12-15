#pragma once
#include "QWidget"
#include "QEvent"
#include "QPushButton"
#include "QMessageBox"
#include "QPropertyAnimation"

#include "SlidingLeftMenu.hpp"

class SlidingLeftmenu;
class MainViewArea;
class MainWindow;

class QtUserViewMain : public QWidget
{
    Q_OBJECT

public:

    QtUserViewMain(MainViewArea*, SlidingLeftMenu*);

private:
    QWidget* m_main_window;
};
