#include "terrain.h"

Terrain::Terrain()
{

}

void Terrain::loadGrassTexture()
{
    QImage image;
    image.load(":/src/img/grass.tiff");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();
    glGenTextures(1, &grassTexture[0]);
    glBindTexture(GL_TEXTURE_RECTANGLE, grassTexture[0]);
    glTexImage2D(GL_TEXTURE_RECTANGLE, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Terrain::loadFenceTexture()
{
    QImage image;
    image.load(":/src/img/fence.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();
    glGenTextures(1, &fenceTexture[0]);
    glBindTexture(GL_TEXTURE_2D, fenceTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Terrain::init()
{
    loadGrassTexture();
    loadFenceTexture();
}

void Terrain::draw(){

    glDisable(GL_CULL_FACE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable( GL_TEXTURE_RECTANGLE );


    /* Dessin du Gazon */
    glBindTexture(GL_TEXTURE_RECTANGLE, grassTexture[0]);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1,1,1);
    glTexCoord2f (0,0);
    glVertex3f(-30,-20,0);
    glTexCoord2f (512,0);
    glVertex3f(30,-20,0);
    glTexCoord2f (0,512);
    glVertex3f(-30,60,0);
    glTexCoord2f (512,512);
    glVertex3f(30,60,0);
    glEnd();
    glDisable( GL_TEXTURE_RECTANGLE );



    /*  Dessin du grillage */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, fenceTexture[0]);
    glDepthMask (GL_FALSE);
    glBegin(GL_QUAD_STRIP);
    glColor4f(1,1,1,0.);
    glTexCoord2f (0,0);
    glVertex3f(-30,-12,0);
    glTexCoord2f (0,1);
    glVertex3f(-30,-12,15);
    glTexCoord2f (1,0);
    glVertex3f(-30,60,0);
    glTexCoord2f (1,1);
    glVertex3f(-30,60,15);
    glTexCoord2f (0,0);
    glVertex3f(30,60,0);
    glTexCoord2f (0,1);
    glVertex3f(30,60,15);
    glTexCoord2f (1,0);
    glVertex3f(30,-12,0);
    glTexCoord2f (1,1);
    glVertex3f(30,-12,15);
    glEnd();
    glDepthMask (GL_TRUE);
    glDisable( GL_TEXTURE_2D );
}
