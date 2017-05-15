#ifndef SCORE_H
#define SCORE_H

struct Score{
	int player_score;
	char player_name[33];	
};

extern Score score_table[11];

bool load_scores();

bool save_scores();

void sort_scores();

#endif