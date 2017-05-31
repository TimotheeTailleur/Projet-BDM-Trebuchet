#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <QImage>
/*Dépendances Mac
#include <glu.h>*/

/*Dépendances PC*/
#include <GL/glu.h>

#include "projectile.h"

class Trebuchet
{
public:
    Trebuchet();

    //Méthodes de dessin
    void draw();
    void init();

    //Getters & Setters
    double getAngleTrebuchet();
    double getInsclinaisonTrebuchet();

    void setAngleTrebuchet(double angle);
    void setInclinaisonTrebuchet(double inclinaison);

    //Chargement des textures

    void loadWoodTexture(); //Charge la texture du trébuchet

    //Méthode pour dessiner les quads qui vont former le trébuchet
    void drawQuad(double length, double width);

    //Méthode pour créer la display list d'un pied du trébuchet
    void createFootDisplayList();

    Projectile ball;
protected:
    double angleTrebuchet_; //Angle pour rotation
    double inclinaisonBras_; //Inclinaison du bras

    GLuint footList; // GLuint qui contiendra la display list d'un pied du trebuchet

    GLuint woodTexture[1]; //Texture bois du trébuchet

};

#endif // TREBUCHET_H
