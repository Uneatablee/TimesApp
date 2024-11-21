#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../view/include/QtUserViewMain.hpp"
#include <memory>
#include "../view/include/QtViewStyles.hpp"
#include "QWidget"
#include "QBoxLayout"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Time'sApp");
    resize(1280, 720);
    //setWindowFlags(Qt::FramelessWindowHint);

    QWidget* central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    this -> setStyleSheet(QtViewStyles::Styles);
    this -> setProperty("class", "general-background");

    QBoxLayout* main_window_layout = new QBoxLayout(QBoxLayout::LeftToRight, central_widget);
    main_window_layout -> setContentsMargins(0,0,0,0);
    main_window_layout -> setAlignment(Qt::AlignLeft);
    main_window_layout -> setSpacing(0);

    QtUserViewMain* UserView = new QtUserViewMain(this);

    main_window_layout -> addWidget(UserView);
    main_window_layout -> addStretch();

}

MainWindow::~MainWindow()
{
    delete ui;
}
