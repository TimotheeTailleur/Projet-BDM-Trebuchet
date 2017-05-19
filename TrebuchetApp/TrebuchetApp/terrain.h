#ifndef TERRAIN_H
#define TERRAIN_H
#include "cible.h"
#include <QImage>

#include <QtOpenGL>

/*Dépendances PC*/
#include <GL/glu.h>
#include <GL/gl.h>

/*Dépendances Mac
* #include <glu.h>
* #include <gl.h> */


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
    void loadFenceTexture();

protected:
    Cible target_; //Cible du jeu

    GLuint GLtexture[1];
    GLuint grassTexture[1]; //Texture Herbe
    GLuint fenceTexture[1]; //Texture Grillage
};

#endif // TERRAIN_H
