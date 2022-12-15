#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QObject>
#include "engine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<engine>("Engine", 1, 0, "Engine");

    QQmlApplicationEngine Qengine;
    Qengine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (Qengine.rootObjects().isEmpty())
        return -1;

    engine* m_engine = new engine();
    Qengine.rootContext()->setContextProperty("engine", m_engine);

    return app.exec();
}


