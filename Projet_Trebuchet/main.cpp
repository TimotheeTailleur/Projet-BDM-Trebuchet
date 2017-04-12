#include "mainwindow.h"
#include "webcamwidget.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    WebcamWidget *web  = new WebcamWidget();
    web->updateFrame();

    return a.exec();
}
