#ifndef TERRAIN_H
#define TERRAIN_H
#include "cible.h"

class Terrain
{
public:
    Terrain();

    //Méthodes de dessin
    void draw();
    void init();
    void drawTargetRectangle(int difficultyLevel); //Dessine le rectangle dans lequel se trouvera la cible

    //Chargement des textures
    void loadGrassTexture();

protected:
    Cible target_;
};

#endif // TERRAIN_H
