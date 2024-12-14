#include <memory>
#include "QWidget"
#include "QBoxLayout"
#include "QSizePolicy"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "../view/include/QtUserViewMain.hpp"
#include "../view/include/QtViewStyles.hpp"

// MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
MainWindow::MainWindow(QtUserViewMain* user_view) : QMainWindow(nullptr), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Time'sApp");
    resize(1280, 710);
    //setWindowFlags(Qt::FramelessWindowHint);

    QWidget* central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    this -> setStyleSheet(QtViewStyles::Styles);
    this -> setProperty("class", "general-background");

    QBoxLayout* main_window_layout = new QBoxLayout(QBoxLayout::LeftToRight, central_widget);
    main_window_layout -> setContentsMargins(0,0,0,0);
    main_window_layout -> setSpacing(0);

    user_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    user_view -> setParent(this);

    main_window_layout -> addWidget(user_view);

}

MainWindow::~MainWindow()
{
    //delete ui;
}
