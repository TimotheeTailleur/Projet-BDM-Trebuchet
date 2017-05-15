#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <QImage>

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
    void loadLogoTexture(); //Charge la texture du logo TSe
    void loadWoodTexture(); //Charge la texture du trébuchet

protected:
    double angleTrebuchet_;
    double inclinaisonBras_;

};

#endif // TREBUCHET_H
