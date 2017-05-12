// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

#include <GL/glu.h>
#include <QDebug>
#include <QTimer>

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //initializeGL();
    paintGL();
}



MyGLWidget::~MyGLWidget()
{
    qDebug()<<"Fin myglwidget";
}


void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    draw();
}
void MyGLWidget::resizeGL(int width, int height)//propriete camera
{

}


void MyGLWidget::draw()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glEnable ( GL_NORMALIZE );
    glDepthMask ( GL_TRUE );
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glPointSize ( 1.0f );
    glLineWidth ( 1.0f );
    glEnable(GL_COLOR_MATERIAL);
    glDisable( GL_CULL_FACE );
    glPushMatrix ();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(0,1,0.25);
    glScalef(0.15,0.15,0.5);
    glBegin ( GL_TRIANGLES );
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glEnd ();
    glBegin ( GL_QUADS );
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glEnd ();
    glPopMatrix ();
    glPushMatrix ();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(1,1,0.25);
    glScalef(0.15,0.15,0.5);
    glBegin ( GL_TRIANGLES );
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0,0,-1);
    glVertex3f(0,0,-0.5);
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0,0,1);
    glVertex3f(0,0,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glEnd ();
    glBegin ( GL_QUADS );
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.66832,0.21715,-0.711473);
    glVertex3f(0.475528,0.154509,-0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.66832,0.21715,0.711473);
    glVertex3f(0.475528,0.154509,0.5);
    glNormal3f(0.568507,0.413045,-0.711473);
    glVertex3f(0.404509,0.293893,-0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0.568507,0.413045,0.711473);
    glVertex3f(0.404509,0.293893,0.5);
    glNormal3f(0.413045,0.568507,-0.711473);
    glVertex3f(0.293893,0.404509,-0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(0.413045,0.568507,0.711473);
    glVertex3f(0.293893,0.404509,0.5);
    glNormal3f(0.21715,0.66832,-0.711473);
    glVertex3f(0.154508,0.475528,-0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(0.21715,0.66832,0.711473);
    glVertex3f(0.154508,0.475528,0.5);
    glNormal3f(-6.36106e-008,0.702713,-0.711473);
    glVertex3f(-2.18557e-008,0.5,-0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-6.36106e-008,0.702713,0.711473);
    glVertex3f(-2.18557e-008,0.5,0.5);
    glNormal3f(-0.21715,0.66832,-0.711473);
    glVertex3f(-0.154509,0.475528,-0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.21715,0.66832,0.711473);
    glVertex3f(-0.154509,0.475528,0.5);
    glNormal3f(-0.413045,0.568507,-0.711473);
    glVertex3f(-0.293893,0.404509,-0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.413045,0.568507,0.711473);
    glVertex3f(-0.293893,0.404509,0.5);
    glNormal3f(-0.568507,0.413045,-0.711473);
    glVertex3f(-0.404509,0.293893,-0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.568507,0.413045,0.711473);
    glVertex3f(-0.404509,0.293893,0.5);
    glNormal3f(-0.66832,0.21715,-0.711473);
    glVertex3f(-0.475528,0.154508,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.66832,0.21715,0.711473);
    glVertex3f(-0.475528,0.154508,0.5);
    glNormal3f(-0.702714,-6.36106e-008,-0.711473);
    glVertex3f(-0.5,-4.37114e-008,-0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.702714,-6.36106e-008,0.711473);
    glVertex3f(-0.5,-4.37114e-008,0.5);
    glNormal3f(-0.66832,-0.21715,-0.711473);
    glVertex3f(-0.475528,-0.154508,-0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.66832,-0.21715,0.711473);
    glVertex3f(-0.475528,-0.154508,0.5);
    glNormal3f(-0.568507,-0.413045,-0.711473);
    glVertex3f(-0.404508,-0.293893,-0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(-0.568507,-0.413045,0.711473);
    glVertex3f(-0.404508,-0.293893,0.5);
    glNormal3f(-0.413045,-0.568507,-0.711473);
    glVertex3f(-0.293893,-0.404509,-0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(-0.413045,-0.568507,0.711473);
    glVertex3f(-0.293893,-0.404509,0.5);
    glNormal3f(-0.21715,-0.66832,-0.711473);
    glVertex3f(-0.154509,-0.475528,-0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(-0.21715,-0.66832,0.711473);
    glVertex3f(-0.154509,-0.475528,0.5);
    glNormal3f(0,-0.702714,-0.711473);
    glVertex3f(5.96244e-009,-0.5,-0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0,-0.702714,0.711473);
    glVertex3f(5.96244e-009,-0.5,0.5);
    glNormal3f(0.217151,-0.66832,-0.711473);
    glVertex3f(0.154509,-0.475528,-0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.217151,-0.66832,0.711473);
    glVertex3f(0.154509,-0.475528,0.5);
    glNormal3f(0.413045,-0.568507,-0.711473);
    glVertex3f(0.293893,-0.404508,-0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.413045,-0.568507,0.711473);
    glVertex3f(0.293893,-0.404508,0.5);
    glNormal3f(0.568507,-0.413044,-0.711473);
    glVertex3f(0.404509,-0.293892,-0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glNormal3f(0.568507,-0.413044,0.711473);
    glVertex3f(0.404509,-0.293892,0.5);
    glNormal3f(0.66832,-0.21715,-0.711473);
    glVertex3f(0.475528,-0.154508,-0.5);
    glNormal3f(0.702714,-1.06018e-008,-0.711473);
    glVertex3f(0.5,0,-0.5);
    glNormal3f(0.702714,-1.06018e-008,0.711473);
    glVertex3f(0.5,0,0.5);
    glNormal3f(0.66832,-0.21715,0.711473);
    glVertex3f(0.475528,-0.154508,0.5);
    glEnd ();
    glPopMatrix ();
    glEnable( GL_TEXTURE_RECTANGLE );

   // glBindTexture(GL_TEXTURE_RECTANGLE, GLtexture[0]);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1,1,1);
    glTexCoord2f (0,0);
    glVertex3f(0,0,0);
    glTexCoord2f (512,0);
    glVertex3f(1,0,0);
    glTexCoord2f (0,512);
    glVertex3f(0,1,0);
    glTexCoord2f (512,512);
    glVertex3f(1,1,0);
    glEnd();
    glDisable( GL_TEXTURE_RECTANGLE );
    glEnable( GL_TEXTURE_2D );

    glBindTexture(GL_TEXTURE_2D,0);
    glDepthMask (GL_FALSE);
    glBegin(GL_QUAD_STRIP);
    glColor4f(1,1,1,0.3);
    glTexCoord2f (0,0);
    glVertex3f(0,0,0);
    glTexCoord2f (0,1);
    glVertex3f(0,0,0.5);
    glTexCoord2f (1,0);
    glVertex3f(0,1,0);
    glTexCoord2f (1,1);
    glVertex3f(0,1,0.5);
    glTexCoord2f (0,0);
    glVertex3f(1,1,0);
    glTexCoord2f (0,1);
    glVertex3f(1,1,0.5);
    glTexCoord2f (1,0);
    glVertex3f(1,0,0);
    glTexCoord2f (1,1);
    glVertex3f(1,0,0.5);
    glEnd();
    glDepthMask (GL_TRUE);
    glDisable( GL_TEXTURE_2D );
}
