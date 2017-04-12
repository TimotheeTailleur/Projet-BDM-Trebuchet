#ifndef WEBCAMWIDGET_H
#define WEBCAMWIDGET_H

#include <QWidget>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <QDebug>

using namespace cv;
using namespace std;

class WebcamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WebcamWidget(QWidget *parent = 0);
    void updateFrame();

signals:

public slots:

protected:
    VideoCapture capture_;
    Mat currentFrame_;

};

#endif // WEBCAMWIDGET_H
