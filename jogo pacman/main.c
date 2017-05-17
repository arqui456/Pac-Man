#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "contadores/count.h"
#include "teclado/teclado.h"
#include "objetos/personagens.h"
#include "include/score.h"
#include "fantasma.h"

#define MAXlINHAS  21
#define MAXCOLUNAS 31
#define DEBUG if(0)

SAMPLE* morte;
SAMPLE* come;
SAMPLE* intro;
SAMPLE* siren;
SAMPLE* birl;
SAMPLE* waza;
SAMPLE* eatGhost;

BITMAP* buffer;
BITMAP* parede;
BITMAP* pastilha;
BITMAP* morreu;
BITMAP* pacbmp;
BITMAP* pacman;
BITMAP* fanbmp;
BITMAP* fantasma;
BITMAP* morreuFan;
BITMAP* correFan;
BITMAP* pastilhaMutante0;
BITMAP* pastilhaMutante1;

char nomes[100][4];
int index;
int nome;
int contou;

int lista[10];

int anteriorpx;
int anteriorpy;

int pastilhasRestantes;
int flag;
int aux33;


int introFlag;
int SCORE;
int VIDAS;
int stopTime;

int contando;

int aux22;
int stopTimee;
int contouu;
int contandoo;

enum
{
     TITLESCREEN,
     GAMESCREEN,
     MAINMENU,
     HIGHSCORE,
     HIGHSCORE1
};

int screen_state;

enum{

    PAREDE   = 0,
    COMIDA   = 1,
    AUX      = 2
};

int Mapa_state;

char** mapa;
/*
char mapa[MAXlINHAS][MAXCOLUNAS] = {
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
     "X****|***XXXXXXXXXXX***|****X",
     "X*XXX*XX*XXXXXXXXXXX*XX*XXX*X",
     "X*********XXXXXXXXX*********X",
     "X*XXX*XXX**XXXXXXX**XXX*XXX*X",
     "X**|**XXXX**XXXXX**XXXX**|**X",
     "X*X*X********XXX********X*X*X",
     "X*X*X*X*X*X*XXXXX*X*X*X*X*X*X",
     "X************XXX************X",
     "XXXXX****XXXXXXXXXXX****XXXXX",
     "XXXXX*XX*XXXXXXXXXXX*XX*XXXXX",
     "X**|**XX*************XX*****X",
     "X*X*X*X*X*X*XXXXX*X*X*X*X*X*X",
     "X*X*X********XXX********X*X*X",
     "X*****XXXX**XXXXX**XXXX*****X",
     "X*XXX*XXX**XXXXXXX**XXX*XXX*X",
     "X*********XXXXXXXXX*********X",
     "X*XXX*XX*XXXXXXXXXXX*XX*XXX*X",
     "X********XXXXXXXXXXX********X",
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
*/








void setupGUI (char* , int , int);
void abilitaBotaoFechar();
void fecharJogo();
volatile int sairDoPrograma = FALSE;
int textout_hack( BITMAP *bmp , FONT font , int x , int y , double multiplier , char *msg , int color );

int busca(int* a, int k,int n,int x);
void desenhaFantasma();
void desenharPersonagem();
void MoverFantasma(); //int**,int,int
void fantasmaPegou(); //int**, int,int
void carregaArquivos();
void destruirArquivos();
void desenharMapa();
void preencheMapa();
void RecontrutorMapa();
//int** carregaMapa(const char* ,int* ,int*);
//void DesenharMapa(BITMAP* ,int** , int ,int );
//void freeMapa(int** ,int );

void init();
void gamescreen();
void titlescreen();
void mainmenu();
void highscore();
void highscore1();


int main()
{
     nomes[100][4];
     index = 0;
     nome = 0;
     contou;

     lista[10];

     anteriorpx;
     anteriorpy;

     pastilhasRestantes;
     flag = 0;
     aux33 = 0;

     introFlag;
     SCORE = 0;
     VIDAS = 3;


     Mapa_state = 0;

    init();

    while(!sairDoPrograma)
    {
        if(screen_state == MAINMENU)
        {
            SCORE = 0;
            mainmenu();
        }
        else if(screen_state == TITLESCREEN)
        {
            titlescreen();
        }
        else if(screen_state == GAMESCREEN)
        {
            gamescreen();
        }
        else if(screen_state == HIGHSCORE)
        {
            highscore();
        }
        else if(screen_state == HIGHSCORE1)
        {
            highscore1();
        }
    }
    return 0;
}
END_OF_MAIN();

