#ifndef JEU_H
#define JEU_H

#include "score.h"
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

    QTime* getTime();

    void setDifficultyLevel(int difficultyLevel);
    void setNumberOfTargets(int numberOfTargets);

     //Sauvegarde & chargement des scores
    void saveScores(ofstream os);
    void loadScores(ifstream &is);

    //Lancement du jeu
    void startGame(int difficultyLevel=0, int numberOfTargets=5);

    //Gestion des temps
    void updateTimes();
protected:
    int difficultyLevel_; //Niveau de difficulté : 0,1 ou 2
    int numberOfTargets_; //Nombre de cibles
    vector<Score> scoreList_; //Liste des scores

    QTime *tempsJeu_ ; //Temps de jeu

};

#endif // JEU_H
