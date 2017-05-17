#include "include/score.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Score score_table[11];

void set_default_scores()
{
	 strcpy(score_table[0].player_name, "Elephant");
	 	score_table[0].player_score = 90;
	 strcpy(score_table[1].player_name, "Hippo");
	    score_table[1].player_score = 80;
	 strcpy(score_table[2].player_name, "Giraffe");
	  	score_table[2].player_score = 70;
	 strcpy(score_table[3].player_name, "Zebra");
	    score_table[3].player_score = 60;
	 strcpy(score_table[4].player_name, "Lion");
	  	score_table[4].player_score = 50;
	 strcpy(score_table[5].player_name, "Wombat");
	    score_table[5].player_score = 40;
	 strcpy(score_table[6].player_name, "Kangaroo");
	    score_table[6].player_score = 40;
	 strcpy(score_table[7].player_name, "Echidna");
	    score_table[7].player_score = 40;
	 strcpy(score_table[8].player_name, "Emu");
	    score_table[8].player_score = 40;
	 strcpy(score_table[9].player_name, "Possum");
	    score_table[9].player_score = 40;

	 strcpy(score_table[10].player_name, "enter name");
	 	score_table[10].player_score = 0;
}

bool load_scores()
{
	FILE *hsf;

	hsf = fopen("highscores.bin", "rb");

	if(hsf != NULL){
		if(fread(score_table, sizeof(Score), 10,hsf) != 10)
		{
			set_default_scores();
			return false;
		}
		fclose(hsf);
	}
	else
	{
		set_default_scores();
		return false;
	}

	strcpy(score_table[10].player_name, "enter name");
	score_table[10].player_score = 0;

	return true;
}

bool save_scores()
{
	FILE *hsf;

	hsf = fopen("highscores.bin", "wb");

	if(hsf != NULL)
	{
		fwrite(score_table, sizeof(Score),10,hsf);
		fclose(hsf);

		return true;
	}
	return false;
}

int qsort_helper_by_score(const void *e1,const void *e2)
{
	return ((const Score *)e2)->player_score - ((const Score *)e1)->player_score;
}

void sort_scores()
{
	qsort(score_table, 11, sizeof(Score), qsort_helper_by_score);
}

