#pragma once
#include "QWidget"

class MainWindow;

class QtUserView : public QWidget
{
    Q_OBJECT

public:

    QtUserView(MainWindow* window);


private:
    MainWindow* m_main_app_window;
};
