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
  SDL_Surface * bg_img;
  SDL_Rect camera;
  int lastx;

} Background;


void initBackgroundSingle(Background * bg, int session);
void initBackgroundMulti(Background * bg, int bg_index);
void displayBackground(Background bg, SDL_Surface * screen);
void scrollBackground(Background * bg, int direction, double acc, double speed, int dt, int py);