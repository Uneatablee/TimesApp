#include "mainwindow.h"
#include "../view/include/QtViewStyles.hpp"
#include <QApplication>
#include "QFontDatabase"

#include <boost/di.hpp>
#include "IDateTimeGetter.hpp"
#include "DateTimeGetter.hpp"
#include "IGenericRepository.hpp"
//#include "GenericRepository.hpp"
#include "GenericRepositorySQLite.hpp"
#include "BaseEntity.hpp"

#include "../view/include/QtUserViewMain.hpp"
#include "../view/include/MainViewArea.hpp"
#include "../view/include/SlidingLeftMenu.hpp"
#include "../view/include/CalendarView.hpp"
#include "../view/include/MonthView.hpp"
#include "../view/include/TasksEventsView.hpp"
#include "../view/include/TasksGroupView.hpp"
#include "../view/include/TopUtilityBar.hpp"

using namespace dp_business_logic::DayPlanner;
//using namespace data_access_layer::dal::memory;
using namespace data_access_layer::dal::sqlite;

int main(int argc, char *argv[])
{
    const char* home = std::getenv("HOME");
    if (!home)
    {
        throw std::runtime_error("Failed accessing home directory!");
    }
    std::filesystem::path home_dir = home;
    const std::string app_path = (home_dir / "Library" / "Application Support" / "TimesApp").string();
    try
    {
        std::filesystem::create_directories(app_path);
        std::cout << "Folder created at: " << app_path << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to create directory: " << e.what() << std::endl;
    }

    try{
        //app setup
        QApplication application(argc, argv);
        application.setStyleSheet(QtViewStyles::Styles);
        QFontDatabase::addApplicationFont(":/fonts/montserrat_regular.ttf");

        //main window
        auto application_di_container = boost::di::make_injector(
            boost::di::bind<IDateTimeGetter>.to<DateTimeGetter>(),
            boost::di::bind<IGenericRepository<Event>>.to<GenericRepository<Event>>(),
            boost::di::bind<GenericRepository<Event>>().to<std::string>(app_path)
        );
        auto main_window = application_di_container.create<std::unique_ptr<MainWindow>>();

        main_window -> show();
        return application.exec();
    }
    catch(std::exception e)
    {
        std::cerr << e.what();
    }
}
