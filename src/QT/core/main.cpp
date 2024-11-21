#include "mainwindow.h"
#include "../view/include/QtViewStyles.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setStyleSheet(QtViewStyles::Styles);

    MainWindow w;
    w.show();
    return application.exec();
}
