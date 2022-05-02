#include "../Headers/menu.h"
#include "../Headers/music.h"
#include "../Headers/game.h"

//#include "../TicTacToe/tictac.h"

char * MENU_BG_PATHS[5] = {
    "Media/Menu/menu_bg1.png",
    "Media/Menu/menu_bg2.png",
    "Media/Menu/menu_bg3.png",
    "Media/Menu/menu_bg4.png",
    "Media/Menu/menu_bg4.png",
};

Menu menu; 
Text nameText;
Text Volume;
Text BestScore; 
Text ClothesText;
saved s; 

void initMenu(){
    char hl[50] = "ahmad";
    s = load();
    initSound("Media/music.mp3");
    initHomePage();
    menu.lamin_but = initButton(1700, 800, 100, 100, "", "");
    for (int i = 0; i < 5; i++){
        menu.bg[i].rect.x = 0;
        menu.bg[i].rect.y = 0;
        menu.bg[i].rect.w = 1916;
        menu.bg[i].rect.h = 914;
        menu.bg[i].img = IMG_Load(MENU_BG_PATHS[i]);
        if (menu.bg[i].img == NULL)
            printf("FAIL BG");
    }
    menu.button_ids[0] = initButton(810, 322, 394, 98, "Media/Menu/newgameoff.png", "Media/Menu/newgameon.png");
    menu.button_ids[1] = initButton(810, 420, 394, 98, "Media/Menu/bestoff.png", "Media/Menu/beston.png");
    menu.button_ids[2] = initButton(850, 515,306, 98, "Media/Menu/settingsoff.png", "Media/Menu/settingson.png");
    menu.button_ids[3] = initButton(870, 620,210, 97, "Media/Menu/quitoff.png", "Media/Menu/quiton.png");
    menu.button_ids[4] = initButton(761, 322, 394, 98, "Media/Menu/Settings/sp.png", "Media/Menu/Settings/sp.png");
    menu.button_ids[5] = initButton(1008, 580, 50, 50, "Media/Menu/Settings/-.png", "Media/Menu/Settings/-.png");
    menu.button_ids[6] = initButton(761, 580, 50, 50, "Media/Menu/Settings/+.png", "Media/Menu/Settings/+.png");
    menu.button_ids[7] = initButton(761, 322, 394, 98, "Media/Menu/Settings/mp.png", "Media/Menu/Settings/mp.png");
    menu.nb = 1;
    menu.volume = 1;
}

void initHomePage(){
    menu.currentMenuPage = 0;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 4;
    menu.startButtonIndex = 0;
}

void initNameSelectionPage(){
    menu.currentMenuPage = 1;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 0;
    menu.startButtonIndex = 0;
    nameText = initText("", 500, 300, 0, 0, 0, "Fonts/Dancing.ttf", 75);
}

void initSettingsPage(){
    menu.currentMenuPage = 2;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 4; 
    menu.startButtonIndex = 4;
    Volume = initText("Volume", 820, 480, 255, 255, 255, "Fonts/Dancing.ttf", 75);
}

void initBestScorePage(){
    menu.currentMenuPage = 3;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 0;
    menu.startButtonIndex = 0;
    int best = getBestScore(s);
    char text[100]; 
    sprintf(text, "%s : %d", s.names[best], s.scores[best]);
    if (BestScore.font == NULL) 
        BestScore = initText(text, 670, 480, 200, 200, 200, "Fonts/Dancing.ttf", 100);
}

void initClothesPage(){
    menu.currentMenuPage = 4;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 0;
    menu.startButtonIndex = 0;
    menu.c = initClothes(); 
    char text[50] = "CURRENT SKIN:";
    if (ClothesText.font == NULL)
        ClothesText = initText(text, 670, 480, 255, 255, 255, "Fonts/Dancing.ttf", 75);

}

void displayMenu(SDL_Surface * screen){
    SDL_BlitSurface(menu.bg[menu.currentMenuPage].img, NULL, screen, &menu.bg[menu.currentMenuPage].rect);
    for (int i = menu.startButtonIndex; i < menu.number_of_buttons + menu.startButtonIndex; i++){
        if (i == 7 && menu.nb == 1)
            continue;
        else if (i == 4 && menu.nb == 2)
            continue; 
        displayButton(menu.button_ids[i], screen);
    }
    if (menu.currentMenuPage == 1)
        display_text(&nameText, screen);
    else if (menu.currentMenuPage == 2)
        display_text(&Volume, screen);
    else if (menu.currentMenuPage == 3)
        display_text(&BestScore, screen);
    else if (menu.currentMenuPage == 4){
        display_text(&ClothesText, screen);
        displayClothesPage(menu.c, screen);
    }
}   

