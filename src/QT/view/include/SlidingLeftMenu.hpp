#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QPropertyAnimation"
#include "QPushButton"
#include "QRect"
#include <memory>
#include <vector>

class MainWindow;

class SlidingLeftMenu : public QWidget
{
    Q_OBJECT
public:
    SlidingLeftMenu();
    bool slidingToggleAnimationOn();
    bool slidingToggleAnimationOff();
    bool toggleMenu();
    bool setButtonTextVisible(QPushButton*);

private:

    QWidget* m_main_window;

    QVBoxLayout* m_menu_layout;
    QPropertyAnimation* m_animation;
    QPushButton* m_button_slider_toggle;
    QPushButton* m_button_home;
    QPushButton* m_button_account;
    QPushButton* m_button_logout;
    QPushButton* m_button_settings;
    QWidget* left_menu_slider;
    std::vector<QPushButton*> m_buttons_container;
    bool isToggled = false;

protected:

};