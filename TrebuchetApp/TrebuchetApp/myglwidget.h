#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QThread>
#include <QTimer>

/*Dépendances Windows*/
#include <QtOpenGL>
#include <GL/glu.h>

/*Dépendances Mac
#include <OpenGL.h>
#include <glu.h> */

#include "trebuchet.h"
#include "cible.h"
#include "terrain.h"


/*
 * Classe gérant l'affichage de la scène openGL
 * Affichage du terrain, trébuchet, cible
 */

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);

    //Vaut true si le tracking de la webcam a été lancé et le jeu commencé.
    bool gameStarted=false;
public:
    void launch(int force); //Lancement du projectile
    void loadLogoTexture(); //Charge la texture du logo TSE
    void setCible(Cible* cible);
protected:
    //Méthodes de dessin
    //Initialise l'éclairage, les ombres et appelle les méthodes d'initialisation du terrain et du trébuchet
    void initializeGL();

    /*Méthode qui sera appelée lors de la mise à jour de la scène
     * Initialise le système de coordonnées
     * appelle draw() */
    void paintGL();

    void resizeGL(int width, int height);

    /*
     * Dessin du terrain, trébuchet et de la cible si le jeu
     * est commencé.
     * Dessin de trois logos TSE */
    void draw();

    //Dessin du logo TSE aux coordonnées (x,y,z) avec rotation autours de x,y,z en fonction des angles passés en paramètres
    void drawLogo(int x, int y, int z, double angleX, double angleY, double angleZ);

public slots:
    // Slot pour MàJ attributs trébuchet après récupération des coordonnées par la webcam
    void getCoords(int x, int y);
private:

    //Elements du modèle
    Terrain terrain_;
    Trebuchet trebuchet_;
    //On fait une simple référence à la cible courante gérée par l'objet Jeu
    Cible * cible_;
    int xPreviousHandPos;
    int yPreviousHandPos;
    GLuint logoTexture[1]; //Texture logo TSE
};

#endif // MYGLWIDGET_H

