// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QThread>
#include <QDebug>
#include <QTimer>

//Dépendances Windows
#include <QtOpenGL>
#include <GL/glu.h>

/*Dépendances Mac
#include <OpenGL.h>
#include <glu.h> */

#include "trebuchet.h"
#include "cible.h"
#include "terrain.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

signals:

public:
    void rotate(int xRot, int yRot, int nbPas);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots pour rotation x,y,z
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    // slot pour récuperer les coordonnees de la main:
    void getCoords(int x, int y);


signals:
    // signaux pour rotation x,y,z
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:


    void draw();

    Terrain terrain;
    Trebuchet trebuchet;
    Cible cible;

    int xRot;
    int yRot;
    int zRot;

    int xPreviousHandPos;
    int yPreviousHandPos;

    int angle;


    QPoint lastPos;
};

#endif // MYGLWIDGET_H

