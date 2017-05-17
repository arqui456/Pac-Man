#include "fantasma.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro.h>

ffantasma fan[4];
//ffantasma* fan = malloc(4*sizeof(ffantasma));

void CriaFantasma()
{
    fan[0].fantasma = create_bitmap(30,30);
    fan[1].fantasma = create_bitmap(30,30);
    fan[2].fantasma = create_bitmap(30,30);
    fan[3].fantasma = create_bitmap(30,30);
}

void perseguir()
{
    fan[0].img = load_bitmap("sprites/fantasmaRed.bmp", NULL);
    fan[1].img = load_bitmap("sprites/fantasmaOrange.bmp", NULL);
    fan[2].img = load_bitmap("sprites/fantasmaBlue.bmp", NULL);
    fan[3].img = load_bitmap("sprites/fantasmaBlueF.bmp", NULL);
    comivel(FALSE);
}

void set_default_Pos(int Mapa_state, int i,int n)
{
    //int i;
    if(Mapa_state == 2)
    {
            for(;i < n;i++)
            {
                fan[i].direcaoFantasma = 0;
                fan[i].fx = 30 * 15;
                fan[i].fy = 30 * 9;
                fan[i].comivel = FALSE;
            }
    }
    else if(Mapa_state == 1)
    {
            for(;i < n;i++)
            {
                fan[i].fx = 30 * 8;
                fan[i].fy = 30 * 9;
                fan[i].comivel = FALSE;
            }
    }
    else if(Mapa_state == 0)
    {
            for(;i < n;i++)
            {
                fan[i].fx = 30 * 10;
                fan[i].fy = 30 * 11;
                fan[i].comivel = FALSE;
            }
    }
}

void foiComido(int Mapa_state,int i)
{
    fan[i].comivel = FALSE;
    set_default_Pos(Mapa_state,i,i + 1);
    if(i == 0)
    {
        fan[0].img = load_bitmap("sprites/fantasmaRed.bmp", NULL);
    }
    else if(i == 1)
    {
        fan[1].img = load_bitmap("sprites/fantasmaOrange.bmp", NULL);
    }
    else if(i == 2)
    {
        fan[2].img = load_bitmap("sprites/fantasmaBlue.bmp", NULL);
    }
    else if(i == 3)
    {
        fan[3].img = load_bitmap("sprites/fantasmaBlueF.bmp", NULL);
    }

}

void comivel(int comivel)
{
    int i;

    for(i = 0;i < 4;i++)
        fan[i].comivel = comivel;
}

void fugir(SAMPLE* waza)
{
    int i;

    for(i = 0;i < 4;i++)
    {
        fan[i].img = load_bitmap("sprites/correFan.bmp", NULL);
    }
    play_sample(waza,100,128,1000,TRUE);
}

void tempo(int time,int* flag, SAMPLE* waza,SAMPLE* siren,int* contou)
{
    int stopTime;
    if((*flag))
    {
        stopTime = time;
        (*flag) = FALSE;
    }
    if((time >= stopTime + 25000) && (*contou))
    {
        stop_sample(waza);
        play_sample(siren,300,128,1000,TRUE);
        perseguir();
        (*contou) = 0;
    }
}

void Destroy_fan()
{
    int i;
    for(i = 0;i < 4;i++)
    {
        free(fan);
    }
}





