#ifndef JEU_H
#define JEU_H

#include "score.h"
#include "cible.h"
#include <vector>
#include <fstream>
#include <QTime>

/*
 * Modèle d'une partie du jeu. Gère le nombre de cibles, niveau de difficulté et l'affichage des temps.
 * La méthode startGame est appelée après lancement du suivi de la webcam.
 * */

using namespace std;

class Jeu
{
public:
    Jeu();

    //Getters & Setters
    int getDifficultyLevel();
    int getNumberOfTargets();
    vector<Score> getScoreList();

    QTime* getGameTime();
    QTime* getTargetTime();

    Cible* getCurrentTarget();

    void setDifficultyLevel(int difficultyLevel);
    void setNumberOfTargets(int numberOfTargets);

     //Sauvegarde & chargement des scores
    void saveScores(ofstream os);
    void loadScores(ifstream &is);

    //Lancement du jeu
    void startGame(int difficultyLevel=1, int numberOfTargets=5);

    /*
     * Mise à jour des temps (du jeu et de la cible courante). Appelée par un timer de la fenêtre principale Window
     * MàJ toutes les secondes */
    void updateTimes();
protected:
    int difficultyLevel_; //Niveau de difficulté : 1, 2 ou 3
    int numberOfTargets_; //Nombre de cibles
    vector<Score> scoreList_; //Liste des scores

    Cible* currentTarget_; //Cible courante

    QTime *tempsJeu_ ; //Temps de jeu

    QTime *tempsCibleCourante_; //Temps de la cible actuelle

};

#endif // JEU_H
