#ifndef JEU_H
#define JEU_H

#include "score.h"
#include <vector>
#include <fstream>
using namespace std;

class Jeu
{
public:
    Jeu();

    //Getters & Setters
    int getDifficultyLevel();
    int getNumberOfTargets();
    vector<Score> getScoreList();

    void setDifficultyLevel(int difficultyLevel);
    void setNumberOfTargets(int numberOfTargets);

     //Sauvegarde des scores
    void saveScores(ofstream os);
    void loadScores(ifstream &is);
protected:
    int difficultyLevel_;
    int numberOfTargets_;
    vector<Score> scoreList_;
};

#endif // JEU_H
