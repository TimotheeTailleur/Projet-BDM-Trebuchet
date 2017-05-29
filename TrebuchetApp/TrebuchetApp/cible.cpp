#include "cible.h"

Cible::Cible()
{

}


void Cible::draw(int xpos, int ypos)
{

    glBindTexture(GL_TEXTURE_2D, targetTexture[0]);
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(xpos,ypos,2);
    glRotated(45,1.0,0,0); //Rotation pour mettre la cible à 45°
    glScaled(1.5,1.5,0);
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    gluTargetPrmtrs = gluNewQuadric();
    gluQuadricTexture(gluTargetPrmtrs, GL_TRUE);
    gluDisk(gluTargetPrmtrs,0,2,20,1);

    gluQuadricNormals(gluTargetPrmtrs, GLU_SMOOTH);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void Cible::init()
{
    loadTargetTexture();
}


void Cible::loadTargetTexture()
{
    QImage image;
    image.load(":/src/img/target2.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &targetTexture[0]);
    glBindTexture(GL_TEXTURE_2D, targetTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}
