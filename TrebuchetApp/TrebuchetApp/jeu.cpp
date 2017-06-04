#include "jeu.h"
#include <QDebug>

using namespace std;

Jeu::Jeu()
{
    scoreList_={};
    tempsJeu_= new QTime(0,0,0);
    tempsCibleCourante_ = new QTime(0,0,0);
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

Cible* Jeu::getCurrentTarget()
{
    return currentTarget_;
}


 void Jeu::setDifficultyLevel(int difficultyLevel)
 {
     if (difficultyLevel > 2)
     {
         difficultyLevel_=2;
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

 void Jeu::startGame(int difficultyLevel, int numberOfTargets){

     tempsJeu_= new QTime(0,0,0);
     tempsCibleCourante_ = new QTime(0,0,0);
     this->setDifficultyLevel(difficultyLevel);
     this->setNumberOfTargets(numberOfTargets);
     currentTarget_ = new Cible(difficultyLevel_);
 }

 QTime* Jeu::getGameTime()
 {
     return tempsJeu_;
 }

 QTime* Jeu::getTargetTime()
 {
     return tempsCibleCourante_;
 }

 void Jeu::updateTimes()
 {
   *tempsJeu_= tempsJeu_->addSecs(1);
   *tempsCibleCourante_ = tempsCibleCourante_->addSecs(1);
 }
