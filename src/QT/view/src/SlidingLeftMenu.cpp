#include "../include/SlidingLeftMenu.hpp"
#include "QStyle"
#include "QHBoxLayout"
#include "QIcon"
#include "QPixmap"


SlidingLeftMenu::SlidingLeftMenu(MainWindow* window ,QWidget* parent) : QWidget(parent), m_main_window(window)
{
    left_menu_slider = new QWidget(m_main_window);
    left_menu_slider -> move(50,50);
    left_menu_slider -> resize(80,620);
    left_menu_slider -> setProperty("class", "left-menu-slider");

    QVBoxLayout* menu_layout = new QVBoxLayout(left_menu_slider);

    QPushButton* button_home = new QPushButton();
    button_home -> setProperty("class", "button-style");

    QIcon icon(":/home_icon.png");
    if (icon.isNull()) {
    qDebug() << "Icon failed to load!";
    }

    button_home -> setIcon(QIcon(":/icons/home_icon.png"));

    QPushButton* button_account = new QPushButton("Profile");
    button_account -> setProperty("class", "button-style");

    QPushButton* button_settings = new QPushButton("Settings");
    button_settings -> setProperty("class", "button-style");

    QPushButton* button_logout = new QPushButton("Logout");
    button_logout -> setProperty("class", "button-style");

    button_slider_toggle = new QPushButton();
    button_slider_toggle -> setProperty("class", "button-toggle-menu-left");

    menu_layout -> addWidget(button_slider_toggle);
    menu_layout -> addWidget(button_home);
    menu_layout -> addWidget(button_account);
    menu_layout -> addWidget(button_settings);
    menu_layout -> addWidget(button_logout);
    menu_layout -> addStretch();

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
    m_animation -> setStartValue(QRect(50, 50, 75, 620));
    m_animation -> setEndValue(QRect(50, 50, 300, 620));
    m_animation -> setDuration(80);
    m_animation -> start();
    isToggled = true;
    return true;

}

bool SlidingLeftMenu::slidingToggleAnimationOff()
{
    m_animation -> setStartValue(QRect(50, 50, 300, 620));
    m_animation -> setEndValue(QRect(50, 50, 75, 620));
    m_animation -> setDuration(80);
    m_animation -> start();
    isToggled = false;
    return true;
}