void gamescreen()
{
     set_default_Pos(Mapa_state,0,4);
     set_default_Pos_p(Mapa_state);
     introFlag  = 0;
     VIDAS = 3;
     int aux;


    int SairDaTela = FALSE;
    carregaArquivos();
    CriaFantasma();
    perseguir();
    CriaPacman();
    clear(pac.pacman);
    while(!sairDoPrograma && !SairDaTela )
    {
        while(ticks > 0 && !SairDaTela && !sairDoPrograma)
        {
            if(flag)
            {
                stop_sample(siren);
                stop_sample(waza);
                SairDaTela = TRUE;
                Mapa_state = rand()% 3;
                RecontrutorMapa();
                flag = 0;
                screen_state = GAMESCREEN;
            }
            keyboard_input();
            if(key[KEY_ESC])
            {
                fecharJogo();
            }
            if(!VIDAS)
            {
                stop_sample(siren);
                stop_sample(waza);
                SairDaTela   = TRUE;
                screen_state = HIGHSCORE;
            }

            anteriorpx = pac.px;
            anteriorpy = pac.py;
            if(pac.px % 15 == 0 && pac.py % 15 == 0)
            {
                if(key[KEY_RIGHT])
                {
                pac.direcao = 1;
                }
                else if(key[KEY_LEFT])
                {
                pac.direcao = 0;
                }
                else if(key[KEY_UP])
                {
                pac.direcao = 2;
                }
                else if(key[KEY_DOWN])
                {
                pac.direcao = 3;
                }
            }

            if(pac.direcao == 0)
            {

                if(mapa[pac.py/30][(pac.px - 30)/30] != 'X')
                {
                    pac.px = ((((pac.px - 30)% 870) + 870) % 870);
                }
                else
                {
                    pac.direcao = 4;
                }
            }
            else if(pac.direcao == 1)
            {
                if(mapa[pac.py/30][(pac.px + 30)/30] != 'X')
                {
                    pac.px = ((((pac.px + 30)% 870) + 870) % 870);
                }
                else
                {
                    pac.direcao = 4;
                }
            }
            else if(pac.direcao == 2)
            {
                if(mapa[(pac.py - 30)/30][pac.px/30] != 'X')
                {
                    pac.py = ((((pac.py - 30)% 600) + 600) % 600);
                }
                else
                {
                    pac.direcao = 4;
                }
            }
            else if(pac.direcao == 3)
            {
                if(mapa[(pac.py + 30)/30][pac.px/30] != 'X')
                {
                    pac.py = ((((pac.py + 30)% 600) + 600) % 600);
                }
                else
                {
                    pac.direcao = 4;
                }
            }

            clear(buffer);
            desenharMapa();
           // RecontrutorMapa();
            //DesenharMapa(buffer, mapa,linhas,colunas);
            desenharPersonagem();
            MoverFantasma(); //mapa,linhas,colunas
            draw_sprite(screen,buffer,0,0);
            rest(50);

            clear(pac.pacman);
            aux = pac.direcao;
            pac.direcao = 4;
            desenharPersonagem();
            pac.direcao = aux;
            draw_sprite(screen,buffer,0,0);
            if(!introFlag)
              {
                play_sample(intro,300,128,1000,0);
                rest(4000);
                introFlag = 1;
                play_sample(siren,300,128,1000,1);
              }
            rest(40);


            ticks--;
        }
    }

    destruirArquivos();
}

