#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ImageProcessor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Expose the ImageProcessor object to QML
    ImageProcessor1 imageProcessor1;
    engine.rootContext()->setContextProperty("imageProcessor1", &imageProcessor1);

    ImageProcessor2 imageProcessor2;
    engine.rootContext()->setContextProperty("imageProcessor2", &imageProcessor2);

    ImageProcessor3 imageProcessor3;
    engine.rootContext()->setContextProperty("imageProcessor3", &imageProcessor3);

    ImageProcessor4 imageProcessor4;
    engine.rootContext()->setContextProperty("imageProcessor4", &imageProcessor4);

    ImageProcessor5 imageProcessor5;
    engine.rootContext()->setContextProperty("imageProcessor5", &imageProcessor5);

    ImageProcessor6 imageProcessor6;
    engine.rootContext()->setContextProperty("imageProcessor6", &imageProcessor6);

    ImageProcessor7 imageProcessor7;
    engine.rootContext()->setContextProperty("imageProcessor7", &imageProcessor7);

    ImageProcessor8 imageProcessor8;
    engine.rootContext()->setContextProperty("imageProcessor8", &imageProcessor8);

    ImageProcessor9 imageProcessor9;
    engine.rootContext()->setContextProperty("imageProcessor9", &imageProcessor9);

    ImageProcessor10 imageProcessor10;
    engine.rootContext()->setContextProperty("imageProcessor10", &imageProcessor10);

    ImageProcessor11 imageProcessor11;
    engine.rootContext()->setContextProperty("imageProcessor11", &imageProcessor11);

    ImageProcessor12 imageProcessor12;
    engine.rootContext()->setContextProperty("imageProcessor12", &imageProcessor12);

    ImageProcessor13 imageProcessor13;
    engine.rootContext()->setContextProperty("imageProcessor13", &imageProcessor13);

    ImageProcessor14 imageProcessor14;
    engine.rootContext()->setContextProperty("imageProcessor14", &imageProcessor14);

    ImageProcessor15 imageProcessor15;
    engine.rootContext()->setContextProperty("imageProcessor15", &imageProcessor15);

    ImageProcessor16 imageProcessor16;
    engine.rootContext()->setContextProperty("imageProcessor16", &imageProcessor16);

    ImageProcessor17 imageProcessor17;
    engine.rootContext()->setContextProperty("imageProcessor17", &imageProcessor17);

    ImageProcessor18 imageProcessor18;
    engine.rootContext()->setContextProperty("imageProcessor18", &imageProcessor18);

    ImageProcessor19 imageProcessor19;
    engine.rootContext()->setContextProperty("imageProcessor19", &imageProcessor19);

    const QUrl url(QStringLiteral("qrc:/First_GUI/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
