#include "webcamwidget.h"
#include "ui_webcamwidget.h"
#include <QDebug>

WebcamWidget::WebcamWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebcamWidget)
{
    ui->setupUi(this);

    cap_.open(0); // 0 pour cam défault.

    if(!cap_.isOpened()){
       ui->label_2->setText("Erreur: La caméra n'est pas detéctée!");
       return;
    }

    tmrTimer_ = new QTimer(this);


    connect(tmrTimer_, SIGNAL(timeout()), this, SLOT(update()));
    tmrTimer_->start(10); // 10 ms
    previousY = 15;
}

WebcamWidget::~WebcamWidget()
{
    delete ui;
}

void WebcamWidget:: update(){

    // Initialisation
    cap_.read(matOriginal_);
    cap_.set(CV_CAP_PROP_FRAME_WIDTH,320);
    cap_.set(CV_CAP_PROP_FRAME_HEIGHT,240);

    frameWidth_=cap_.get(CV_CAP_PROP_FRAME_WIDTH);
    frameHeight_=cap_.get(CV_CAP_PROP_FRAME_HEIGHT);

    if(matOriginal_.empty()) return; // eviter les redondances ??? éviter de perdre du temps ??

    // Rajout de couleur
    cvtColor(matOriginal_, matOriginal_, CV_BGR2RGB);

    // Traitement sur le fait que l'utilisateur ait cliqué ou non sur le bouton de capture.

    if(!haveYouClicked_){
        capture();
    }

    else{
        flip(matOriginal_,matOriginal_,1);
        followDetection();

    }
}

void WebcamWidget::capture(){
    // Initialisation + Dessin de la Template de Capture :

    Rect rectProcessing((frameWidth_-templateWidth_)/2,(frameHeight_-templateHeight_)/2,templateWidth_,templateHeight_);
    rectangle(matOriginal_, rectProcessing, Scalar(255,0,0),2,8,0);

    // Récupération des captures + affichages dans le label.

    QImage qimgOriginal_((uchar*)matOriginal_.data, matOriginal_.cols, matOriginal_.rows, matOriginal_.step, QImage::Format_RGB888);
    flip(matOriginal_,matOriginal_,1);
    ui->label_2->setPixmap(QPixmap::fromImage(qimgOriginal_));

}


void WebcamWidget::on_webcamCapture_clicked(){

    haveYouClicked_ = true;

    // Initialisation de la Template de Capture :

    Rect rectProcessing((frameWidth_-templateWidth_)/2,(frameHeight_-templateHeight_)/2,templateWidth_,templateHeight_);

    // Récupération du carré capturé
    Mat temp(matOriginal_, rectProcessing);
    temp.copyTo(matProcessing_);

    // On affiche l'image capturée pour connaitre sur quoi est fait le traitement
    QImage qimgProcessing_((uchar*)matProcessing_.data, matProcessing_.cols, matProcessing_.rows, matProcessing_.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qimgProcessing_));

    emit trackingStarted();

}

void WebcamWidget::on_reinitCapture_clicked(){
    haveYouClicked_ = false;
}

void WebcamWidget::followDetection(){

    // Creation des lignes/colonnes de la matrice de résultats:
    int result_cols =  frameWidth_ - templateWidth_ + 1;
    int result_rows = frameHeight_- templateHeight_ + 1;
    matProcessed_.create(result_rows, result_cols, CV_32FC1);

    // Appel à la fonction Match Template de méthode 3 + segmentation:
    matchTemplate(matOriginal_,matProcessing_,matProcessed_,TM_CCORR_NORMED);
    threshold(matProcessed_, matProcessed_, 0.1, 1, CV_THRESH_TOZERO);

    // Recherche de la meilleure correspondance :
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    minMaxLoc(matProcessed_, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

    // Sauvegarde de la location pour le rectangle qui lui correspond (matched)
    Rect resultRect = Rect(maxLoc.x, maxLoc.y, templateWidth_, templateHeight_);
    rectangle(matOriginal_,resultRect, Scalar(0,255,0), 2, 8, 0);

    // Dessin du rectangle de délimitation :

    Rect limitRect = Rect(99,77,115,85);
    rectangle(matOriginal_,limitRect,Scalar(0,0,255), 2,8,0);

    // Application du traitement au label pour afficher la webcam:

    QImage qimgOriginal_((uchar*)matOriginal_.data, matOriginal_.cols, matOriginal_.rows, matOriginal_.step, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(qimgOriginal_));

    initialX_ = resultRect.x + 130;
    initialY_ = resultRect.y -80;

    // On emet le signal pour récuperer les coordonnées:

    emit getCoords(initialX_, initialY_);


    // On emet le signal de lancement en fonction de la puissance :

    if (initialY_ - previousY > 40){
        qDebug() << "previous" << previousY;
        if (previousY < 14 ){
            previousY=5;
            emit launch(previousY);}

        else if (  previousY>14 && previousY<40){
            previousY = 10;
            emit launch(previousY);
        }

        else{
            previousY=15;
            emit launch(previousY);
        }

    }
    previousY = initialY_;
    }
