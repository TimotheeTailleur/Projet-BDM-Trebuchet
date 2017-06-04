#ifndef CIBLE_H
#define CIBLE_H
#include <GL/glu.h>
#include <QImage>
#include <QTime>

class Cible
{
public:
    Cible(int difficultyLevel);

    void draw();
    void init();


protected:
    GLUquadric *gluTargetPrmtrs;
    GLuint targetTexture[1];

    void loadTargetTexture();

    int checkCollision(double xProjectile, double yProjectile, double zProjectile); //Méthode qui va vérifier les collisions

    void getDifficultyLevel();
    void setDifficultyLevel();

protected:
    double xpos_; //Position en x de la cible
    double ypos_;   // Position en y de la cible
};

#endif // CIBLE_H
