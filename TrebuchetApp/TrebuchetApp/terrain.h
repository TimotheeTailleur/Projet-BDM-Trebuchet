#ifndef TERRAIN_H
#define TERRAIN_H
#include "cible.h"
#include <QImage>
#include <GL/glu.h>

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
    Cible target_; //Cible du jeu

    GLuint GLtexture[1];
    GLuint grassTexture[1]; //Texture Herbe
};

#endif // TERRAIN_H
