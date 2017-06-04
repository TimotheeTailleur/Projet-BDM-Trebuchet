// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QThread>
#include <QDebug>
#include <QTimer>

/*Dépendances Windows*/
#include <QtOpenGL>
#include <glu.h>

/*Dépendances Mac
#include <OpenGL.h>
#include <glu.h> */

#include "trebuchet.h"
#include "cible.h"
#include "terrain.h"
#include "projectile.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

    bool gameStarted=false;

signals:

public:
    void launch(int force); //Lancement du projectile

    void loadLogoTexture(); //Charge la texture du logo TSE

    void setCible(Cible* cible);

protected:

    //Méthodes de dessin
    void initializeGL();
    void paintGL();
    void draw();
    void resizeGL(int width, int height);
    void drawLogo(int x, int y, int z, double angleX, double angleY, double angleZ); //Dessine le logo TSE aux coordonnées x,y,z

    //Gestion des évènements
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

    //Elements du modèle
    Terrain terrain_;
    Trebuchet trebuchet_;
    Projectile projectile_;
    Cible * cible_;



    int xRot;
    int yRot;
    int zRot;

    int xPreviousHandPos;
    int yPreviousHandPos;

    int angle;

    QPoint lastPos;

    GLuint logoTexture[1]; //Texture logo TSE

};

#endif // MYGLWIDGET_H

