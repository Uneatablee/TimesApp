#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QPropertyAnimation"
#include "QPushButton"
#include "QRect"
#include <memory>

class MainWindow;

class SlidingLeftMenu : public QWidget
{
    Q_OBJECT
public:
    SlidingLeftMenu(MainWindow* window ,QWidget* parent = nullptr);
    bool slidingToggleAnimationOn();
    bool slidingToggleAnimationOff();
    bool toggleMenu();

private:
    MainWindow* m_main_window;
    QPropertyAnimation* m_animation;
    QPushButton* button_slider_toggle;
    QWidget* left_menu_slider;
    bool isToggled = false;

protected:

};