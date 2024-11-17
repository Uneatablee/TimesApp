#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../view/QtUserViewMain.hpp"
#include <memory>
#include "../view/QtViewStyles.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Time'sApp");
    resize(1280, 720);
    //setWindowFlags(Qt::FramelessWindowHint);

    this -> setStyleSheet(QtViewStyles::Styles);
    std::shared_ptr<QtUserViewMain> UserView = std::make_shared<QtUserViewMain>(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
