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
    glBindTexture(GL_TEXTURE_2D, grassTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
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
    //TODO Initialize Terrain
}
