#ifndef PERSONAGENS_H_INCLUDED
#define PERSONAGENS_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro.h>



typedef struct pacHombre{

    BITMAP* img;
    BITMAP* pacman;
	int direcao;
    int px;
    int py;

}pacHombre;

extern pacHombre pac;

void CriaPacman();

void set_default_Pos_p();


//void Destroy_pac();


#endif // PERSONAGENS_H_INCLUDED