void highscore()
{
    char edittext[128];
    int caret = 0;
    int sairDaTela = FALSE;
    buffer = create_bitmap(SCREEN_W,SCREEN_H);

    while(!sairDoPrograma && !sairDaTela)
    {
        while(ticks > 0 && !sairDoPrograma && !sairDaTela)
        {
            keyboard_input();
            if(key[KEY_ENTER] && apertou(KEY_ENTER))
            {
                sairDaTela   = TRUE;
                screen_state = MAINMENU;
            }
            if(key[KEY_ESC])
            {
                fecharJogo();
            }
                if(keypressed())
                {
                    int newkey    = readkey();
                    char ASCII    = newkey & 0xff;
                    char scancode = newkey >> 8;

                    if(ASCII >= 32 && ASCII <= 126)
                    {
                        if(caret < 128 - 1)
                        {
                            edittext[caret] = ASCII;
                            caret++;
                            edittext[caret] = '\0';
                        }
                    }
                    else if(scancode == KEY_BACKSPACE)
                    {
                        if(caret > 0) caret --;
                        edittext[caret] = '\0';
                    }
                }

                clear(buffer);
                textout_centre_ex(buffer,font,"Insira Seu Nome!",SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1);
                textout_centre(buffer,font,edittext,SCREEN_W/2,SCREEN_H/2 + 50,makecol(255,255,255));
                vline(buffer,caret * 8,8,18,makecol(255,255,255));
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                strcpy(score_table[(player)%10].player_name, edittext);
                score_table[(player)%10].player_score = SCORE;






          //  draw_sprite(screen,buffer,0,0);


           // textprintf_centre_ex(buffer, font, SCREEN_W/2 + 50,SCREEN_H/2 + 50,makecol(255,255,255),"%c",nomes[index][nome]);

            clear(buffer);

            ticks--;
        }
    }
    player++;
    destroy_bitmap(buffer);
}

void highscore1()
{
    int flagB = FALSE;
    char edittext[128];
    int caret;
    int buscar;
    int i,j;
    int sairDaTela = FALSE;
    buffer = create_bitmap(SCREEN_W,SCREEN_H);

    while(!sairDoPrograma && !sairDaTela)
    {
        while(ticks > 0 && !sairDoPrograma && !sairDaTela)
        {
            keyboard_input();
            if(key[KEY_ENTER] && apertou(KEY_ENTER) && !flagB)
            {
                sairDaTela   = TRUE;
                screen_state = MAINMENU;
            }
            if(key[KEY_ESC])
            {
                fecharJogo();
            }
                sort_scores();

                for(i = 0;i < 10;i++)
                {
                    lista[i] = score_table[i].player_score;
                }

                clear(buffer);
                textout_centre_ex(buffer,font,"HIGHSCORES",SCREEN_W/2,SCREEN_H/2 - 100,makecol(255,255,255),-1);
                for(i = 0,j = -90;i < 10;i++,j+=10)
                {
                    textprintf_centre_ex(buffer,font,SCREEN_W/2,SCREEN_H/2 + j,makecol(0,0,255),-1,"%s %d",score_table[i].player_name,score_table[i].player_score);
                }

                textprintf_centre_ex(buffer,font,SCREEN_W/2, SCREEN_H/2 + 110, makecol(0,0,255), -1,"O maior pontuador eh: %s",score_table[busca(lista,0,10, score_table[0].player_score)].player_name);

                //vline(buffer,caret * 8,8,18,makecol(255,255,255));
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            clear(buffer);

            ticks--;
        }
    }
    destroy_bitmap(buffer);
}

void titlescreen()
{
    BITMAP* introPac = load_bitmap("intro/logo.bmp", NULL);
    int sairDaTela = FALSE;
    buffer = create_bitmap(SCREEN_W,SCREEN_H);

    while(!sairDoPrograma && !sairDaTela)
    {
        while(ticks > 0 && !sairDoPrograma && !sairDaTela)
        {
            keyboard_input();
            if(key[KEY_ENTER] && apertou(KEY_ENTER))
            {
                sairDaTela   = TRUE;
                screen_state = MAINMENU;
            }
            if(key[KEY_ESC])
            {
                fecharJogo();
            }
            draw_sprite(buffer,introPac,SCREEN_W/2 - 230,SCREEN_H/2 - 200);
            textout_centre_ex(buffer,font,"PRESSIONE ENTER!",SCREEN_W/2,SCREEN_H/2 + 50,makecol(255,255,255),-1);
            textout_centre_ex(buffer,font,"PACMAN", SCREEN_W/2, SCREEN_H/2, makecol(255,255,255), -1);
            draw_sprite(screen, buffer,0,0);
            clear_to_color(buffer, makecol(0,0,0));

            ticks--;
        }
    }
    destroy_bitmap(buffer);
    destroy_bitmap(introPac);
}

