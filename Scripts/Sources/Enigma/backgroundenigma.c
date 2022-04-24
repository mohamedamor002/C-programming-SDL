#include "../../Headers/Enigma/backgroundenigma.h"


background1 initBackground(char * path, int w, int h){
  background1 bg;
  bg.bg_img = IMG_Load(path);

  if ( bg.bg_img == NULL ){
    printf("Unable to load background: %s\n", SDL_GetError());
    return bg;
  }
  bg.rect.x = 0;
  bg.rect.y = 0;
  bg.rect.w = w;
  bg.rect.h = h;
  return bg;

};
void displayBackgroundE(background1 bg, SDL_Surface * screen){
  SDL_BlitSurface(bg.bg_img, NULL, screen, &bg.rect);
}

