// myglwidget.cpp

#include <QtWidgets>
#include "myglwidget.h"
#include <QDebug>
#include <QtOpenGL>


MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 198;
    yRot = 88;
    zRot = 0;

    xPreviousHandPos = 198;
    yPreviousHandPos = 88;

    paintGL();
}



MyGLWidget::~MyGLWidget()
{
}

void MyGLWidget::initializeGL()
{
    // Couleur de fond = bleu ciel pour simuler un ciel clair.
    qglClearColor(Qt::cyan);

    // Initialisation de l'éclairage/ombrage:
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glShadeModel (GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    //Méthodes d'initialisations finales :
    terrain.init();
    trebuchet.init();
    cible.init();

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Initialisation du système de coordonnées.
    glRotatef(90.0,1.0,0.0,0.0);
    glRotatef(90.0,0.0,0.0,1.0);

    glTranslatef(-23, 0, 0);
    glRotatef(-xRot , 0.0, 1.0, 0.0);
    glRotatef(-yRot , 0.0, 0.0, 1.0);
    glRotatef(-zRot , 1.0, 0.0, 0.0);


    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,((float)width/(float)height),0.1,100);
    glMatrixMode(GL_MODELVIEW);
}


void MyGLWidget::draw()
{
    //Méthode finale

   terrain.draw();
   trebuchet.draw();
   cible.draw(10,10);
   //projectile.draw();
}


static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 1;
    while (angle > 360)
        angle -= 360 * 1;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void MyGLWidget::getCoords(int x, int y){

   // Dans cette méthode, on réutilise les coordonnées récupérées par le tracking de la webcam.

    trebuchet.setAngleTrebuchet(x);
    trebuchet.setInclinaisonTrebuchet(y);
    this->update();

}