void mainmenu()
{
    int sairDaTela = FALSE;
    int iniciarJogo = TRUE;
    int Config = FALSE;
    int flagH = 0;
    int flagS = 1;

    buffer = create_bitmap(SCREEN_W,SCREEN_H);


    while(!sairDoPrograma && !sairDaTela)
    {
        while(ticks > 0 && !sairDaTela && !sairDoPrograma)
        {
            if(key[KEY_ESC])
            {
                fecharJogo();
            }
            keyboard_input();
            if(key[KEY_ENTER] && apertou(KEY_ENTER) && flagS)
            {
                RecontrutorMapa();
                sairDaTela   = TRUE;
                rest(10);
                screen_state = GAMESCREEN;
            }
            if(key[KEY_ENTER] && apertou(KEY_ENTER) && flagH)
            {
                sairDaTela   = TRUE;
                rest(10);
                screen_state = HIGHSCORE1;
            }

            textout_centre_ex(buffer, font, "MenuPrincipal", SCREEN_W/2, SCREEN_H/2, makecol(255,255,255),-1);
            textout_centre_ex(buffer, font, "Start Game", SCREEN_W/2, SCREEN_H/2 + 50, makecol(255,0,0),-1);
            textout_centre_ex(buffer, font, "HighScores", SCREEN_W/2, SCREEN_H/2 + 100, makecol(0,0,255),-1);
            keyboard_input();
            if(key[KEY_DOWN] || flagH)
            {
                textout_centre_ex(buffer, font, "Start Game", SCREEN_W/2, SCREEN_H/2 + 50, makecol(0,0,255),-1);
                textout_centre_ex(buffer, font, "HighScores", SCREEN_W/2, SCREEN_H/2 + 100, makecol(255,0,0),-1);
                flagH = 1;
                flagS = 0;
            }
            if(key[KEY_UP] && flagH)
            {
                flagH = 0;
                flagS = 1;
            }

            draw_sprite(screen,buffer,0,0);
            clear_to_color(buffer, makecol(0,0,0));

            ticks--;
        }
    }

    destroy_bitmap(buffer);
}

void preencheMapa()
{
    int i,j;
    for(i = 0;i < MAXlINHAS;i++)
    {
        for(j = 0;j < MAXlINHAS;j++)
        {
            if(mapa[i][j] != 'X')
            {
                mapa[i][j] = '*';
            }
        }
    }
}

