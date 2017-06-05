#ifndef PROJECTILE_H
#define PROJECTILE_H

/*Dépendances Mac*/

/*Dépendances PC*/
#include <GL/glu.h>
#include <QImage>


/*
 * Représentation du projectile du trébuchet.
 * Charge la texture pierre et possède des attributs
 * correspondant aux coordonnées du centre du projectile
 * */

class Projectile
{
public:
    Projectile();

    //Méthodes de dessin & initialisation
    void draw();
    void init();

    //Chargement texture projectile
    void loadProjectileTexture();


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

    //GLuint stockant la texture pierre du projectile
    GLuint ballTexture[1];

    //Chargement de la texture de pierre
    void loadBallTexture();


    //Coordonnées
    double x_;
    double y_;
    double z_;

};

#endif // PROJECTILE_H
