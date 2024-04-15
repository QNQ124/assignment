// ==================================================================================== //
// FCAI – Structured Programming – 2024 - Assignment                                    //
//                                                                                      //
// File:    CS112_A3_Part3_S5S6_20230003_20230016_20230233.cpp                          //
//                                                                                      //
// Purpose: This program allows users to Applying filters to images It                  //
//          provides a user-friendly menu for selecting filters and                     //
//          saving the modified images.                                                 //
//                                                                                      //
// Author:  Ibrahim Mohamed Saad Mohamed_S6_20230003 => Filter 1, 4, 7, 10, 13, 15      //
//          Ahmed Hussein Mohamed Ahmed_S5_20230016  => Filter 2, 5, 8, 11, 14, 18      //
//          Ezz eldin Omar Abd El-latif_S6_20230233  => Filter 3, 6, 9, 12, 16, 17      //
//          TeamWork => Filter 19, 20                                                   //
//                                                                                      //
// Emails:  hes93314@gmail.com                                                          //
//          hzrdu3500@gmail.com                                                         //
//          ezzeldinomar7@gmail.com                                                     //
//                                                                                      //
// TA name: Rana Abdelkader                                                             //
// Date:    4/14/2024                                                                   //
// Version: 3.0                                                                         //
// ==================================================================================== //

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "ImageProcessor.h"


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon("assets/images/image.png"));

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

    ImageProcessor20 imageProcessor20;
    engine.rootContext()->setContextProperty("imageProcessor20", &imageProcessor20);

    ImageProcessor21 imageProcessor21;
    engine.rootContext()->setContextProperty("imageProcessor21", &imageProcessor21);

    ImageProcessor22 imageProcessor22;
    engine.rootContext()->setContextProperty("imageProcessor22", &imageProcessor22);

    ImageProcessor23 imageProcessor23;
    engine.rootContext()->setContextProperty("imageProcessor23", &imageProcessor23);

    const QUrl url(QStringLiteral("qrc:/First_GUI/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
