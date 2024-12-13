#include "mainwindow.h"
#include "../view/include/QtViewStyles.hpp"
#include <boost/di.hpp>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setStyleSheet(QtViewStyles::Styles);

    //main window
    auto main_window_injector = boost::di::make_injector();
    auto main_window = main_window_injector.create<std::unique_ptr<MainWindow>>();



    main_window -> show();
    return application.exec();
}
