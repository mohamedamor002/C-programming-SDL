#include <stdio.h>

#include <stdlib.h>

#include <SDL/SDL.h>

#include <stdbool.h>

#include <math.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

#include <SDL/SDL_mixer.h>

typedef struct {
  int nb; //  player number
  SDL_Surface * spritesheet;
  SDL_Rect pos; // position of the player in the background
  int direction;
  SDL_Rect pos_sprite;
  double speed, acceleration;
  int speedV;
  int val;
}
player;

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

void initplayer(player * p);
void displayplayer(player p, SDL_Surface * screen);
void moveplayer(player * p, int dt);
void animeplayer(player * p);
void jump(player * p);
void check(player * p, int dir1);
score init_score();
void manage_score(score * s);
void update(player * p, int right, int left, int up);
void update_acceleration(player * p);
life init_life();
void manage_life(life * l, int * lifes);
void display_all(life l, score s, SDL_Surface * screen);