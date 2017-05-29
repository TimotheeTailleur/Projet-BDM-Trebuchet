#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QTime>
#include <fstream>
using namespace std;


class Score
{
public:
    Score(int difficultyLevel=0);
    Score(QString name, int difficultyLevel, int points);

    //Getters & Setters
    QString getName();
    int getDifficultyLevel();
    int getPoints();

    void setName(string name);
    void setDifficultyLevel(int difficultyLevel);
    void setPoints(int points);

    //Sauvegarde des scores
    void saveScore(ofstream &os);
    void loadScore(ifstream &is);
protected:
    QString name_; // Nom du joueur
    int difficultyLevel_;    //Niveau de difficulté (1,2 ou 3)
    int points_;     //Points marqués

};

#endif // SCORE_H
