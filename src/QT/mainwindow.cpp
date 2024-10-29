#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Time'sApp");
    resize(1280, 720);
}

MainWindow::~MainWindow()
{
    delete ui;
}