void RecontrutorMapa()
{
    int i,j;
    mapa = malloc(MAXlINHAS*sizeof(mapa));
    for(i = 0;i < MAXlINHAS;i++)
    {
        mapa[i] = malloc(MAXCOLUNAS*sizeof(mapa[i]));
    }

     char mapaAux[MAXlINHAS][MAXCOLUNAS] =
     {
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
     "XO***|***XXXXXXXXXXX***|***OX",
     "X*XXX*XX*XXXXXXXXXXX*XX*XXX*X",
     "X*********XXXXXXXXX*********X",
     "X*XXX*XXX**XXXXXXX**XXX*XXX*X",
     "X**|**XXXX**XXXXX**XXXX**|**X",
     "X*X*X********XXX********X*X*X",
     "X*X*X*X*X*X*XXXXX*X*X*X*X*X*X",
     "X**|*********XXX*******|****X",
     "XXXXX*******************XXXXX",
     "XXXXX*XX*XXXXXXXXXXX*XX*XXXXX",
     "X**|**XX*************XX*****X",
     "X*X*X*X*X*X*XXXXX*X*X*X*X*X*X",
     "X*X*X********XXX********X*X*X",
     "X*****XXXX**XXXXX**XXXX*****X",
     "X*XXX*XXX**XXXXXXX**XXX*XXX*X",
     "X*********XXXXXXXXX*********X",
     "X*XXX*XX*XXXXXXXXXXX*XX*XXX*X",
     "XO***|***XXXXXXXXXXX***|***OX",
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };

    char mapaClassic[MAXlINHAS][MAXCOLUNAS] =
    {
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"XO****|*****|XX|*****|****OXX",
	"X*XXXX*XXXXX*XX*XXXXX*XXXX*XX",
	"X*****|**|********|**|*****XX",
	"X*XXXX*XX*XXXXXXXX*XX*XXXX*XX",
	"X******XX***|XX|***XX******XX",
	"XXXXXX*XXXXX*XX*XXXXX*XXXXXXX",
	"XXXXXX*XX***|**|***XX*XXXXXXX",
	"XXXXXX*XX*XXX  XXX*XX*XXXXXXX",
	"******|***X  ||  X***|*******",
	"XXXXXX*XX*XXXXXXXX*XX*XXXXXXX",
	"XXXXXX*XX|********|XX*XXXXXXX",
	"XXXXXX*XX*XXXXXXXX*XX*XXXXXXX",
	"X*****|******XX******|*****XX",
	"X*XXXX*XXXXX*XX*XXXXX*XXXX*XX",
	"X***XX******|**|******XX***XX",
	"XXX*XX*XX*XXXXXXXX*XX*XX*XXXX",
	"X**|***XX****XX****XX***|**XX",
	"X*XXXXXXXXXX*XX*XXXXXXXXXX*XX",
	"XO**********|**|**********OXX",
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };

    char mapa2[MAXlINHAS][MAXCOLUNAS] =
     {
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
     "XO***|****  XXXXX *****|***OX",
     "X*XXX*XXXXX XXXXX XXXXX*XXX*X",
     "X*XXX*XXXXX XXXXX XXXXX*XXX*X",
     "X*******|**       **|*******X",
     "X*XXX*XX XXXXXXXXXXX XX XXX X",
     "X****|XX*****XXX*****XX*****X",
     "X*XXX*XXXXXX*XXX*XXXXXX*XXX*X",
     "X*XXX*XX *  |   |  * XX*XXX*X",
     "*****|XX XXXXXXXXXXX XX|*****",
     "X*XXX*XX XXXXXXXXXXX XX*XXX*X",
     "X*XXX*XX *  |   |  * XX*XXX*X",
     "X*XXX*XXXXXX XXX XXXXXX*XXX*X",
     "X*****XX*****XXX*****XX*****X",
     "X*XXX*XX*XXXXXXXXXXX*XX*XXX*X",
     "X*XXX|  |           |  |XXX*X",
     "X*XXX*XXXX*XXXXXXXX*XXX*XXX*X",
     "X*XXX*XXXX**********XXX*XXX*X",
     "XO***|*****XXXXXXXX****|***OX",
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };

    if(Mapa_state == 1)
    {
            for(i = 0;i < MAXlINHAS;i++)
            {
                for(j = 0;j < MAXCOLUNAS;j++)
                {
                    mapa[i][j] = mapaAux[i][j];
                }
            }
    }
    else if(Mapa_state == 2)
    {
            for(i = 0;i < MAXlINHAS;i++)
            {
                for(j = 0;j < MAXCOLUNAS;j++)
                {
                    mapa[i][j] = mapaClassic[i][j];
                }
            }
    }
    else if(Mapa_state == 0)
    {
            for(i = 0;i < MAXlINHAS;i++)
            {
                for(j = 0;j < MAXCOLUNAS;j++)
                {
                    mapa[i][j] = mapa2[i][j];
                }
            }
    }


}



void setupGUI (char* title, int width, int heigh)
{
	allegro_init();
	install_timer();
	install_keyboard();
	install_mouse();
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,width,heigh,0,0);
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT, NULL);
	set_window_title(title);

	screen_state = TITLESCREEN;
}
END_OF_FUNCTION(setupGUI)

void abilitaBotaoFechar()
{
    LOCK_VARIABLE(sairDoPrograma);
    LOCK_FUNCTION(fecharJogo);
    set_close_button_callback(fecharJogo);
}
END_OF_FUNCTION(abilitaBotaoFechar);

void fecharJogo()
{
    sairDoPrograma = TRUE;
}
END_OF_FUNCTION(fecharJogo)

