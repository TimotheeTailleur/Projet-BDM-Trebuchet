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
    glBindTexture(GL_TEXTURE_2D, ballTexture[0]);
    glColor3ub(255,255,255);
        glPushMatrix();
        glTranslated(x_,y_,z_);

        glEnable(GL_TEXTURE_2D);

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

            projectilePrmtrs=gluNewQuadric();
            gluQuadricTexture(projectilePrmtrs,1);
            glScalef(.8,.8,.8);
            gluSphere(projectilePrmtrs,0.5,10,10);
            gluQuadricNormals(projectilePrmtrs, GLU_SMOOTH);

        glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void Projectile::init()
{
    loadBallTexture();
}

void Projectile::loadBallTexture()
{
    QImage image;
    image.load(":/src/img/rock.jpg");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &ballTexture[0]);
    glBindTexture(GL_TEXTURE_2D, ballTexture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
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
