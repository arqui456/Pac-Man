#ifndef FANTASMA_H
#define FANTASMA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct ffantasma{

	int direcaoFantasma;
    int fx;
    int fy;

}ffantasma;

extern ffantasma fan[4];

void set_default_Pos();


#endif
