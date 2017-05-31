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
    loadLogoTexture(); //On charge la texture du Logo

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

   //Logo gauche
   drawLogo(-30,2,5,90,90,0);

   //Logo centre
   drawLogo (0, 60, 5,90,0,0);

   //Logo droit
   drawLogo(30,2,5,90,90,0);
}

void MyGLWidget::drawLogo(int x, int y, int z,double angleX ,double angleY, double angleZ)
{
    glPushMatrix();

    glTranslated(x,y,z);
    glRotated(angleX,1,0,0);
    glRotated(angleY,0,1,0);
    glRotated(angleZ,0,0,1);

    glColor3ub(255,255,255);

    glBindTexture(GL_TEXTURE_2D, logoTexture[0]);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);

        glTexCoord2d(0,0);
        glVertex3d(0,0,0);

        glTexCoord2d(0,1);
        glVertex3d(0,8,0);

        glTexCoord2d(1,1);
        glVertex3d(8,8,0);

        glTexCoord2d(1,0);
        glVertex3d(8,0,0);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

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
    //this->launch(15);
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



void MyGLWidget::launch(int force){

   double tmpZ;
   double tmpY;
   qDebug() << force;

   if(force == 5){
       for (int i=0; i<(6); i++)
       {
           tmpZ=(0.5*i*i -  0.5*(5)*i)-1;
           tmpY= ((5)*i)*0.5 -4;
           trebuchet.ball.setX(tmpZ);
           trebuchet.ball.setZ(-tmpY);
           updateGL();
           QThread::usleep(90000);
       }
   }

   else if(force == 10){
       for (int i=0; i<(11); i++)
       {
           tmpZ=(0.5*i*i -  0.5*(10)*i)-1;
           tmpY= ((10)*i)*0.5 -4;
           trebuchet.ball.setX(tmpZ);
           trebuchet.ball.setZ(-tmpY);
           updateGL();
           QThread::usleep(90000);
       }
   }

   else{
       for (int i=0; i<(14); i++)
       {
           tmpZ=(0.5*i*i -  0.5*(13)*i)-1;
           tmpY= ((15)*i)*0.5 -4;
           trebuchet.ball.setX(tmpZ);
           trebuchet.ball.setZ(-tmpY);
           updateGL();
           QThread::usleep(90000);
       }
   }

   QThread::msleep(1500);
   trebuchet.ball.setX(0);
   trebuchet.ball.setY(0);
   trebuchet.ball.setZ(4);
}


void MyGLWidget::loadLogoTexture()
{

    QImage image;
    image.load(":/src/img/TSE.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &logoTexture[0]);
    glBindTexture(GL_TEXTURE_2D, logoTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}
