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

/*
 * Widget contenant la capture de la webcam.
 * Emet un signal quand l'utilisateur lance le tracking (démarre le jeu)
 * Emet un signal avec les coordonnées de la main de l'utilisateur après
 * chaque instance du template matching.
 * Le template matching est géré au moyen d'un timer qui met à jour l'affichage de la webcam
 * toutes les 10 milisecondes.
 * */

class WebcamWidget : public QWidget
{
    Q_OBJECT

public:

    //Constructeur, initialise l'UI, le timer et ouvre le flux de la webcam
    explicit WebcamWidget(QWidget *parent = 0);

    //Destructeur => suppression de l'ui en mémoire
    ~WebcamWidget();

    //Suivi de la détection ; réalise le template matching et émet le signal avec les coordonnées de la main
    void followDetection();

    //Capture d'une frame de la webcam & dessin du template
    void capture();

private:

    //Ui du widget
    Ui::WebcamWidget *ui;

    //Objet capture opencv
    VideoCapture cap_;

    //Matrice avec coordonnées de l'image capturée
    Mat matOriginal_;

    //Matrice avec coordonnées de l'image de template
    Mat matProcessing_;

    //Matrice avec coordonnées de l'image obtenue après template matching
    Mat matProcessed_;

    QImage qimgOriginal_;
    QImage qimgProcessing_;

    //Largeur image capturée
    int frameWidth_;
    //Hauteur image capturée
    int frameHeight_;

    //Largeur template
    int templateWidth_=50;
    //Hauteur template
    int templateHeight_=50;

    //Coordonnées de la main après template matching
    int x_;
    int y_;

    //Ancienne coordonnée en y de la main. Permet de gérer le lancement du projectile
    int previousY_;

    //Boutons démarrage et reset du suivi par caméra
    QPushButton webcamCapture;
    QPushButton reinitCapture;

    //Timer pour mise à jour de l'affichage toutes les  ms
    QTimer * tmrTimer_;

    //Vaut true si l'utilisateur a lancé le suivi de la main
    bool haveYouClicked_ = false;

private slots:

    //Mise à jour toutes les ms de l'affichage
    void update();

    //Lancement capture par bouton
    void on_webcamCapture_clicked();

    //Reset capture par bouton
    void on_reinitCapture_clicked();

signals:

    //Signal après changement des coordonnées de la main
    void getCoords(int x,int y);

    //Signal début capture -> lancement du Jeu
    void trackingStarted();

    //Signal lancement projectile
    void launch(int force);
};
#endif // WEBCAMWIDGET_H
