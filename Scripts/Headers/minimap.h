#include "player.h"
#include "game_background.h"

typedef struct {
  SDL_Surface * img;
  SDL_Rect pos;
  SDL_Surface * player;
  SDL_Rect posp;
  SDL_Rect camera;
  int multi;
}
mini;

mini init_minimap(int multiplayer, int p_index, int posx);
void display_minimap(mini M, SDL_Surface * screen);
void update_mini(mini * M, player * p, Background b, int index);
