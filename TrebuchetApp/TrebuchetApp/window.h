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
    void setRot();
    void startGame(); //Démarrage du jeu après lancement du tracking par webcam
    void updateTimes(); //Mise à jour de l'affichage des temps toutes les 1000ms
    void launch();
};

#endif // WINDOW_H
