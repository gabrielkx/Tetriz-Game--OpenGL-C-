#pragma once
#include "GL\glut.h"
#include <iostream>
#include "figura.h"
#include <list>
#include <ctime>
using namespace std;

class juego
{
public:
    juego();
    static void dibujar();
    static void processar_teclado(unsigned char p, int x, int y);
    static void atualizar();
    static void iniciar();
    static void dibujar_tablero();
    static void dibujar_quadrados();
    static void checar_colisao();
    static void checar_linhas();


private:
    static int w,h;
    static float fps;
    static float tempo_atualizar;
    static figura peca;
    static list<quadrado> quadrados;

};
