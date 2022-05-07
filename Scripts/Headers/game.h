
#include "enemy.h"
#include "save.h"
#include "collider.h"
#include "animation.h"

typedef struct  {
    int nb_players; 
    int completed_enigma[2][5];
    player players[2];
    Background bg[2];
    mini mini_map[2];
    Enemy enemies[2];
    char player_name[50];
    int current_cloth;
} Game; 

void handlePlayerMovement(SDL_Event event, int * game_loop, int * currentPage);
void initGame(int nb_players, char * player_name, saved * s, int clothes_index);
void displayGame(SDL_Surface * screen);
void updateGame(Uint32 tick_start);
void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage);
