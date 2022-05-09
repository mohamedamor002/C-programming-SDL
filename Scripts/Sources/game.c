#include "../Headers/game.h"

Game game; 

int right[2] = {0, 0};
int left[2] = {0, 0};
int up[2] = {0, 0};
int down[2] = {0, 0};
int direction[2] = {2, 2};
int et = 1; 


saved * tops; 

void handlePlayerMovement(SDL_Event event, int * game_loop, int * currentPage){
    for (int i = 0; i < game.nb_players; i++)
        if (game.players[i].enigma_up == 1){
            if (!et)
                handleEnigmaEvents(event, game_loop, &game.players[i].e, &game.players[i].enigma_up);
            else 
                handleTextEnigmaEvents(event, game_loop, &game.players[i].te, &game.players[i].enigma_up);
        }
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
                case SDLK_d:
                    right[1] = 1;
                    break;
                case SDLK_q:
                    left[1] = 1;
                    break;
                case SDLK_z:
                    up[1] = 1;
                    break;
                case SDLK_ESCAPE:
                    save(tops, game.player_name, game.players[0].s.value_score, game.bg[0].camera.x, game.players[0].pos.x);
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
                case SDLK_d:
                    right[1] = 0;
                    direction[1] = 2;
                    game.players[1].speed = 0;
                    break;
                case SDLK_q:
                    left[1] = 0;
                    direction[1] = 3;
                    game.players[1].speed = 0;
                    break;
                case SDLK_z:
                    direction[1] = 0;
                    break;    
            }
        break;
    }
}


void initGame(int nb_players, char * player_name, saved * s, int clothes_index){
    tops = s;
    game.current_cloth = clothes_index;
    strcpy(game.player_name, player_name);
    game.nb_players = nb_players;
    int session[3] = {50, 0, 0};
    for (int i = 0; i < s->nb_saves; i++){
        if (strcmp(s->names[i], player_name) == 0){
            session[0] = s->xpos[i];
            session[1] = s->xcam[i];
            session[2] = s->scores[i];
            break;
        }       
    }
    if (nb_players == 1){
        initAnim1(0);
        initAnim2(0, 0);
        initMaskSurface();
        initPlayerSingle(&game.players[0], session[0], session[2], game.current_cloth);
        game.mini_map[0] = init_minimap(0, 0, session[1]);
        initEnemy(&game.enemies[0], 0);
        initBox(session[0], 490, 100, 100, 0);
    } else {
        for (int i = 0; i < nb_players; i++){
            initAnim1(i);
            initAnim2(i, 1);
            initPlayerMulti(&game.players[i], i, game.current_cloth);
            game.mini_map[i] = init_minimap(1, i, 0);
            initEnemy(&game.enemies[i], i);
        }
        //initBox(50, 490, 100, 100, 0);
        //initBox(958, 490, 100, 100, 1);
    }
    if (nb_players == 1)
        initBackgroundSingle(&game.bg[0], session[1]);
    else 
        for (int i = 0; i < nb_players; i++)
            initBackgroundMulti(&game.bg[i], i);
}

void displayGame(SDL_Surface * screen){
    for (int i = 0; i < game.nb_players; i++){
        if (game.players[i].enigma_up == 1){
            if (!et)
                displayEnigma(game.players[i].e, screen);
            else 
                displayTextEnigma(game.players[i].te, screen);
            
            continue;
        }

        displayBackground(game.bg[i], screen);
        displayplayer(game.players[i] ,screen);
        display_minimap(game.mini_map[i], screen);
        display_all(game.players[i], screen);
        displayEnemy(game.enemies[i], screen);
        displayAnime(screen, i);
    }
}

void updateGame(Uint32 tick_start){
    for (int i = 0; i < game.nb_players; i++){
        updateAnim1(i);
        updateAnim2(game.nb_players - 1, i);
        update_player(&game.players[i] , right[i], left[i], up[i]) ;  
        updateBox(i, game.players[i].pos.x, game.players[i].pos.y);
        update_acceleration(&game.players[i])  ;
        SDL_Delay(1);
        Uint32 dt = SDL_GetTicks()- tick_start;
        moveIA(&game.players[i], &game.enemies[i]);
        int l = checkCollisionFloor(i, game.players[i].pos.y, game.players[i].pos.x, game.bg[i].camera.x, game.bg[i].camera.y);
        int s = checkCollisionSides(i, game.players[i].pos.y, game.players[i].pos.x, game.bg[i].camera.x, game.bg[i].camera.y);
        if (l == 0)
            if (s == 2)
                game.players[i].pos.x -= 10;
            else if (s == 3)
                game.players[i].pos.x += 10;
        if (s == 0 || l == 1){
            moveplayer(&game.players[i],dt, s);
        } else if ((game.players[i].direction == 2) && (s == 3)){
            moveplayer(&game.players[i],dt, s);
        } else if  ((game.players[i].direction == 3) && (s == 2)) {
            moveplayer(&game.players[i],dt, s);
        }
        if ((s == 0) || ((game.players[i].direction == 3) && (s == 2)) || ((game.players[i].direction == 2) && (s == 3)) )
            scrollBackground(&game.bg[i], game.players[i].direction, game.players[i].acceleration, game.players[i].speed, dt, game.players[i].pos.y);
        else 
            game.bg[i].lastx =game.bg[i].camera.x;
        animeplayer(&game.players[i]);
        moveEnemy(&game.enemies[i], i);
        animateEnemy(&game.enemies[i]);
        check(&game.players[i],direction[i], &up[i], l) ;
        checkcollision(&game.players[i], game.enemies[i]);
        int dx = 0.5 * game.players[i].acceleration * dt * dt + game.players[i].speed * dt;
        updateWithBackground(&game.enemies[i], game.bg[i].camera.x, game.bg[i].lastx, game.players[i].direction, i);
        manage_life(&game.players[i].l);
        if (game.players[i].enigma_up == 2){
            game.players[i].enigma_up = 0;
            swapEnigma(&game.players[i].e);
            swapTextEnigma(&game.players[i].te);
            et = !et; 
        }
        else if (game.players[i].enigma_up == 3){
            game.players[i].enigma_up = 0;
            game.players[i].l.val--;
            swapEnigma(&game.players[i].e);
            swapTextEnigma(&game.players[i].te);
            et = !et; 
        }

        if (game.players[i].l.val == 1)
            initGame(game.nb_players, game.player_name, tops, game.current_cloth);
        if ((game.bg[0].camera.x >= 14700) && (game.players[i].l.val > 1))
            initGame(game.nb_players, game.player_name, tops, game.current_cloth);
        manage_score(&game.players[i], i);
        updateTimer(&game.players[i].t);
        game.enemies[i].pos.y = 490 + (490 - game.players[i].pos.y);
        update_mini(&game.mini_map[i], &game.players[i], game.bg[i], i);
    }
}

void handleGameEvents(SDL_Event event, int * game_loop, int * currentPage){
    while(SDL_PollEvent(&event)){
        handlePlayerMovement(event, game_loop, currentPage);
    }
}
