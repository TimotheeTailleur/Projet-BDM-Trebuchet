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

    //Connexion lancement du projectile :
    connect(ui->webcamWidget,SIGNAL(launch(int)),SLOT(launch(int)));

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

/* Initialisation du jeu
 * On change le niveau de difficulté et le nombre de cibles du jeu
 * On crée une nouvelle cible située dans la zone correspondant à la difficulté
 * On initialise le temps du jeu et de la cible courante à 0
 * Le glWidget devra maintenant afficher des cibles
 * On met à jour l'affichage pour afficher la cible nouvellement créée */
void Window::startGame()
{
    jeu_.startGame(difficultyLevel_,numberOfTargets_);
    ui->gameTime->setText(jeu_.getGameTime()->toString("mm:ss"));
    ui->currentTargetTime->setText(jeu_.getTargetTime()->toString("mm:ss"));
    ui->glWidget->setCible(jeu_.getCurrentTarget());
    ui->glWidget->gameStarted=true;
    ui->glWidget->update();

    timer_->start(1000);
}

//Slot de màj de l'affichage des temps
void Window::updateTimes()
{
    //Mise à jour gérée par l'objet jeu
    jeu_.updateTimes();

    //Modifications affichage ui
    ui->gameTime->setText(jeu_.getGameTime()->toString("mm:ss"));
    ui->currentTargetTime->setText(jeu_.getTargetTime()->toString("mm:ss"));
}

// Lancement du projectile
void Window::launch(int force){
    lancementEnCours_ = true;

    ui->glWidget->launch(force);
}
