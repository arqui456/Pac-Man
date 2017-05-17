#include "personagens.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro.h>

 pacHombre pac;

void CriaPacman()
{
    //pac = malloc(sizeof(pac));
    pac.pacman = create_bitmap(33,33);
    pac.img = load_bitmap("sprites/pacman.bmp", NULL);
}

void set_default_Pos_p(int Mapa_state)
{
    int i;
    if(Mapa_state == 2)
    {
        pac.direcao = 4;
        pac.px = 30 * 15;
        pac.py = 30 * 15;
    }
    else if(Mapa_state == 1)
    {
        pac.direcao = 4;
        pac.px = 30 * 14;
        pac.py = 30 * 11;
    }
    else if(Mapa_state == 0)
    {
        pac.direcao = 4;
        pac.px = 30 * 19;
        pac.py = 30 * 16;
    }
}

/*
void Destroy_pac()
{
    int i;
    for(i = 0;i < 4;i++)
    {
        free(pac);
    }
}
*/













