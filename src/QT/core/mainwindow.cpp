#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../view/QtUserView.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Time'sApp");
    resize(1280, 720);

    QtUserView* UserView = new QtUserView(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
