#include "jeu.h"

using namespace std;

Jeu::Jeu()
{
    difficultyLevel_=0;
    numberOfTargets_=0;
    scoreList_={};
}


int Jeu::getDifficultyLevel()
{
    return difficultyLevel_;
}

int Jeu::getNumberOfTargets()
{
    return numberOfTargets_;
}

std::vector<Score> Jeu::getScoreList()
{
    return this->scoreList_;
}

 void Jeu::setDifficultyLevel(int difficultyLevel)
 {
     if (difficultyLevel > 3)
     {
         difficultyLevel_=3;
     }else
     {
        difficultyLevel_=difficultyLevel;
     }
 }

 void Jeu::setNumberOfTargets(int numberOfTargets)
 {
     numberOfTargets_=numberOfTargets;
 }


 void Jeu::saveScores(ofstream os)
 {
    os<<this->scoreList_.size()<<endl;
    vector<Score>::iterator it;
    for (std::vector<Score>::iterator it= scoreList_.begin();it!=scoreList_.end();it++)
    {
        it->saveScore(os);
    }
    os.close();
 }

 void Jeu::loadScores(ifstream &is)
 {
    int size;
    is>>size;

    scoreList_.resize(size* sizeof(Score));

    vector<Score>::iterator it;
    for ( it = scoreList_.begin(); it!=scoreList_.end(); it++)
    {
        it->loadScore(is);
    }
    is.close();
 }
