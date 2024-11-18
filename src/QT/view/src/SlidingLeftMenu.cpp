#include "../include/SlidingLeftMenu.hpp"
#include "QStyle"
#include "QHBoxLayout"
#include "QIcon"
#include "QPixmap"
#include "QSize"
#include "../../core/mainwindow.h"
#include <string>
#include "QVariant"

SlidingLeftMenu::SlidingLeftMenu(MainWindow* window ,QWidget* parent) : QWidget(parent), m_main_window(window)
{
    //UI------->
    left_menu_slider = new QWidget(m_main_window);
    left_menu_slider -> resize(65,m_main_window -> height());
    left_menu_slider -> setProperty("class", "left-menu-slider");

    //QHBoxLayout* left_layout = new QHBoxLayout(left_menu_slider);
    m_menu_layout = new QVBoxLayout(left_menu_slider);
    //QVBoxLayout* right_menu_layout = new QVBoxLayout();

    QPushButton* m_button_home = new QPushButton();
    m_button_home -> setProperty("class", "button-style");
    m_button_home -> setProperty("original-text", "  Home");
    m_button_home -> setIcon(QIcon(":/icons/home_icon.png"));
    m_button_home -> setIconSize(QSize(16,16));

    QPushButton* m_button_account = new QPushButton();
    m_button_account -> setProperty("class", "button-style");
    m_button_account -> setProperty("original-text", "  Profile");
    m_button_account -> setIcon(QIcon(":/icons/profile_icon.png"));
    m_button_account -> setIconSize(QSize(16,16));

    QPushButton* m_button_settings = new QPushButton();
    m_button_settings -> setProperty("class", "button-style");
    m_button_settings -> setProperty("original-text", "  Settings");
    m_button_settings -> setIcon(QIcon(":/icons/settings_icon.png"));
    m_button_settings -> setIconSize(QSize(16,16));

    QPushButton* m_button_logout = new QPushButton();
    m_button_logout -> setProperty("class", "button-style");
    m_button_logout -> setProperty("original-text", "  Logout");
    m_button_logout -> setIcon(QIcon(":/icons/power_off_icon.png"));
    m_button_logout -> setIconSize(QSize(16,16));

    m_button_slider_toggle = new QPushButton();
    m_button_slider_toggle -> setProperty("class", "button-toggle-menu-left");
    m_button_slider_toggle -> setIcon(QIcon(":/icons/process_icon.png"));
    m_button_slider_toggle -> setIconSize(QSize(24,24));

    m_menu_layout -> addWidget(m_button_slider_toggle);
    m_menu_layout -> addWidget(m_button_home);
    m_menu_layout -> addWidget(m_button_account);
    m_menu_layout -> addWidget(m_button_settings);
    m_menu_layout -> addWidget(m_button_logout);
    m_menu_layout -> addStretch();

    m_buttons_container.emplace_back(m_button_home);
    m_buttons_container.emplace_back(m_button_account);
    m_buttons_container.emplace_back(m_button_settings);
    m_buttons_container.emplace_back(m_button_logout);

    // QPushButton* settings_but = new QPushButton("Settings");
    // settings_but -> setProperty("class", "button-style");

    // right_menu_layout -> addWidget(settings_but);
    // right_menu_layout -> addStretch();

    // left_layout -> addLayout(m_menu_layout);
    // left_layout -> addLayout(right_menu_layout);

    //Connectors------>
    connect(m_button_slider_toggle, &QPushButton::clicked, this, &SlidingLeftMenu::toggleMenu);
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

bool SlidingLeftMenu::setButtonTextVisible(QPushButton* button)
{
    auto text_to_popup = button -> property("original-text");
    if(text_to_popup.isValid())
    {
        button -> setText(text_to_popup.toString());
    }

    return true;
}

bool SlidingLeftMenu::slidingToggleAnimationOn()
{
    m_animation -> setStartValue(QRect(0, 0, 65, m_main_window -> height()));
    m_animation -> setEndValue(QRect(0, 0, 300, m_main_window -> height()));
    m_animation -> setDuration(80);
    m_animation -> start();

    for(const auto &elem : m_buttons_container)
    {
        setButtonTextVisible(elem);
    }

    isToggled = true;
    return true;

}

bool SlidingLeftMenu::slidingToggleAnimationOff()
{
    m_animation -> setStartValue(QRect(0, 0, 300, m_main_window -> height()));
    m_animation -> setEndValue(QRect(0, 0, 65, m_main_window -> height()));
    m_animation -> setDuration(80);
    m_animation -> start();

    for(const auto &elem : m_buttons_container)
    {
        elem -> setText("");
    }

    isToggled = false;
    return true;
}