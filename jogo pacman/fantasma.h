#ifndef FANTASMA_H
#define FANTASMA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro.h>



typedef struct ffantasma{

    BITMAP* img;
    BITMAP* fantasma;
	int direcaoFantasma;
    int fx;
    int fy;
    int comivel;

}ffantasma;

extern ffantasma fan[4];

void CriaFantasma();

void perseguir();

void set_default_Pos(int Mapa_state,int i,int n);

void comivel(int comivel);

void foiComido(int Mapa_state,int i);

void fugir(SAMPLE* waza);

void tempo(int time,int* flag,SAMPLE* waza,SAMPLE* siren,int* contou);

void Destroy_fan();


#endif
