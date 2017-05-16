// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <GL/glu.h>
#include <QThread>

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

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);



public slots:


signals:


private:
    void draw();

    Terrain terrain;
    Trebuchet trebuchet;
    Cible cible;
};

#endif // MYGLWIDGET_H

