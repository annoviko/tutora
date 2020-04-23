#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>

#include "MainWindow.h"
#include "QmlDictionaryManager.h"


#define FRONT_END_TYPE_QML


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if defined(FRONT_END_TYPE_FORMS)
    MainWindow w;
    w.show();
#elif defined(FRONT_END_TYPE_QML)
    QQuickView view(QUrl::fromLocalFile("../tutora/DictionaryManager.qml"));
    QObject * item = view.rootObject();

    QmlDictionaryManager dictionary_manager;
    QObject::connect(item, SIGNAL(signal_dict_insert(QString, QString)),
                     &dictionary_manager, SLOT(SlotInsert(QString, QString)));

    view.show();
//    QQmlApplicationEngine engine;
//    engine.load(QUrl::fromLocalFile("../tutora/DictionaryManager.qml"));
#endif

    return app.exec();
}
