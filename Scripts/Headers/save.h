
#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct {
    char names[20][50];
    int scores[20]; 
    int xpos[20];
    int xcam[20];
    int nb_saves; 
} saved; 


void save(saved * s, char * name, int score, int xcam, int xp);
saved load();
int getBestScore(saved s);