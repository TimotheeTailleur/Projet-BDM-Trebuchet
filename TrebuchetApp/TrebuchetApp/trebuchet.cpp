#include "trebuchet.h"

Trebuchet::Trebuchet()
{

}

void Trebuchet::draw()
{

}

void Trebuchet::init()
{
    loadLogoTexture();
    loadWoodTexture();
    //TODO Initialize Trebuchet
}

void Trebuchet::loadLogoTexture()
{

    QImage image;
    image.load(":/src/img/TSE.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &logoTexture[0]);
    glBindTexture(GL_TEXTURE_2D, logoTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

void Trebuchet::loadWoodTexture()
{

    QImage image;
    image.load(":/src/img/wood.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &woodTexture[0]);
    glBindTexture(GL_TEXTURE_2D, woodTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

double Trebuchet::getAngleTrebuchet()
{
    return angleTrebuchet_;
}

double Trebuchet::getInsclinaisonTrebuchet()
{
    return inclinaisonBras_;
}

void Trebuchet::setAngleTrebuchet(double angle)

{
    angleTrebuchet_=angle;
}

void Trebuchet::setInclinaisonTrebuchet(double inclinaison)
{
    inclinaisonBras_=inclinaison;
}
