#include "fantasma.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ffantasma fan[4];

void set_default_Pos()
{
        fan[0].direcaoFantasma = 0;
        fan[1].direcaoFantasma = 0;
        fan[2].direcaoFantasma = 0;
        fan[3].direcaoFantasma = 0;

        fan[0].fx = 30 * 15;
        fan[1].fx = 30 * 15;
        fan[2].fx = 30 * 15;
        fan[3].fx = 30 * 15;

        fan[0].fy = 30 * 9;
        fan[1].fy = 30 * 9;
        fan[2].fy = 30 * 9;
        fan[3].fy = 30 * 9;
}




