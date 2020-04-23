#include <QApplication>
#include <QQmlApplicationEngine>

#include "MainWindow.h"


#define FRONT_END_TYPE_QML


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if defined(FRONT_END_TYPE_FORMS)
    MainWindow w;
    w.show();
#elif defined(FRONT_END_TYPE_QML)
    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile("../tutora/DictionaryManager.qml"));
#endif

    return app.exec();
}
