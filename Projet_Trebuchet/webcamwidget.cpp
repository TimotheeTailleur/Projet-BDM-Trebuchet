#include "webcamwidget.h"

WebcamWidget::WebcamWidget(QWidget *parent) : QWidget(parent)
{
    capture_ = VideoCapture(0); // open the default camera
    if(!capture_.isOpened())  // check if we succeeded
        cerr<<"Error openning the default camera"<<endl;
}

void WebcamWidget::updateFrame(){
    Mat frame;
    capture_ >> frame;
}
