#include "window.h"
#include "ui_window.h"

#include <QDebug>


Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this); //Setup Ui
    timer_= new QTimer(this); //Instanciation timer affichage des temps

    //Dialog Box d'initialisation de la partie
    InitDialogBox initDialogBox(this,&playerName_,&difficultyLevel_,&numberOfTargets_);
    initDialogBox.exec();

    //Connexion timer & slot de màj des temps
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTimes()));

    // Connexion entre la webcam et le gl widget.
    connect(ui->webcamWidget, SIGNAL(getCoords(int,int)),ui->glWidget, SLOT(getCoords(int,int)));

    //Connexion début tracking du mouvement avec initialisation des paramètres du jeu & du chronomètre
    connect(ui->webcamWidget,SIGNAL(trackingStarted()),SLOT(startGame()));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void Window::setRot(){
   /* int x = ui->webcamWidget->getInitialX();
    int y = ui->webcamWidget->getInitialY();

    x = x*20-10;
    y = y*20-10;

    ui->glWidget->rotate(x,y,20);*/
}


/*
 * Slot de démarrage du jeu :
 * On initialise les paramètres du jeu, on lance l'affichage des temps
 * et on définit le timeout du timer qui mettra à jour les temps affichés
 * */
void Window::startGame()
{
    jeu_.startGame(difficultyLevel_,numberOfTargets_);
    ui->gameTime->setText(jeu_.getTime()->toString("mm:ss"));

    timer_->start(1000);
}

//Slot de màj de l'affichage des temps
void Window::updateTimes()
{
    //Mise à jour gérée par l'objet jeu
    jeu_.updateTimes();

    //Modifications affichage ui
    ui->gameTime->setText(jeu_.getTime()->toString("mm:ss"));
    //ui->currentTargetTime->setText();
}
