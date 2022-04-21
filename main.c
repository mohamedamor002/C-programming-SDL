#include <SDL/SDL.h>

#include "Scripts/Headers/menu.h"

int SW = 1916, SH = 914;
int currentPage = 0;
SDL_Event event;
SDL_Surface * screen;
int game_loop = 1;

void init(){
  if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_VIDEO) != 0) {
    printf("error ! %s", SDL_GetError());
  }
  SDL_EnableUNICODE(1);
  TTF_Init();
  screen = SDL_SetVideoMode(SW , SH, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
  initMenu();
}

void update(){
  if (currentPage == 0){
      displayMenu(screen);
      handleMenuEvents(event, &game_loop, &currentPage);
  }

}

int main(int argc , char ** argv){
  init();
  while (game_loop){
    update();
    SDL_Flip(screen);
  }
  SDL_Quit();
  return 0;
}
