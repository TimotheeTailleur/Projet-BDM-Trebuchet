#ifndef WEBCAMWIDGET_H
#define WEBCAMWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QPushButton>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;


namespace Ui {
class WebcamWidget;
}

class WebcamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WebcamWidget(QWidget *parent = 0);
    ~WebcamWidget();

private:


    Ui::WebcamWidget *ui;
    VideoCapture cap_;


    Mat matOriginal_;
    Mat matProcessing_;
    Mat matProcessed_;

    QImage qimgOriginal_;
    QImage qimgProcessing_;
    QImage qimgProcessed_;

    int frameWidth_;
    int frameHeight_;

    int templateWidth_=50;
    int templateHeight_=50;

    QPushButton webcamCapture;

    Vector<cv::Vec3f> vecCircles_;
    Vector<cv::Vec3f>::iterator itrCircles_;


    QTimer * tmrTimer_; //Car on ne peut pas avoir while(1) ou while(true) sinon le processeur ne pourra pas gérer.
public slots:
    void update();
    void detect();

    void on_webcamCapture_clicked();
};

#endif // WEBCAMWIDGET_H
