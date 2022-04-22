#include "player.h"
#include "game_background.h"

typedef struct  {
    int nb_players; 
    player players[2];
    Background bg[2];
    int completed_enigma[2][5];
} Game; 

void handlePlayerMovement(SDL_Event event, int * game_loop, int * currentPage);
void initGame(int nb_players);
void displayGame(SDL_Surface * screen);
void updateGame(Uint32 tick_start);
void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage);