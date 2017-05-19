#ifndef WEBCAMWIDGET_H
#define WEBCAMWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QPushButton>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
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
    void followDetection();
    void capture();
    int getInitialX() {return initialX_;}
    int getInitialY() {return initialY_;}

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

    int initialX_;
    int initialY_;

    QPushButton webcamCapture;
    QPushButton reinitCapture;

    Vector<cv::Vec3f> vecCircles_;
    Vector<cv::Vec3f>::iterator itrCircles_;

    QTimer * tmrTimer_; //Car on ne peut pas avoir while(1) ou while(true) sinon le processeur ne pourra pas gérer.

    bool haveYouClicked_ = false;

private slots:
    void update();
    void on_webcamCapture_clicked();
    void on_reinitCapture_clicked();

signals:
    void getCoords(int x,int y);

};

#endif // WEBCAMWIDGET_H
