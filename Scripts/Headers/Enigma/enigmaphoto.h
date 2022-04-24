#ifndef enigmaphoto_H
#define enigmaphoto_h
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "choices.h"
#include "backgroundenigma.h"
#include<time.h>
typedef struct {
SDL_Rect position;
TTF_Font *font;
SDL_Surface *surfacetexte;
SDL_Color textcolor;
char text[50];
}Text ;
typedef struct {
  background1 bg;
  choice btn_list[4];
  int current_choice;
int active_choice;
Text t[3];
}
enigma;



void initEnigma(enigma *e,char *filename,int *j);
void display(SDL_Surface * screen,char ch[50]);
void display_enigma(SDL_Surface* screen);

void onKeyDown_enigma(SDL_Event event, int * quit, SDL_Surface* screen, char ch[50] ,int *j);
void animer(SDLKey key);
void update_enigma(SDL_Surface * screen,char ch[50]);
void choiceActive_enigma(int * quit,SDL_Surface * screen,char ch[50],int *j);
void onMouseHover_enigma();


#endif
