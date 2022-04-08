#include "figura.h"
#include "quadrado.h"

figura::figura(unsigned short num)
{
  id = num;
  rotacao = 1;

  pos_x = 15;
  pos_y=345;


    switch(id)
    {

    case 1:

    quadrados[1].set_x(30);
    quadrados[2].set_x(-30);
    quadrados[3].set_x(-30);
    quadrados[3].set_y(30);
     break;

    case 2:

    quadrados[1].set_x(30);
    quadrados[2].set_x(-30);
    quadrados[3].set_x(30);
    quadrados[3].set_y(30);
     break;

     case 3:

    quadrados[1].set_x(30);
    quadrados[2].set_x(-30);
    quadrados[3].set_x(0);
    quadrados[3].set_y(30);
     break;


     case 4:

    quadrados[1].set_x(30);
    quadrados[2].set_x(30);
    quadrados[2].set_y(30);
    quadrados[3].set_x(0);
    quadrados[3].set_y(30);

     break;



    case 5:
    quadrados[1].set_x(30);
    quadrados[2].set_x(-30);
    quadrados[3].set_x(-60);
    break;

    case 6:
    quadrados[1].set_x(-30);
    quadrados[2].set_y(30);
    quadrados[3].set_x(30);
    quadrados[3].set_y(30);

    break;


    }


  }

bool figura::atualizar()
{
    bool colisao = false;

    for(int i =0; i<4; i++)
    {

        if((int)calcula_posicao_y(i)> -280)
        {

        }

        else
        {

            colisao = true;

        }


    }

    if(!colisao)
    {
        pos_y -=30;
    }

 return colisao;
}


void figura::dibujar() {

    //quadrado[0] mantem sua posição

    switch(id)
    {

    case 1:
    glColor3f(1,1,0);
    break;

    case 2:
    glColor3f(1,1,0);
    break;

    case 3:
    glColor3f(1,0,1);
    break;


    case 4:
    glColor3f(0,0,1);
    break;

    case 5:
    glColor3f(1,0,0);
    break;

    case 6:
    glColor3f(0,1,1);
    break;
    }

/*

*/
    glPushMatrix();
    glTranslatef(pos_x, pos_y,0);

    for(int i=0; i<4; i++)
    {
        quadrados[i].dibujar();
    }

    glPopMatrix();


}


void figura::set_x(double x)
{
    bool tem_colisao = false;
    if(x>0)
    {
        for( int i =0 ; i<4; i++)
        {

            if(abs((int)calcula_posicao_x(i)-130) <15)
            {
                tem_colisao = true;
            }

        }

    }
    else
        {
            for( int i =0 ; i<4; i++)
            {

                if(abs((int)calcula_posicao_x(i)+130) <15)
                {
                 tem_colisao = true;
                }
            }
        }

        if(!tem_colisao)
        {
        pos_x +=x;

        }
}




void  figura::set_y(double y)
{

    if(pos_y > -285)
    {

    pos_y +=y;

    }

}


void figura::rotar()

{
        rotacao++;
        if(rotacao>4) rotacao = 1 ;

        for(int i=0; i<4; i++)
        {

        quadrados[i].set_rotacao(rotacao);

        }
}

double figura::get_angulo_quadrado(unsigned short num)
{

    double angulo_quadrado = atan2f(quadrados[num].get_y(),quadrados[num].get_x());

    cout << radgra(angulo_quadrado)<< endl;


    double rotacao_local =  (rotacao-1) *90;

    return (angulo_quadrado) + radgra(rotacao_local);

}


double figura::calcula_posicao_x(unsigned short num)
{


    double  hipotenusa;

    hipotenusa = sqrt(pow((quadrados[num].get_x()),2) + pow((quadrados[num].get_y()),2));

    return cos(get_angulo_quadrado(num))* hipotenusa + pos_x;


}

double figura::calcula_posicao_y(unsigned short num)
{


    double  hipotenusa;

    hipotenusa = sqrt(pow((quadrados[num].get_x()),2) + pow((quadrados[num].get_y()),2));

    return sin(get_angulo_quadrado(num))* hipotenusa + pos_y;


}
