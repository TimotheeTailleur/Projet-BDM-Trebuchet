#include "score.h"

using namespace std;

Score::Score(int difficultyLevel)
{
    name_="undefined";
    time_= QTime();
    difficultyLevel_=difficultyLevel;
    points_=0;
}

Score::Score(QString name, QTime time, int difficultyLevel, int points)
{
    name_=name;
    time_=time;
    difficultyLevel_=difficultyLevel;
    points_=points;
}

QString Score::getName()
{
    return name_;
}

QTime Score::getTime()
 {
    return time_;
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

void Score::setTime(string time)
{
    time_=QTime::fromString(QString::fromStdString(time),QString("mm:ss"));
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
    os<<time_.toString(QString("mm:ss")).toStdString()<<endl;
    os<<difficultyLevel_<<endl;
    os<<points_<<endl;
    os<<"#"<<endl;
}

void Score::loadScore(ifstream &is)
{
    string name;
    string time;
    getline(is,name);
    getline(is,time);
    this->setName(name);
    this->setTime(time);
    is>>difficultyLevel_;
    is.ignore();
    is>>points_;
}
