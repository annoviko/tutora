#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>

#include "QmlDictionaryManager.h"


#define FRONT_END_TYPE_QML


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if defined(FRONT_END_TYPE_QML)
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/DictionaryManager.qml"));
    QQmlComponent component(&engine, url);
    component.create();

    QmlDictionaryManager dictionary_manager;

//    auto children = main_window->contentItem()->childItems();
//    for (auto & child : children) {
//        QObject * item = child->findChild<QObject *>("dictionary_manager");
//        if (item) {
//            QObject::connect(item, SIGNAL(signal_dict_insert(QString, QString)), &dictionary_manager, SLOT(SlotInsert(QString, QString)));
//        }
//    }

#endif

    return app.exec();
}
