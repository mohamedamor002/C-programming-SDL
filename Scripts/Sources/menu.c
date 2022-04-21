#include "../Headers/menu.h"

char * MENU_BG_PATHS[2] = {
    "Media/Menu/menu_bg1.png",
    "Media/Menu/menu_bg2.png",
};

Menu menu; 
Text nameText;

void initMenu(){
    initHomePage();
    for (int i = 0; i < 2; i++){
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
}

void initHomePage(){
    menu.currentMenuPage = 0;
    menu.currentActiveButtonIndex = 0;
    menu.number_of_buttons = 4;
}

void initNameSelectionPage(){
    menu.currentMenuPage = 1;
    menu.currentActiveButtonIndex = -1;
    menu.number_of_buttons = 0;
    nameText = initText("", 500, 300, 0, 0, 0, "Fonts/Dancing.ttf", 75);
}

void displayMenu(SDL_Surface * screen){
    SDL_BlitSurface(menu.bg[menu.currentMenuPage].img, NULL, screen, &menu.bg[menu.currentMenuPage].rect);
    for (int i = 0; i < menu.number_of_buttons; i++){
        displayButton(menu.button_ids[i], screen);
    }
    if (menu.currentMenuPage == 1)
        display_text(&nameText, screen);
}

void handleMenuHomeButtonClick( SDL_Event event, int * game_loop){
    switch(menu.currentActiveButtonIndex){
        case 0:
            initNameSelectionPage();
            break;
        case 1:
            break;
        case 2:
            break;        
        case 3:
            *game_loop = 0;
            break;
    }
}


void handleHomePageEvents(SDL_Event event, int * game_loop, int * currentPage){
      while(SDL_PollEvent(&event)){
      switch(event.type)
      {   
          case SDL_QUIT:
            *game_loop = 0;
            break;
          case SDL_MOUSEBUTTONDOWN:
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
                        if (nameText.text_length != 0)
                            *currentPage = 1;
                        break ;
                }
                break;           
        }
    }
}

void handleMenuEvents(SDL_Event event, int * game_loop, int * currentPage){
    if (menu.currentMenuPage == 0){
        handleHomePageEvents(event, game_loop, currentPage);
    } else if (menu.currentMenuPage == 1){
        handleNameSelectionPageEvents(event, game_loop, currentPage);
    }
}

