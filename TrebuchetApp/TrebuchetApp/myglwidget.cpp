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

    glEnable(GL_LIGHTING);
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

    glTranslatef(-10, 0, 0);
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
    gluPerspective(70,((float)width/(float)height),0.01,30);
    glMatrixMode(GL_MODELVIEW);
}


void MyGLWidget::draw()
{
    //Méthode finale

   terrain.draw();
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


void MyGLWidget::rotate(int xRot, int yRot, int nbPas){
    int initXRot = trebuchet.getAngleTrebuchet();
    int initYRot = trebuchet.getInsclinaisonTrebuchet();

    int tmpX;
    int tmpY;

    for (int i=0; i<nbPas+1; i++)
    {
        tmpX=(initXRot*(nbPas-i)+(xRot*i))/nbPas;
        tmpY=(initYRot*(nbPas-i)+(yRot*i))/nbPas;
        trebuchet.setAngleTrebuchet(tmpX);
        trebuchet.setInclinaisonTrebuchet(tmpY);
        trebuchet.draw();
        updateGL();
        QThread::usleep(100);


    }
}

void MyGLWidget::getCoords(int x, int y){


   // Dans cette méthode, on réutilise les coordonnées récupérées par le tracking de la webcam.


    // On réalise des if / else pour éviter que l'utilisateur tourne trop son trébuchet.
    if (y < 66){
        yRot = 66;
        if (x < 185) xRot = 185;
        else if(x> 210) xRot = 210;
        else xRot = x;


    }
    else if (y > 117){
        yRot = 117;
        if (x < 185) xRot = 185;
        else if(x> 210) xRot = 210;
        else xRot = x;
    }

    else{
        if (x < 185) xRot = 185;
        else if(x> 210) xRot = 210;
        else xRot = x;
        yRot = y;
    }

    qDebug() << x << " et y " << y;

    //angle = maxAngle-2*xRot*maxAngle;

    this->update();

}