void handleMenuHomeButtonClick( SDL_Event event, int * game_loop){
    switch(menu.currentActiveButtonIndex){
        case 0:
            initNameSelectionPage();
            break;
        case 1:
            initBestScorePage();
            break;
        case 2:
            initSettingsPage();
            break;        
        case 3:
            *game_loop = 0;

            break;
    }
}

void handleMenuSettingsButtonClick(SDL_Event event, int * game_loop, int * nb){
    switch(menu.currentActiveButtonIndex){
        case 4:
        case 7: 
            if (menu.nb == 1)
                menu.nb = 2;
            else if (menu.nb == 2)
                menu.nb = 1;
            break;
        case 6:
            if (menu.volume < 1){
                menu.volume += 0.25;
                updateVolume(menu.volume);
            }
            break;
        case 5:
            if (menu.volume > 0){
                menu.volume -= 0.25;
                updateVolume(menu.volume);
            }
            break; 
    }
}

void handleHomePageEvents(SDL_Event event, int * game_loop, int * currentPage, int * tiktakon){
      while(SDL_PollEvent(&event)){
      switch(event.type)
      {   
          case SDL_QUIT:
            *game_loop = 0;
            break;
          case SDL_MOUSEBUTTONDOWN:
            if (checkButtonHover(menu.lamin_but, event.motion.x, event.motion.y)){
                *tiktakon = 1;
            } else 
                handleMenuHomeButtonClick(event, game_loop);
            break;
          case SDL_MOUSEMOTION:
            for (int i = 0; i< menu.number_of_buttons; i++)
                if (checkButtonHover(menu.button_ids[i], event.motion.x, event.motion.y))
                    menu.currentActiveButtonIndex = i;
                else if (menu.currentActiveButtonIndex != i)
                    updateButtonState(menu.button_ids[i], 0);
                
            break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_UP:
                    updateButtonState(menu.button_ids[menu.currentActiveButtonIndex], 0);
                    if (menu.currentActiveButtonIndex == 0)
                        menu.currentActiveButtonIndex = menu.number_of_buttons - 1;
                    else 
                        menu.currentActiveButtonIndex--;
                    if (menu.currentActiveButtonIndex != -1 && menu.currentActiveButtonIndex != menu.number_of_buttons)
                        updateButtonState(menu.button_ids[menu.currentActiveButtonIndex], 1);
                    break;
                case SDLK_DOWN:
                    updateButtonState(menu.button_ids[menu.currentActiveButtonIndex], 0);
                    if (menu.currentActiveButtonIndex == 3)
                        menu.currentActiveButtonIndex = 0;
                    else 
                        menu.currentActiveButtonIndex++;
                    if (menu.currentActiveButtonIndex != -1 && menu.currentActiveButtonIndex != menu.number_of_buttons)
                        updateButtonState(menu.button_ids[menu.currentActiveButtonIndex], 1);
                    break;
                case SDLK_RETURN:
                    handleMenuHomeButtonClick(event, game_loop);
                    break;
                case SDLK_l:
                    initClothesPage();
                    break;
            }
            break;
      }
  }
}