void desenharMapa()
{
    int i,j;
    pastilhasRestantes = 0;

    for(i = 0;i < MAXlINHAS;i++)
    {
        for(j = 0;j < MAXCOLUNAS;j++)
        {
            if(mapa[i][j] == 'X')
            {
                draw_sprite(buffer, parede, j*30, i*30);
            }
            else if(mapa[i][j] == '*')
            {
                draw_sprite(buffer, pastilha, j*30, i*30);
                pastilhasRestantes++;
                if(pac.py/30 == i && pac.px/30 == j)
                {
                    mapa[i][j] = ' ';
                    play_sample(come, 300, 128, 1000, FALSE);
                    pastilhasRestantes--;
                    SCORE+=10;
                }


            }
            else if(mapa[i][j] == 'O')
            {
                if(ticks % 2 == 0)
                draw_sprite(buffer,pastilhaMutante0,j*30,i*30);
                else
                draw_sprite(buffer,pastilhaMutante1,j*30,i*30);

                if(pac.py/30 == i && pac.px/30 == j)
                {
                    aux33 = 1;
                    mapa[i][j] = ' ';
                    play_sample(birl, 300, 128, 1000, FALSE);
                    SCORE+=100;
                    if(!contando)
                    {
                            comivel(1);
                            stop_sample(siren);
                            fugir(waza);
                    }
                    contou = 1;

                }

            }
            if(!introFlag)
            {
                textout_centre_ex(buffer,font,"GET READY!",SCREEN_W/2 - 100,SCREEN_H/2,makecol(255,255,0),-1);
            }
        }
    }


        if(aux33)
        {
            stopTime = milisegundos;
            aux33 = 0;
            contando = 1;
        }
        if((milisegundos >= stopTime + 10000) && (contou))
        {
            stop_sample(waza);
            play_sample(siren,300,128,1000,TRUE);
            perseguir();
            contou = 0;
            contando = 0;
        }


        //tempo(milisegundos,&aux33,waza,siren,&contou);
       //printf("depois da funcao tempo: %d\n",aux33);



    textprintf_right_ex(buffer,font,SCREEN_W - 10,10,makecol(255,255,0),-1,"SCORE: %d",SCORE);
    textprintf_right_ex(buffer,font,SCREEN_W - 10,30,makecol(255,255,0),-1,"VIDAS: %d",VIDAS);
    if(!pastilhasRestantes)
    {
        flag = 1;
    }

}
END_OF_FUNCTION(desenharMapa)


void desenhaFantasma()
{
    int i;
    /*
    blit(fanbmp, fantasma, fan[0].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    blit(fanbmp, fantasma, fan[1].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    blit(fanbmp, fantasma, fan[2].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    blit(fanbmp, fantasma, fan[3].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    */
    for(i = 0;i < 4;i++)
    {
        blit(fan[i].img, fan[i].fantasma, fan[i].direcaoFantasma * 30, 0, 0, 0, 30, 30);
        draw_sprite(buffer, fan[i].fantasma,fan[i].fx,fan[i].fy);
    }
    /*
    blit(fan[1].img, fan[1].fantasma, fan[1].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    blit(fan[2].img, fan[2].fantasma, fan[2].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    blit(fan[3].img, fan[3].fantasma, fan[3].direcaoFantasma * 30, 0, 0, 0, 30, 30);
    draw_sprite(buffer, fan[0].fantasma,fan[0].fx,fan[0].fy);
    draw_sprite(buffer, fan[1].fantasma,fan[1].fx,fan[1].fy);
    draw_sprite(buffer, fan[2].fantasma,fan[2].fx,fan[2].fy);
    draw_sprite(buffer, fan[3].fantasma,fan[3].fx,fan[3].fy);
    */
}
END_OF_FUNCTION(desenhaFantasma)

void desenharPersonagem()
{
    blit(pac.img, pac.pacman, pac.direcao * 33, 0, 0, 0, 33, 33);
    draw_sprite(buffer, pac.pacman,pac.px,pac.py);
}
END_OF_FUNCTION(desenharPersonagem)

void MoverFantasma() //int** mapa,int linhas,int colunas
{
    int i;
    desenhaFantasma();
    fantasmaPegou(); // mapa,linhas,colunas
    for(i = 0;i < 4;i++)
    {
        if(mapa[ fan[i].fy/30][ fan[i].fx/30] == '|')
        {
            fan[i].direcaoFantasma = rand()%4;
        }
        if( fan[i].direcaoFantasma == 0)
        {
            if(mapa[ fan[i].fy/30][( fan[i].fx - 30)/30] != 'X')
            {
                fan[i].fx -= 30;
            }
            else
            {
                fan[i].direcaoFantasma = rand()%4;
            }
        }
        if( fan[i].direcaoFantasma == 1)
        {
            if(mapa[ fan[i].fy/30][( fan[i].fx + 30)/30] != 'X')
            {
                fan[i].fx += 30;
            }
            else
            {
                fan[i].direcaoFantasma = rand()%4;
            }
        }
        if( fan[i].direcaoFantasma == 2)
        {
            if(mapa[( fan[i].fy - 30)/30][ fan[i].fx/30] != 'X')
            {
                fan[i].fy -= 30;
            }
            else
            {
                fan[i].direcaoFantasma = rand()%4;
            }
        }
        if( fan[i].direcaoFantasma == 3)
        {
            if(mapa[( fan[i].fy + 30)/30][ fan[i].fx/30] != 'X')
            {
                fan[i].fy += 30;
            }
            else
            {
                fan[i].direcaoFantasma = rand()%4;
            }
        }
    if(fan[i].fx <= -30 )
    {
         fan[i].fx = 870;
    }
    else if( fan[i].fx >= 870)
    {
         fan[i].fx = -30;
    }
    }

}
END_OF_FUNCTION(MoverFantasma)


