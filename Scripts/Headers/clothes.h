#include <stdio.h>

#include <stdlib.h>

#include <SDL/SDL.h>

#include <stdbool.h>

#include <math.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Rect rect;
    SDL_Surface * src;
} img; 


typedef struct {
    int nb_clothes;
    img cloth[5]; 
    int currentCloth; 
    SDL_Rect rect; 
} clothesPage;



void initImg(img * i,int x, int y, int w, int h, char * path);
clothesPage initClothes();
void displayClothesPage(clothesPage c, SDL_Surface * screen);