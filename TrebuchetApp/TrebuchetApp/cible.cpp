#include "cible.h"

Cible::Cible()
{
    xpos_=10;
    ypos_=10;
}


void Cible::draw()
{

    glBindTexture(GL_TEXTURE_2D, targetTexture[0]);
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(xpos_,ypos_,2);
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
    image.load(":/src/img/target.bmp");
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

//Méthode qui va vérifier les collisions
/*
 * Le projectile n'a pas le même système de coordonnées que la cible.
 * On doit donc vérifier des conditions qui semblent porter sur des coordonnées
 * différentes mais qui correspondent aux mêmes directions dans la représentation OpenGL
 * ex : la coordonnée z de la cible correspond à -x du projectile
 * => si zCible=2 et -xProjectile=2 alors les deux objets sont à la même hauteur
 * dans la représentation OpenGL
 * */
int Cible::checkCollision(double xProjectile, double yProjectile)
{
    //Calcul de la distance entre point en entrée et  point centre de la cible
    double d = pow((xProjectile-xpos_),2)+pow((yProjectile-ypos_),2);

    //10 zones avec 10 scores différents sur la cible
    for (int i=10;i>0;i--)
    {
        /*
         * Chaque anneau de la cible a pour rayon 0.15
         * Quand i vaut 10, la distance au centre de la cible doit être comprise
         * entre 0 et 0.15.
         * Quand i vaut 9, entre 0.15 et 0.30, etc.
         * */
        if ( (1.5-(0.15*i)<d) && (d<1.5-(0.15*(i-1))) )
            return (i);
    }

    return -1;
}