void fantasmaPegou() //int** mapa,int linhas,int colunas
{
    int i,j;
    for(i = 0;i < 4;i++){
    if(((pac.py == fan[i].fy && pac.px == fan[i].fx) || (fan[i].fy == anteriorpy && fan[i].fx == anteriorpx)))
    {
            if(fan[i].comivel)
            {
                play_sample(eatGhost,300,128,1000,FALSE);
                foiComido(Mapa_state,i);
            }
            else
            {
                play_sample(morte, 255, 128, 1000, FALSE);
                VIDAS--;
                for(j = 0;j <= 5; j++)
                {
                    clear(pac.pacman);
                    clear(buffer);
                    desenharMapa();
                    // DesenharMapa(buffer,mapa,linhas,colunas);
                    blit(morreu,pac.pacman, j * 33, 0,0,0,33,33);
                    draw_sprite(buffer,pac.pacman,pac.px,pac.py);
                    draw_sprite(screen, buffer,0,0);
                    rest(100);
                }
                set_default_Pos_p(Mapa_state);
                break;
            }

            /*
            if(Mapa_state == 0)
            {
                pac.px      = 30 * 15;
                pac.py      = 30 * 15;
                pac.direcao = 4;
                break;
            }
            else if(Mapa_state == 1)
            {
                pac.px      = 30 * 14;
                pac.py      = 30 * 11;
                pac.direcao = 4;
                break;
            }
            else if(Mapa_state == 2)
            {
                pac.px      = 30 * 15;
                pac.py      = 30 * 15;
                pac.direcao = 4;
                break;
            }
            */

    }
    }
}
END_OF_FUNCTION(fantasmaPegou)

void carregaArquivos()
 {
    come             = load_sample("sons/eating.wav");
    morte            = load_sample("sons/death.wav");
    intro            = load_sample("sons/beginning.wav");
    siren            = load_sample("sons/siren.wav");
    birl             = load_sample("sons/birl.wav");
    waza             = load_sample("sons/waza.wav");
    eatGhost         = load_sample("sons/eatghost.wav");

    buffer           = create_bitmap(SCREEN_W,SCREEN_H);
    parede           = load_bitmap("sprites/parede3.bmp",NULL);
    pastilha         = load_bitmap("sprites/pastilha.bmp", NULL);
    morreu           = load_bitmap("sprites/morreu.bmp", NULL);
    morreuFan        = load_bitmap("sprites/fanMorreu.bmp", NULL);
    correFan         = load_bitmap("sprites/correFan.bmp", NULL);
    pastilhaMutante0 = load_bitmap("sprites/pastilhaMutante0.bmp",NULL);
    pastilhaMutante1 = load_bitmap("sprites/pastilhaMutante1.bmp",NULL);
 }
 END_OF_FUNCTION(carregaArquivos)


 void destruirArquivos()
 {
    destroy_bitmap(buffer);
    destroy_bitmap(parede);
    destroy_bitmap(pastilha);
    destroy_bitmap(morreu);
    destroy_bitmap(morreuFan);
    destroy_bitmap(correFan);
    destroy_sample(morte);
    destroy_sample(come);
    destroy_sample(birl);
    destroy_bitmap(pastilhaMutante0);
    destroy_bitmap(pastilhaMutante1);
    destroy_sample(waza);
    destroy_sample(eatGhost);
    Destroy_fan();
 }
 END_OF_FUNCTION(destruirArquivos)

 void init()
{
    setupGUI("PAC-MAN",1080,600);
    //setupGUI("PAC-MAN",880,600);
    abilitaBotaoFechar();
    TICKS();
    install_int_ex(tick_counter, BPS_TO_TIMER(60));
    MILI();
    install_int_ex(msec_counter, MSEC_TO_TIMER(1));
    srand(time(0));

    screen_state = TITLESCREEN;
}
END_OF_FUNCTION(init)

int busca(int* a, int k,int n,int x)
{
    if(k == n) return -1;
    if(a[k] == x) return k;
    return busca (a,k + 1, n, x);
}
END_OF_FUNCTION(busca)



