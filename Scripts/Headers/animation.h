#include <stdio.h>

#include <stdlib.h>

#include <SDL/SDL.h>

#include <stdbool.h>

#include <math.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

#include <SDL/SDL_mixer.h>

#include <time.h>

typedef struct {
    SDL_Rect rect;
    SDL_Surface * img[2];
    int state; 
    Uint32 lastTimeChanged; 
} Animation1; 

typedef struct {
    SDL_Rect rect;
    SDL_Surface * img;
    Uint32 lastTimeChanged; 
} Animation2; 

void initAnim1(int p_index);
void initAnim2(int p_index, int mp);
void updateAnim1(int p_index);
void updateAnim2(int mp, int p_index);
void displayAnime(SDL_Surface * screen, int p_index);