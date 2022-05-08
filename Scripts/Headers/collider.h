#include <stdio.h>

#include <stdlib.h>

#include <SDL/SDL.h>

#include <stdbool.h>

#include <math.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

#include <SDL/SDL_mixer.h>

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Box_C; 


SDL_Color GetPixelColor(const SDL_Surface* pSurface, const int X, const int Y);
void initMaskSurface();
void initBox(int x, int y, int w, int h, int p_index);
void updateBox(int p_index, int x, int y );
int checkCollisionSides(int p_index, int y, int x, int cx, int cy);
int checkCollisionFloor(int p_index, int y, int x, int cx, int cy);
