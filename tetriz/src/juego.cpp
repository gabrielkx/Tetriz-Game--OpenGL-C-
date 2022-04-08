#include "juego.h"

 int juego::w = 800, juego::h=600;
 float juego::fps =60.f;
 float juego::tempo_atualizar = 1000.f;
 figura juego::peca(rand()%6+1);
 list<quadrado> juego::quadrados;

juego::juego(){

    srand(time(NULL));
    peca= figura(rand()%6+1);

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(w,h);
    glutCreateWindow("Tetris Extremo Super Mega ");
    glutDisplayFunc(dibujar);
    glutKeyboardFunc(processar_teclado);
    glutIdleFunc(atualizar);
    iniciar();
}

void juego::iniciar()
{   glClearColor(0.5,0,0.5,1);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(0,w,0,h,-1,1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

void juego::dibujar()
{   glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(400,300,0);
    dibujar_tablero();
    peca.dibujar();

    dibujar_quadrados();

    glPopMatrix();
    glutSwapBuffers();
}

void juego:: processar_teclado(unsigned char c, int x, int y)
{

    switch(c)
    {

    case 'A' : case 'a':

    peca.set_x(-30);

    break;

    case 'D': case 'd':

    peca.set_x(30);

    break;

    case 'S' : case 's' :
    tempo_atualizar = 50;
    break;

    case ' ':
    peca.rotar();

    break;

    }
}

void juego::atualizar()
{
  static float tiempo_transcurrido =0;
  static float atualizar_quadrado =0;
  if(glutGet(GLUT_ELAPSED_TIME) > tiempo_transcurrido + 1.f/fps)
  {
       if(glutGet(GLUT_ELAPSED_TIME) > atualizar_quadrado + tempo_atualizar)

       {
            checar_colisao();
            atualizar_quadrado = glutGet(GLUT_ELAPSED_TIME);
            if(peca.atualizar())
            {

                for(int i=0; i<4 ; i++)
                    {
                    quadrados.push_back(quadrado(peca.calcula_posicao_x(i),peca.calcula_posicao_y(i)));
                    }
                    checar_linhas();
                    peca = figura(rand()%6+1);

            }




       }


       tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
       tempo_atualizar=1000;
       glutPostRedisplay();

  }
}

void juego::dibujar_tablero()
{   glPushMatrix();
    glTranslatef(-150,300,0);
    glColor3f(0,0,0);
    glBegin(GL_QUAD_STRIP);

    glVertex2f(0,0);
    glVertex2f(300,0);
    glVertex2f(0,-600);
    glVertex2f(300,-600);

    glEnd();

    glPopMatrix();




}


void juego::dibujar_quadrados()
{
    glColor3f(1,1,1);
    list<quadrado>::iterator p = quadrados.begin();
    while(p!= quadrados.end())
    {
        p-> dibujar();
        p++;
    }
}

void juego::checar_colisao()
{

    bool gameover = false;
    list<quadrado>::iterator p = quadrados.begin();
    while(p!= quadrados.end())
    {
        bool cubo_colisao = false;
        for(int i =0 ; i<4; i++)
        {


            if(abs(p->get_y()- ((int)peca.calcula_posicao_y(i)-30))<15)
            {

                if(abs(p->get_x() - (int) peca.calcula_posicao_x(i))<5)
                {
                   cubo_colisao = true;
                }

            }


        }
        if(cubo_colisao)
        {

                    for(int i=0; i<4 ; i++)
                    {

                    quadrados.push_back(quadrado(peca.calcula_posicao_x(i),peca.calcula_posicao_y(i)));
                        if((int)peca.calcula_posicao_y(i)>300)
                        {
                            gameover = true;
                        }

                    }
                    checar_linhas();

                    peca = figura(rand()%6+1);

        }
        p++;
    }
        if(gameover)
        {
            exit(1);
        }
}

void juego::checar_linhas()
{

    for(int i=0;i<4 ; i++)
    {
        int contar_quadrados =0;
        list<quadrado>::iterator p = quadrados.begin();
        while(p!= quadrados.end())
        {
            if(abs((int)peca.calcula_posicao_y(i) - p->get_y()) <15)
            {
               contar_quadrados++;
            }
            p++;
        }

        if(contar_quadrados ==10)
        {
            p=quadrados.begin();
            while(p!= quadrados.end())
            {
                if(abs((int)peca.calcula_posicao_y(i) - p->get_y()) <15)
                {
                    p= quadrados.erase(p);
                }
                else{
                    if(p->get_y()> ((int)peca.calcula_posicao_y(i)) )
                    {
                        p-> set_y(-30);
                    }
                    p++;
                    }
            }

        }
    }

}
