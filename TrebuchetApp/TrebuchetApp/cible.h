#ifndef CIBLE_H
#define CIBLE_H
#include <GL/glu.h>
#include <QImage>

class Cible
{
public:
    Cible();

    void draw(int xpos, int ypos);
    void init();

protected:
    GLUquadric *gluTargetPrmtrs;
    GLuint targetTexture[1];

    void loadTargetTexture();

protected:
    QTime* tempsCible_;
};

#endif // CIBLE_H
