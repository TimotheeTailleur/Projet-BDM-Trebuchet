#ifndef PROJECTILE_H
#define PROJECTILE_H

/*Dépendances Mac*/

/*Dépendances PC*/
#include <glu.h>
#include <QImage>
#include <glu.h>

#define PI

class Projectile
{
public:
    Projectile();

    //Méthodes de dessin & initialisation
    void draw();
    void init();

    void loadProjectileTexture();


    //Méthode qui va mettre à jour la position en fonction du temps
    int updatePos();

    //Getters & Setters

    double getX();
    double getY();
    double getZ();

    void setX(double x);
    void setY(double y);
    void setZ(double z);

protected:
    //GLUquadric pour représenter la sphère
    GLUquadric* projectilePrmtrs;

    GLuint ballTexture[1];

    void loadBallTexture();


    //Coordonnées
    double x_;
    double y_;
    double z_;

};

#endif // PROJECTILE_H
