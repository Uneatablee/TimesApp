#include "SlidingLeftMenu.hpp"
#include "QStyle"
#include "QHBoxLayout"


SlidingLeftMenu::SlidingLeftMenu(MainWindow* window ,QWidget* parent) : QWidget(parent), m_main_window(window)
{
    QWidget* left_menu_slider = new QWidget(m_main_window);
    left_menu_slider -> setFixedWidth(300);
    left_menu_slider -> setFixedHeight(720);
    left_menu_slider -> move(-250,0);
    left_menu_slider -> setProperty("class", "left-menu-slider");

    QVBoxLayout* toggle_button_layout = new QVBoxLayout();
    QVBoxLayout* menu_layout = new QVBoxLayout();

    QPushButton* button_account = new QPushButton("PROFILE");
    button_account -> setProperty("class", "button-style");

    QPushButton* button_settings = new QPushButton("SETTINGS");
    button_settings -> setProperty("class", "button-style");

    QPushButton* button_logout = new QPushButton("LOGOUT");
    button_logout -> setProperty("class", "button-style");

    menu_layout -> addWidget(button_account);
    menu_layout -> addWidget(button_settings);
    menu_layout -> addWidget(button_logout);
    menu_layout -> addStretch();

    button_slider_toggle = new QPushButton();
    button_slider_toggle -> setFixedWidth(25);
    button_slider_toggle -> setProperty("class", "button-toggle-menu-left");
    toggle_button_layout -> addWidget(button_slider_toggle, 0, Qt::AlignTop);

    QHBoxLayout* layouts_container = new QHBoxLayout(left_menu_slider);
    layouts_container -> addLayout(menu_layout);
    layouts_container -> addLayout(toggle_button_layout);

    connect(button_slider_toggle, &QPushButton::clicked, this, &SlidingLeftMenu::toggleMenu);
    m_animation = new QPropertyAnimation(left_menu_slider, "geometry");
}

bool SlidingLeftMenu::toggleMenu()
{
    if(isToggled)
    {
        slidingToggleAnimationOff();
        isToggled = false;
    }
    else
    {
        slidingToggleAnimationOn();
        isToggled = true;
    }

    return true;
}

bool SlidingLeftMenu::slidingToggleAnimationOn()
{
    m_animation -> setStartValue(QRect(-250, 0, 300, 720));
    m_animation -> setEndValue(QRect(0, 0, 300, 720));
    m_animation -> setDuration(100);
    m_animation -> start();
    isToggled = true;
    return true;

}

bool SlidingLeftMenu::slidingToggleAnimationOff()
{
    m_animation -> setStartValue(QRect(0, 0, 300, 720));
    m_animation -> setEndValue(QRect(-250, 0, 300, 720));
    m_animation -> setDuration(100);
    m_animation -> start();
    isToggled = false;
    return true;
}