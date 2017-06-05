#ifndef CIBLE_H
#define CIBLE_H
#include <glu.h>
#include <math.h>
#include <QImage>


/*
 * Classe représentant une cible du jeu. Gère le caractère aléatoire du placement
 * en fonction d'un niveau de difficulté compris entre 1 et 3 passé en paramètre du constructeur
 * */
class Cible
{
public:
    Cible(int difficultyLevel); //Constructeur prenant en paramètre le niveau de difficulté du jeu

    //Méthodes de dessin et d'initialisation
    void draw();
    void init();


protected:
    //Paramètres pour le GLUquadricTexture dessinant la cible
    GLUquadric *gluTargetPrmtrs;

    //GLuint stockant la texture de la cible
    GLuint targetTexture[1];

    //Méthode de chargement de la texture de la cible
    void loadTargetTexture();

    /*Méthode permettant de vérifier si il y a collision entre un projectile
     * dont le centre est situé en (x,y,z).
     * Renvoie un entier compris entre 1 et 10 si la cible est touchée.
     * -1 si non collision
     * */
    int checkCollision(double xProjectile, double yProjectile, double zProjectile); //Méthode qui va vérifier les collisions

protected:
    double xpos_; //Position en x de la cible
    double ypos_;   // Position en y de la cible
};

#endif // CIBLE_H
