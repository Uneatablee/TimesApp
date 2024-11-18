#pragma once
#include "QWidget"

class MainWindow;

class TopUtilityBar : public QWidget
{
public:
    TopUtilityBar(MainWindow* window ,QWidget* parent = nullptr);
private:
    MainWindow* m_main_window;
};