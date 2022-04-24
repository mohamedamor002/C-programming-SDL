#ifndef backgroundenigma_H
#define backgroundenigma_h
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct {
  SDL_Rect rect;
  SDL_Surface * bg_img;
}
background1;

background1 initBackground(char * path, int w, int h);
void displayBackgroundE(background1 bg, SDL_Surface * screen);


#endif
