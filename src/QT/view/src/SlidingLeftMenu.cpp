#include "../include/SlidingLeftMenu.hpp"
#include "QStyle"
#include "QHBoxLayout"
#include "QIcon"
#include "QPixmap"
#include "QSize"
#include "../../core/mainwindow.h"

SlidingLeftMenu::SlidingLeftMenu(MainWindow* window ,QWidget* parent) : QWidget(parent), m_main_window(window)
{
    //UI------->
    left_menu_slider = new QWidget(m_main_window);
    left_menu_slider -> resize(65,m_main_window -> height());
    left_menu_slider -> setProperty("class", "left-menu-slider");

    // QHBoxLayout* left_layout = new QHBoxLayout(left_menu_slider);
    QVBoxLayout* menu_layout = new QVBoxLayout(left_menu_slider);
    //QVBoxLayout* right_menu_layout = new QVBoxLayout();

    QPushButton* button_home = new QPushButton();
    button_home -> setProperty("class", "button-style");
    button_home -> setIcon(QIcon(":/icons/home_icon.png"));
    button_home -> setIconSize(QSize(16,16));

    QPushButton* button_account = new QPushButton();
    button_account -> setProperty("class", "button-style");
    button_account -> setIcon(QIcon(":/icons/profile_icon.png"));
    button_account -> setIconSize(QSize(16,16));

    QPushButton* button_settings = new QPushButton();
    button_settings -> setProperty("class", "button-style");
    button_settings -> setIcon(QIcon(":/icons/settings_icon.png"));
    button_settings -> setIconSize(QSize(16,16));

    QPushButton* button_logout = new QPushButton();
    button_logout -> setProperty("class", "button-style");
    button_logout -> setIcon(QIcon(":/icons/power_off_icon.png"));
    button_logout -> setIconSize(QSize(16,16));

    button_slider_toggle = new QPushButton();
    button_slider_toggle -> setProperty("class", "button-toggle-menu-left");
    button_slider_toggle -> setIcon(QIcon(":/icons/process_icon.png"));
    button_slider_toggle -> setIconSize(QSize(24,24));

    menu_layout -> addWidget(button_slider_toggle);
    menu_layout -> addWidget(button_home);
    menu_layout -> addWidget(button_account);
    menu_layout -> addWidget(button_settings);
    menu_layout -> addWidget(button_logout);
    menu_layout -> addStretch();

    // QPushButton* settings_but = new QPushButton("Settings");
    // settings_but -> setProperty("class", "button-style");

    // right_menu_layout -> addWidget(settings_but);
    // right_menu_layout -> addStretch();

    // left_layout -> addLayout(menu_layout);
    // left_layout -> addLayout(right_menu_layout);

    //Connectors------>
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
    m_animation -> setStartValue(QRect(0, 0, 65, m_main_window -> height()));
    m_animation -> setEndValue(QRect(0, 0, 300, m_main_window -> height()));
    m_animation -> setDuration(80);
    m_animation -> start();
    isToggled = true;
    return true;

}

bool SlidingLeftMenu::slidingToggleAnimationOff()
{
    m_animation -> setStartValue(QRect(0, 0, 300, m_main_window -> height()));
    m_animation -> setEndValue(QRect(0, 0, 65, m_main_window -> height()));
    m_animation -> setDuration(80);
    m_animation -> start();
    isToggled = false;
    return true;
}