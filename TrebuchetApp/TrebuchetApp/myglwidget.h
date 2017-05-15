// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <glu.h>
#include <QThread>


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
};

#endif // MYGLWIDGET_H

