#pragma once
#include "QWidget"

class MainViewArea : public QWidget
{
    Q_OBJECT
public:

    MainViewArea(QWidget* parent, QWidget* main);

private:
    QWidget* main_window;
};