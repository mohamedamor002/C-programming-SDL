
#include "enemy.h"

typedef struct  {
    int nb_players; 
    int completed_enigma[2][5];
    player players[2];
    Background bg[2];
    mini mini_map[2];
    Enemy enemies[2];
    char player_name[50];
} Game; 

void handlePlayerMovement(SDL_Event event, int * game_loop, int * currentPage);
void initGame(int nb_players, char * player_name);
void displayGame(SDL_Surface * screen);
void updateGame(Uint32 tick_start);
void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage);
void handleEnigmaEvents(SDL_Event event, int * game_loop, int * en);
