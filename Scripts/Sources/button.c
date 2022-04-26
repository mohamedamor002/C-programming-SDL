#include "../Headers/button.h"

Button currentButtons[30];
int number_of_buttons = 0;

int initButton(int x, int y, int w, int h, char * p1, char * p2){
  Button b;
  b.rect.x = x;
  b.rect.y = y;
  b.rect.w = w;
  b.rect.h = h;
  b.img[0] = IMG_Load(p1);
  b.img[1] = IMG_Load(p2);
  if ((b.img[0] == NULL) || (b.img[1] == NULL))
    printf("Unable to load button: %s\n", SDL_GetError());
  b.current_state = 0;
  currentButtons[number_of_buttons] = b;
  number_of_buttons++;
  return (number_of_buttons - 1);
}

void displayButton(int b, SDL_Surface * screen){
  int state = currentButtons[b].current_state;
  SDL_BlitSurface(currentButtons[b].img[state], NULL, screen, &currentButtons[b].rect);
}

int checkButtonHover(int b, int x, int y){
    // check for x axis
    if (currentButtons[b].rect.x <= x && currentButtons[b].rect.x + currentButtons[b].rect.w >= x)
      // check for y axis
      if (currentButtons[b].rect.y <= y && currentButtons[b].rect.y + currentButtons[b].rect.h >= y){
        updateButtonState(b, 1);
        return 1;
      }
    return 0;
}

void updateButtonState(int button_id, int state){
  currentButtons[button_id].current_state = state;
}

void liberateAllButtons(){
  for (int i = 0; i < number_of_buttons; i++){
    SDL_FreeSurface(currentButtons[i].img[0]);
    SDL_FreeSurface(currentButtons[i].img[1]);
  }
}