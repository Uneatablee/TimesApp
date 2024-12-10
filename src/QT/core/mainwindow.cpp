#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../view/include/QtUserViewMain.hpp"
#include <memory>
#include "../view/include/QtViewStyles.hpp"
#include "QWidget"
#include "QBoxLayout"
#include "QSizePolicy"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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

    QtUserViewMain* user_view = new QtUserViewMain(this);
    user_view -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    main_window_layout -> addWidget(user_view);

}

MainWindow::~MainWindow()
{
    delete ui;
}
