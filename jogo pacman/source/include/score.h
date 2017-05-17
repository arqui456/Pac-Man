#ifndef SCORE_H
#define SCORE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int player = 0;

typedef struct Score{
	int player_score;
	char player_name[33];
}Score;

extern Score score_table[11];

bool load_scores();

bool save_scores();

void sort_scores();

#endif
