#include "projectile.h"

Projectile::Projectile()
{
    x_=0;
    y_=0;
    z_=4;
}


//Méthodes de dessin & initialisation
void Projectile::draw()
{
    glEnable(GL_COLOR_MATERIAL);
        glColor4f (1, 0.2, 0.2, 0);
        glPushMatrix();
            projectilePrmtrs=gluNewQuadric();
            gluQuadricDrawStyle(projectilePrmtrs, GLU_FILL);
            gluQuadricTexture(projectilePrmtrs,1);

            glTranslated(x_,y_,z_);
            glScalef(.8,.8,.8);
            gluSphere(projectilePrmtrs,0.5,10,10);
            gluDeleteQuadric(projectilePrmtrs);;
        glPopMatrix();
        glColor4f (1, 1, 1, 0);
    glDisable(GL_COLOR_MATERIAL);
    glFlush();
}

void Projectile::init()
{

}

//Méthode qui va mettre à jour la position en fonction du temps
int Projectile::updatePos()
{

}

//Getters & Setters

double Projectile::getX()
{
    return x_;
}

double Projectile::getY()
{
    return y_;
}

double Projectile::getZ()
{
    return z_;
}

void Projectile::setX(double x)
{
    x_=x;
}

void Projectile::setY(double y)
{
    y_=y;
}

void Projectile::setZ(double z)
{
    z_=z;
}
