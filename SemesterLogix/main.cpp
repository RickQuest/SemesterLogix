#pragma region Includes

#include <QApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include "MainViewModel.h"
#include "SelectionViewModel.h"
#include "ISchool.h"
#include "TableModel.h"
#include "SingletonProvider.h"

#pragma endregion


int main(int argc, char* argv[])
{

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    app.setOrganizationDomain("GPA548");
    qmlRegisterType<TableModel>("TableModel", 0, 1, "TableModel");
    
    QQmlApplicationEngine engine;

    SingletonProvider& provider = SingletonProvider::instance();
    MainViewModel mainViewModel;
    SelectionViewModel selectionViewModel;
    //CourseViewModel courseViewModel;
    //ScheduleViewModel scheduleViewModel;

    engine.rootContext()->setContextProperty("MainViewModel", &mainViewModel);
    engine.rootContext()->setContextProperty("SelectionViewModel", &selectionViewModel);
    engine.rootContext()->setContextProperty("ScheduleViewModel", provider.getScheduleViewModel());
    engine.rootContext()->setContextProperty("CourseViewModel", provider.getCourseViewModel());



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();


}

