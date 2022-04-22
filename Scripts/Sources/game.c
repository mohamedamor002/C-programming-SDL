#include "../Headers/game.h"

Game game; 

int right[2] = {0, 0};
int left[2] = {0, 0};
int up[2] = {0, 0};
int down[2] = {0, 0};
int direction[2] = {2, 2};

void handlePlayerMovement(SDL_Event event, int * game_loop, int * currentPage){
    switch (event.type) {
        case SDL_QUIT:
            *game_loop = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    right[0] = 1;
                    break;
                case SDLK_LEFT:
                    left[0] = 1;
                    break;
                case SDLK_UP:
                    up[0] = 1;
                    break;
                case SDLK_ESCAPE:
                    *currentPage = 0;
                    initGame(game.nb_players);
        }
        break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    right[0] = 0;
                    direction[0] = 2;
                    game.players[0].speed = 0;
                    break;
                case SDLK_LEFT:
                    left[0] = 0;
                    direction[0] = 3;
                    game.players[0].speed = 0;
                    break;
                case SDLK_UP:
                    direction[0] = 0;
                    break;
            }
        break;
    }
}


void initGame(int nb_players){
    game.nb_players = nb_players;
    if (nb_players == 1)
        initPlayerSingle(&game.players[0]);
    else
        for (int i = 0; i < nb_players; i++)
            initPlayerMulti(&game.players[i], i);
    
    if (nb_players == 1)
        initBackgroundSingle(&game.bg[0]);
    else 
        for (int i = 0; i < nb_players; i++)
            initBackgroundMulti(&game.bg[i], i);
}

void displayGame(SDL_Surface * screen){
    for (int i = 0; i < game.nb_players; i++){
        displayBackground(game.bg[i], screen);
        displayplayer(game.players[i] ,screen);
        display_all(game.players[i], screen);
    }
}

void updateGame(Uint32 tick_start){
    for (int i = 0; i < game.nb_players; i++){
        update_player(&game.players[i] , right[i], left[i], up[i]) ;  
        update_acceleration(&game.players[i])  ;
        SDL_Delay(1);
        Uint32 dt = SDL_GetTicks()- tick_start;
        moveplayer(&game.players[i],dt);
        animeplayer(&game.players[i]);
        check(&game.players[i],direction[i]) ;
        scrollBackground(&game.bg[i], game.players[i].direction, game.players[i].acceleration, game.players[i].speed, dt);
    }
}

void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage){
    while(SDL_PollEvent(&event)){
        handlePlayerMovement(event, game_loop, currentPage);
    }
}