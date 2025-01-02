#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qpainter>

#include "../view/include/QtUserViewMain.hpp"

QT_BEGIN_NAMESPACE
    namespace Ui
    {
        class MainWindow;
    }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // MainWindow(QWidget *parent = nullptr);
    MainWindow(QtUserViewMain* = nullptr);
    ~MainWindow();
protected:

private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H