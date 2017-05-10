#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T13:52:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Trebuchet
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11.1


SOURCES += main.cpp\
        mainwindow.cpp \
    webcamwidget.cpp

HEADERS  += mainwindow.h \
    webcamwidget.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13.2/include

LIBS += -L/usr/local/Cellar/opencv/2.4.13.2/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
