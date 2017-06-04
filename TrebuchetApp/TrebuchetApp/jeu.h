#ifndef JEU_H
#define JEU_H

#include "score.h"
#include "cible.h"
#include <vector>
#include <fstream>
#include <QTime>


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

    //Gestion des temps
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
