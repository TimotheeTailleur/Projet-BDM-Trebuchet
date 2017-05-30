#include "trebuchet.h"
#include <QDebug>

Trebuchet::Trebuchet()
{
    angleTrebuchet_=265;
    inclinaisonBras_=14;
}

void Trebuchet::draw()
{

    glPushMatrix();
        //translation par rapport au sol
        glTranslated(0,-14.5,0);

        glColor3ub(255,240,230);

        glRotatef(angleTrebuchet_,0,0,1.0);

        //pied gauche
        glPushMatrix();
            glTranslated(-3/2,-1.4/2,0);
            glCallList(footList);
        glPopMatrix();

        //pied droit
        glPushMatrix();
            glTranslated(-3/2,1.4/2,0);
            glCallList(footList);
        glPopMatrix();

        //bras de lancement
        glPushMatrix();
            glColor4ub(200,200,200,1);
            glTranslated(0,0,3*0.97);
            glRotated(inclinaisonBras_,0,1,0);
            glTranslated(-3*1.5/4.75,0,0);
            drawQuad(3*1.5,0.3*1.5);


            //Dessin du projectile
            ball.setX(4);
            ball.setY(0);
            ball.setZ(.5);
            ball.draw();


            //contrepoids
            glTranslated(0.2*0.75,0,0.2*0.75);
            glRotated(-inclinaisonBras_,0,1,0);
            glBegin(GL_LINES);

                glLineWidth(20);
                glVertex3d(0,0,0);
                glVertex3d(0,0,-0.8);

            glEnd();
            glTranslated(-0.25,0,-0.75);
            drawQuad(0.6,2*0.5);


        glPopMatrix();


        //base de rotation
        glPushMatrix();
            glColor3ub(50,50,50);
            glTranslated(0,1.4/2,3*0.97);
            glRotated(-90,0,0,1);
            drawQuad(1.4,2*0.1);
        glPopMatrix();
    glPopMatrix();
}

void Trebuchet::drawQuad(double length, double width)
{
    glBindTexture(GL_TEXTURE_2D, woodTexture[0]);
    glBegin(GL_QUADS);
        glNormal3d(-1,0,0);
        //face devant
        glTexCoord2d(0,width*2);            glVertex3d(0,width/2,width/2);
        glTexCoord2d(0,0);                      glVertex3d(0,width/2,-width/2);
        glTexCoord2d(width*2,0);            glVertex3d(0,-width/2,-width/2);
        glTexCoord2d(width*2,width*2);  glVertex3d(0,-width/2,width/2);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3d(1,0,0);
        //face derrière
        glTexCoord2d(0,width*2);            glVertex3d(length,width/2,width/2);
        glTexCoord2d(0,0);                      glVertex3d(length,width/2,-width/2);
        glTexCoord2d(width*2,0);            glVertex3d(length,-width/2,-width/2);
        glTexCoord2d(width*2,width*2);  glVertex3d(length,-width/2,width/2);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3d(0,1,0);
        //face droite
        glTexCoord2d(0,width*2);            glVertex3d(0,width/2,width/2);
        glTexCoord2d(0,0);                      glVertex3d(0,width/2,-width/2);
        glTexCoord2d(length,0);               glVertex3d(length,width/2,-width/2);
        glTexCoord2d(length,width*2);     glVertex3d(length,width/2,width/2);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3d(0,-1,0);
        //face gauche
        glTexCoord2d(0,width*2);            glVertex3d(0,-width/2,width/2);
        glTexCoord2d(0,0);                      glVertex3d(0,-width/2,-width/2);
        glTexCoord2d(length,0);               glVertex3d(length,-width/2,-width/2);
        glTexCoord2d(length,width*2);     glVertex3d(length,-width/2,width/2);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3d(0,0,-1);
        //face bas
        glTexCoord2d(0,width*2);            glVertex3d(0,width/2,-width/2);
        glTexCoord2d(0,0);                      glVertex3d(0,-width/2,-width/2);
        glTexCoord2d(length,0);               glVertex3d(length,-width/2,-width/2);
        glTexCoord2d(length,width*2);     glVertex3d(length,width/2,-width/2);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3d(0,0,1);
        //face haut
        glTexCoord2d(0,width*2);            glVertex3d(0,width/2,width/2);
        glTexCoord2d(0,0);                      glVertex3d(0,-width/2,width/2);
        glTexCoord2d(length,0);               glVertex3d(length,-width/2,width/2);
        glTexCoord2d(length,width*2);     glVertex3d(length,width/2,width/2);
    glEnd();
}

void Trebuchet::createFootDisplayList()
{
    footList=glGenLists(1);
    glNewList(footList,GL_COMPILE);
        glPushMatrix();
            drawQuad(3,0.2*0.94);
        glPopMatrix();

        glPushMatrix();
            glTranslated(3*0.31,0,0);
            glRotated(-80,0,1,0);
            drawQuad(3,0.2*0.96);
            glTranslated(3,0,0);
            glRotated(160,0,1,0);
            drawQuad(3,0.2*0.92);
        glPopMatrix();
    glEndList();
}

void Trebuchet::init()
{
    loadLogoTexture();
    loadWoodTexture();
    createFootDisplayList();
}

/*Getters & Setters*/

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
    if (angle<230)
    {
        angleTrebuchet_=230;
    }else if (angle>295)
    {
        angleTrebuchet_=295;
    }else
    {
        angleTrebuchet_=angle;

    }
}

void Trebuchet::setInclinaisonTrebuchet(double inclinaison)
{
    if (inclinaison > 36){
        inclinaisonBras_ = 36;
    }
    else if(inclinaison < 0){
        inclinaisonBras_ = 0;
    }
    else{
        inclinaisonBras_=inclinaison;
    }
}

/* Méthodes de chargement des textures */

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
