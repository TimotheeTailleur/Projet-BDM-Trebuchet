#include "webcamwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebcamWidget w;
    w.show();

    return a.exec();
}
