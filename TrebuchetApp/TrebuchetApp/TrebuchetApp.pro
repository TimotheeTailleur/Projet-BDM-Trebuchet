#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T15:07:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrebuchetApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        webcamwidget.cpp\
        myglwidget.cpp \
        window.cpp \
    cible.cpp \
    jeu.cpp \
    score.cpp \
    terrain.cpp \
    trebuchet.cpp \
    initdialogbox.cpp \
    projectile.cpp

HEADERS  += webcamwidget.h \
         myglwidget.h \
         window.h \
    cible.h \
    jeu.h \
    score.h \
    terrain.h \
    trebuchet.h \
    initdialogbox.h \
    projectile.h

FORMS    += webcamwidget.ui\
    window.ui \
    initdialogbox.ui

QT += opengl

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11.1

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13.2/include \


LIBS += -L/usr/local/Cellar/opencv/2.4.13.2/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d

RESOURCES += \
    src.qrc

