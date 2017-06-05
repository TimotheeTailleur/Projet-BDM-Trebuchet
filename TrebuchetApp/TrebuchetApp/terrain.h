#ifndef TERRAIN_H
#define TERRAIN_H
#include "cible.h"
#include <QImage>

#include <QtOpenGL>

/*Dépendances PC
#include <GL/glu.h>
#include <GL/gl.h>*/

/*Dépendances Mac*/
#include <glu.h>
#include <gl.h>


/*
 * Terrain de la scène OpenGL
 * */

class Terrain
{
public:
    Terrain();

    //Méthodes de dessin
    void draw();
    void init();

    //Chargement des textures
    void loadGrassTexture();
    void loadFenceTexture();
protected:

    GLuint grassTexture[1]; //Texture Herbe
    GLuint fenceTexture[1]; //Texture Grillage
};

#endif // TERRAIN_H
