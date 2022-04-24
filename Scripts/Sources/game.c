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


void initGame(int nb_players, char * player_name){
    strcpy(game.player_name, player_name);
    game.nb_players = nb_players;
    if (nb_players == 1){
        initPlayerSingle(&game.players[0]);
        game.mini_map[0] = init_minimap(0, 0);
        initEnemy(&game.enemies[0], 0);
    } else
        for (int i = 0; i < nb_players; i++){
            initPlayerMulti(&game.players[i], i);
            game.mini_map[i] = init_minimap(1, i);
            initEnemy(&game.enemies[i], i);
        }
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
        display_minimap(game.mini_map[i], screen);
        display_all(game.players[i], screen);
        displayEnemy(game.enemies[i], screen);
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
        moveEnemy(&game.enemies[i], i);
        animateEnemy(&game.enemies[i]);
        check(&game.players[i],direction[i], &up[i]) ;
        checkcollision(&game.players[i], game.enemies[i]);
        manage_life(&game.players[i].l);
        if (game.players[i].l.val == 1)
            initGame(game.nb_players, game.player_name);
        if ((game.bg[0].camera.x >= 14700) && (game.players[i].l.val > 1))
            initGame(game.nb_players, game.player_name);
        manage_score(&game.players[i], i);
        updateTimer(&game.players[i].t);
        scrollBackground(&game.bg[i], game.players[i].direction, game.players[i].acceleration, game.players[i].speed, dt);
        update_mini(&game.mini_map[i], &game.players[i], game.bg[i], i);
    }
}

void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage){
    while(SDL_PollEvent(&event)){
        handlePlayerMovement(event, game_loop, currentPage);
    }
}
