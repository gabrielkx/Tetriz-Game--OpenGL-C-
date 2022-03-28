#pragma once
#include "quadrado.h"
#include <cmath>
#include <iostream>

using namespace std;

class figura
{
    public:

figura(unsigned short num); // 1 ele, 2 ele invertida, 3 cubo , 4 triango, 5 o T
bool atualizar();
void dibujar();
void set_x(double);
void set_y(double);
double get_x(unsigned short num) { return quadrados[num].get_x() + pos_x;}
double get_y(unsigned short num ) {return quadrados[num].get_y()+ pos_y;}
void rotar();
double get_angulo_quadrado(unsigned short int);
double calcula_posicao_x( unsigned short num);
double calcula_posicao_y(unsigned short num);
float radgra(float graus){return graus*3.14/180; }
private:



 quadrado quadrados[4];
 unsigned short id;
 unsigned short rotacao;
 double pos_x;
 double pos_y;
};

