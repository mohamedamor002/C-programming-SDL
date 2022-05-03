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
} Box; 


SDL_Color GetPixelColor(const SDL_Surface* pSurface, const int X, const int Y);
void initMaskSurface();
Box initBox(int x, int y, int w, int h);
void updateBox(Box * b, int x, int y );
int checkCollision(Box b, int y, int x, int cx);