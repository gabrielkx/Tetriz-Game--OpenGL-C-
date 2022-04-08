#include "quadrado.h"
#include "GL\glut.h"

quadrado::quadrado()
{
   pos_y = 0;
   pos_x =0;
}

void quadrado::dibujar()
{
    glPushMatrix();

   switch(rotacao)

    {
    case 2:
    glRotatef(90,0,0,1);
    break ;


    case 3:
    glRotatef(180,0,0,1);
    break ;

    case 4:
    glRotatef(270,0,0,1);
    break ;

    }

    glTranslatef(pos_x, pos_y,0);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-15,-15);
    glVertex2f(15,-15);
    glVertex2f(-15,15);
    glVertex2f(15,15);

    glEnd();
    glPopMatrix();


}

void quadrado::atualizar()
{



}

void quadrado::set_rotacao(unsigned short num)
{
    rotacao = num;
}
