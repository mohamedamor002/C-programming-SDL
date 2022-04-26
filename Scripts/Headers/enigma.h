#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include <time.h>

#include "button.h"


typedef struct {
    int choices[3][4];
    int question[3]; 
    int bg;
    int currentEnigma; 
    int er[3];  
    int right[3];
    int currentButton; 
    int enigmasCount;
} Enigma; 

void loadEnigmasFromFile(Enigma * e, int p_index);
Enigma initEnigma(int p_index);
void swapEnigma(Enigma * e);
void displayEnigma(Enigma e, SDL_Surface * screen);
void handleEnigmaEvents(SDL_Event event, int * game_loop, Enigma * e,  int * enigma_up);