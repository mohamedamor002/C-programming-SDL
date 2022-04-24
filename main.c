#include <SDL/SDL.h>

#include "Scripts/TicTacToe/tictac.h"

int tiktakon = 0;

#include "Scripts/Headers/menu.h"

#include "Scripts/Headers/game.h"

int SW = 1916, SH = 914;
int currentPage = 0;
SDL_Event event;
SDL_Surface * screen;
int game_loop = 1;
Uint32 tick_start;
int nb = 1;

void init(){
  if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
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
    handleMenuEvents(event, &game_loop, &currentPage, &nb, &tiktakon);
  } else if (currentPage == 1){
    handleGameEvents(event, &game_loop, &currentPage);
    updateGame(tick_start);
    displayGame(screen);
  }

}

int main(int argc , char ** argv){
  init();
  int rate = 1000 / 60;
  while (game_loop){
    if (tiktakon){
      initTicTacToe(screen, &tiktakon);
      continue;
    }
    tick_start = SDL_GetTicks();
    update();
    SDL_Flip(screen);
    int delay = rate - SDL_GetTicks() + tick_start;
    if (delay > 0)
      SDL_Delay(delay);
  }
  liberateAllButtons();
  SDL_Quit();
  return 0;
}
