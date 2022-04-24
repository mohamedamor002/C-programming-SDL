#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>



typedef struct  {
  SDL_Rect rect;
  SDL_Surface * img[2];
  int current_state;
} Button;

int initButton(int x, int y, int w, int h, char * p1, char * p2);
void displayButton(int b, SDL_Surface * screen);
int checkButtonHover(int b, int x, int y);
void updateButtonState(int button_id, int state);
void liberateAllButtons();