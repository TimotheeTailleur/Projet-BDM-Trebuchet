#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <QImage>
/*Dépendances Mac
#include <glu.h> */

/*Dépendances PC*/
#include <GL/glu.h>

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
    void loadLogoTexture(); //Charge la texture du logo TSE
    void loadWoodTexture(); //Charge la texture du trébuchet

    //Méthode pour dessiner les quads qui vont former le trébuchet
    void drawQuad(double length, double width);

    //Méthode pour créer la display list d'un pied du trébuchet
    void createFootDisplayList();

protected:
    double angleTrebuchet_;
    double inclinaisonBras_;

    GLuint footList; // GLuint qui contiendra la display list d'un pied du trebuchet

    GLuint GLtextures[2];
    GLuint logoTexture[1]; //Texture logo TSE
    GLuint woodTexture[1]; //Texture bois du trébuchet
};

#endif // TREBUCHET_H
