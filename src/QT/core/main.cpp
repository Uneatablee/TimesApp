#include "mainwindow.h"
#include "../view/include/QtViewStyles.hpp"
#include <QApplication>

#include <boost/di.hpp>
#include "DateTimeGetter.hpp"
#include "../view/include/QtUserViewMain.hpp"
#include "../view/include/MainViewArea.hpp"
#include "../view/include/SlidingLeftMenu.hpp"
#include "../view/include/CalendarView.hpp"
#include "../view/include/MonthView.hpp"
#include "../view/include/TasksEventsView.hpp"
#include "../view/include/TasksGroupView.hpp"
#include "../view/include/TopUtilityBar.hpp"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setStyleSheet(QtViewStyles::Styles);

    //main window
    // auto main_window_injector = boost::di::make_injector(
    //     //boost::di::bind<QtUserViewMain>.to<QtUserViewMain>()
    // );
    // auto main_window = main_window_injector.create<std::unique_ptr<MainWindow>>();

    auto calendar_view = new CalendarView();
    auto month_view = new MonthView();
    auto top_utility_bar = new TopUtilityBar();
    auto tasks_group_view = new TasksGroupView();
    auto tasks_option_view = new TasksEventsView();

    auto main_view_area = new MainViewArea(calendar_view, month_view, tasks_option_view, tasks_group_view, top_utility_bar);
    auto left_menu_slider = new SlidingLeftMenu();

    auto user_view = new QtUserViewMain(main_view_area, left_menu_slider);

    auto main_window = new MainWindow(user_view);


    main_window -> show();
    return application.exec();
}
