#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <QImage>
#include <glu.h>

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

protected:
    double angleTrebuchet_;
    double inclinaisonBras_;

    GLuint GLtextures[2];
    GLuint logoTexture[1]; //Texture logo TSE
    GLuint woodTexture[1]; //Texture bois du trébuchet
};

#endif // TREBUCHET_H
