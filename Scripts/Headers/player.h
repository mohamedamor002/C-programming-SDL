#include <stdio.h>

#include <stdlib.h>

#include <SDL/SDL.h>

#include <stdbool.h>

#include <math.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

#include <SDL/SDL_mixer.h>

#include "enigma.h"


typedef struct {
  SDL_Surface * image_life[4];
  SDL_Rect position_life;
  int val;
  SDL_Rect position_text;
  TTF_Font * text;
  SDL_Color color;
  SDL_Surface * texte;
}
life;

typedef struct {
  // score
  char number[20];
  SDL_Rect position_textt;
  SDL_Rect position_number;
  int value_score;
  TTF_Font * font;
  SDL_Color white;
  SDL_Surface * texte1;
  SDL_Surface * number1;
}
score;

typedef struct {
  char number[20];
  SDL_Rect position_textt;
  SDL_Rect position_number;
  TTF_Font * font;
  SDL_Color white;
  SDL_Surface * texte1;
  SDL_Surface * number1;
} Timer; 


typedef struct {
  int nb; //  player number
  SDL_Surface * spritesheet;
  SDL_Rect pos; // position of the player in the background
  int direction;
  SDL_Rect pos_sprite;
  double speed, acceleration;
  int speedV;
  int val;
  life l; 
  score s; 
  Timer t;
  int multi;
  Enigma e;
  TextEnigma te; 
  int lasty;
  int enigma_up;
}
player;



void initPlayerSingle(player * p, int posx, int score, int clothes_index);
void initPlayerMulti(player * p, int p_index, int clothes_index);
void displayplayer(player p, SDL_Surface * screen);
void moveplayer(player * p, int dt, int col);
void animeplayer(player * p);
void jump(player * p);
void check(player * p, int dir1, int * up, int col);
score init_score(int p_index);
void manage_score(player * p, int p_index);
void update_player(player * p, int right, int left, int up);
void update_acceleration(player * p);
life init_life(int p_index);
void manage_life(life * l);
void display_all(player p, SDL_Surface * screen);
Timer initTimer(int p_index);
void updateTimer(Timer * t);
