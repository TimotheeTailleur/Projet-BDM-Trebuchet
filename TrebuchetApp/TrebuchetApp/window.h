#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "jeu.h"
#include "initdialogbox.h"

namespace Ui {
class Window;
}

/*
 * Fenêtre principale de l'application.
 * Récupère les paramètres de l'utilisateur depuis l'initDialogBox (nom, difficulté, nombre de cibles)
 * Gère l'objet Jeu et gère la mise à jour de l'affichage des temps (temps de jeu et temps de la cible courante)
 * Récupère les signaux du webcamwidget et les connecte aux slots correspondants de glWidget.
 * */
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Window *ui;
    Jeu jeu_;

    QString playerName_;
    int difficultyLevel_;
    int numberOfTargets_;

     QTimer *timer_ ; //Timer pour MàJ de l'affichage des temps de jeu
     bool lancementEnCours_;

private slots:
    void startGame(); //Démarrage du jeu après lancement du tracking par webcam
    void updateTimes(); //Mise à jour de l'affichage des temps toutes les 1000ms
    void launch(int force);
};

#endif // WINDOW_H
