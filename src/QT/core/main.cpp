#include "mainwindow.h"
#include "../view/include/QtViewStyles.hpp"
#include <QApplication>
#include "QFontDatabase"

#include <boost/di.hpp>
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include "../view/include/QtUserViewMain.hpp"
#include "../view/include/MainViewArea.hpp"
#include "../view/include/SlidingLeftMenu.hpp"
#include "../view/include/CalendarView.hpp"
#include "../view/include/MonthView.hpp"
#include "../view/include/TasksEventsView.hpp"
#include "../view/include/TasksGroupView.hpp"
#include "../view/include/TopUtilityBar.hpp"

using namespace dp_business_logic::DayPlanner;

int main(int argc, char *argv[])
{
    //app setup
    QApplication application(argc, argv);
    application.setStyleSheet(QtViewStyles::Styles);
    QFontDatabase::addApplicationFont(":/fonts/montserrat_regular.ttf");

    //main window
    auto main_window_injector = boost::di::make_injector(
        boost::di::bind<IDateTimeGetter>.to<DateTimeGetter>()
    );
    auto main_window = main_window_injector.create<std::unique_ptr<MainWindow>>();

    main_window -> show();
    return application.exec();
}