void handleNameSelectionPageEvents(SDL_Event event, int * game_loop, int * currentPage){
    while(SDL_PollEvent(&event)){
        switch(event.type)
        {   
            case SDL_QUIT:
                *game_loop = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        initHomePage();
                        break;
                    case SDLK_a :
                        update_text(&nameText, 'a');
                        break;
                    break ;
                    case SDLK_b:  
                        update_text(&nameText, 'b') ;
                        break ;
                    case SDLK_c:   
                        update_text(&nameText, 'c') ;
                        break ;
                    case SDLK_d:  
                        update_text(&nameText, 'd') ;
                        break ;
                    case SDLK_e:  
                        update_text(&nameText, 'e') ;
                        break ;
                    case SDLK_f :  
                        update_text(&nameText, 'f') ;
                        break ;
                    case SDLK_g :  
                        update_text(&nameText, 'g') ;
                        break ;
                    case SDLK_h:  
                        update_text(&nameText, 'h') ;
                        break ;
                    case SDLK_i:  
                        update_text(&nameText, 'i') ;
                        break ;
                    case SDLK_j:  
                        update_text(&nameText, 'j') ;
                        break ;
                    case SDLK_k :  
                        update_text(&nameText, 'k') ;
                        break ;
                    case SDLK_l:  
                        update_text(&nameText, 'l') ;
                        break ;
                    case SDLK_m :  
                        update_text(&nameText, 'm') ;
                        break ;
                    case SDLK_n :  
                        update_text(&nameText, 'n') ;
                        break ;
                    case SDLK_o:  
                        update_text(&nameText, 'o') ;
                        break ;
                    case SDLK_p:  
                        update_text(&nameText, 'p') ;
                        break ;
                    case SDLK_q :  
                        update_text(&nameText, 'q') ;
                        break ;
                    case SDLK_r:  
                        update_text(&nameText, 'r') ;
                        break ;
                    case SDLK_s:  
                        update_text(&nameText, 's') ;
                        break ;
                    case SDLK_t:  
                        update_text(&nameText, 't') ;
                        break ;
                    case SDLK_u:  
                        update_text(&nameText, 'u') ;
                        break ;
                    case SDLK_v:  
                        update_text(&nameText, 'v') ;
                        break ;
                    case SDLK_w:  
                        update_text(&nameText, 'w') ;
                        break ;
                    case SDLK_x:  
                        update_text(&nameText, 'x') ;
                        break ;
                    case SDLK_y:  
                        update_text(&nameText, 'y') ;
                        break ;
                    case SDLK_z:  
                        update_text(&nameText, 'z') ;
                        break ;
                    case SDLK_SPACE: 
                        update_text(&nameText, ' ') ;
                        break ;
                    case SDLK_RETURN :
                        if (nameText.text_length != 0){
                            *currentPage = 1;
                            menu.currentMenuPage = 0;
                            menu.currentActiveButtonIndex = 0;
                            menu.number_of_buttons = 4;
                            initGame(menu.nb, nameText.text_string, &s, menu.c.currentCloth);
                        }
                        break ;
                }
                break;           
        }
    }
}

void handleBestScorePageEvents(SDL_Event event, int * game_loop, int * currentPage){
    while(SDL_PollEvent(&event)){
        switch(event.type)
        {   
            case SDL_QUIT:
                *game_loop = 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    initHomePage();
                break;    
        }
    }
}

void handleSettingsPageEvents(SDL_Event event, int * game_loop, int * currentPage, int * nb){
      while(SDL_PollEvent(&event)){
      switch(event.type)
      {   
          case SDL_QUIT:
            *game_loop = 0;
            break;
          case SDL_MOUSEBUTTONDOWN:
            handleMenuSettingsButtonClick(event, game_loop, nb);
            break;
          case SDL_MOUSEMOTION:
            for (int i = menu.startButtonIndex; i< menu.startButtonIndex + menu.number_of_buttons; i++)
                if (checkButtonHover(menu.button_ids[i], event.motion.x, event.motion.y))
                    menu.currentActiveButtonIndex = i;
                else if (menu.currentActiveButtonIndex != i)
                    updateButtonState(menu.button_ids[i], 0);
            break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_RETURN:
                    handleMenuHomeButtonClick(event, game_loop);
                    break;
                case SDLK_ESCAPE:
                    initHomePage();
                    break;
            }

            break;
      }
  }

}

void handleClothPageEvents(SDL_Event event, int * game_loop){
    while(SDL_PollEvent(&event)){
      switch(event.type)
      {   
          case SDL_QUIT:
            *game_loop = 0;
            break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_RIGHT:
                    if (menu.c.currentCloth + 1 < menu.c.nb_clothes){
                        menu.c.currentCloth++;
                    } else {
                        menu.c.currentCloth = 0;
                    }
                    break; 
                case SDLK_LEFT:
                    if (menu.c.currentCloth - 1 >= 0){
                        menu.c.currentCloth--;
                    } else {
                        menu.c.currentCloth = menu.c.nb_clothes - 1;
                    }
                    break;
                case SDLK_ESCAPE: 
                    initHomePage();
                    break; 
            }
      }
    }
}

void handleMenuEvents(SDL_Event event, int * game_loop, int * currentPage, int * nb, int * tiktakon){
    if (menu.currentMenuPage == 0){
        handleHomePageEvents(event, game_loop, currentPage, tiktakon);
    } else if (menu.currentMenuPage == 1){
        handleNameSelectionPageEvents(event, game_loop, currentPage);
    } else if (menu.currentMenuPage == 2){
        handleSettingsPageEvents(event, game_loop, currentPage, nb);
    } else if (menu.currentMenuPage == 3){
        handleBestScorePageEvents(event, game_loop, currentPage);
    } else if (menu.currentMenuPage == 4){
        handleClothPageEvents(event, game_loop);
    }
}

