#include "score.h"

using namespace std;

Score::Score(int difficultyLevel)
{
    name_="undefined";
    difficultyLevel_=difficultyLevel;
    points_=0;
}

Score::Score(QString name, int difficultyLevel, int points)
{
    name_=name;
    difficultyLevel_=difficultyLevel;
    points_=points;
}

QString Score::getName()
{
    return name_;
}


int Score::getDifficultyLevel()
{
    return difficultyLevel_;
}

int Score::getPoints()
{
    return points_;
}

void Score::setName(string name)
{
    name_=QString::fromStdString(name);
}


void Score::setDifficultyLevel(int difficultyLevel)
{
    this->difficultyLevel_=difficultyLevel;
}

void Score::setPoints(int points)
{
    this->points_=points;
}


void Score::saveScore(ofstream &os)
{
    os<<name_.toStdString()<<endl;
    os<<difficultyLevel_<<endl;
    os<<points_<<endl;
    os<<"#"<<endl;
}

void Score::loadScore(ifstream &is)
{
    string name;
    getline(is,name);
    this->setName(name);
    is>>difficultyLevel_;
    is.ignore();
    is>>points_;
}
