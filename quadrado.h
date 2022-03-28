#pragma once
#include "GL\glut.h"


class quadrado
{
    public:
        quadrado();
        quadrado(double x , double y ){pos_x = x , pos_y = y;}
        void dibujar();
        void set_x(double x ){pos_x += x;}
        void set_y (double y) {pos_y +=y;}
        void set_rotacao(unsigned short num);
        void atualizar();

        double get_x(){return pos_x;}
        double get_y(){return pos_y;}



    private:
    double pos_x;
    double pos_y;
    unsigned short rotacao;
};



