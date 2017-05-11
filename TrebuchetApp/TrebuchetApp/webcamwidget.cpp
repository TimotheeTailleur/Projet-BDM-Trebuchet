#include "webcamwidget.h"
#include "ui_webcamwidget.h"

WebcamWidget::WebcamWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebcamWidget)
{
    ui->setupUi(this);

    cap_.open(0); // 0 pour cam défault.

    if(!cap_.isOpened()){
       ui->labelCam_->setText("Erreur: La caméra n'est pas detéctée!");
       return;
    }

    tmrTimer_ = new QTimer(this);
    connect(tmrTimer_, SIGNAL(timeout()), this, SLOT(update()));
    tmrTimer_->start(20); // 20 ms



}

WebcamWidget::~WebcamWidget()
{
    delete ui;
}

void WebcamWidget:: update(){
    cap_.read(matOriginal_);


    cap_.set(CV_CAP_PROP_FRAME_WIDTH,640);
    cap_.set(CV_CAP_PROP_FRAME_HEIGHT,480);

    int frameWidth=cap_.get(CV_CAP_PROP_FRAME_WIDTH);
    int frameHeight=cap_.get(CV_CAP_PROP_FRAME_HEIGHT);

    int templateWidth=64;
    int templateHeight=64;
    Rect templateRect((frameWidth-templateWidth)/2,2*(frameHeight-templateHeight)/3,templateWidth,templateHeight);


    if(matOriginal_.empty()) return; // eviter les redondances ??? éviter de perdre du temps ??
    inRange(matOriginal_, Scalar(0,0,175), Scalar(100,100,256), matProcessed_);
    GaussianBlur(matProcessed_, matProcessed_, Size(9,9), 1.5);
    //HoughCircles(matProcessed_, vecCircles_, CV_HOUGH_GRADIENT, 2, matProcessed_.rows / 4, 100, 50, 10, 400);

    for(itrCircles_ = vecCircles_.begin(); itrCircles_ != vecCircles_.end(); itrCircles_++) {
        circle(matOriginal_, Point((int)(*itrCircles_)[0], (int)(*itrCircles_)[1]), 3, Scalar(0,255,0), CV_FILLED);
        circle(matOriginal_, Point((int)(*itrCircles_)[0], (int)(*itrCircles_)[1]), (int)(*itrCircles_)[2], Scalar(0,0,255), 3);
        }

    cvtColor(matOriginal_, matOriginal_, CV_BGR2RGB);

    QImage qimgOriginal_((uchar*)matOriginal_.data, matOriginal_.cols, matOriginal_.rows, matOriginal_.step, QImage::Format_RGB888);
    QImage qimgProcessed_((uchar*)matProcessed_.data, matProcessed_.cols, matProcessed_.rows, matProcessed_.step, QImage::Format_Indexed8);

    flip(matOriginal_,matOriginal_,1);
    ui->label_2->setPixmap(QPixmap::fromImage(qimgOriginal_));
    ui->labelCam_->setPixmap(QPixmap::fromImage(qimgProcessed_));

    }
    /*
    cvtColor(matOriginal_,matOriginal_,CV_BGR2RGB);
    QImage qimgOriginal_((uchar*)matOriginal_.data, matOriginal_.cols, matOriginal_.rows, matOriginal_.step, QImage::Forma t_RGB888);

    ui->label_2->setPixmap(QPixmap::fromImage(qimgOriginal_));
*/
