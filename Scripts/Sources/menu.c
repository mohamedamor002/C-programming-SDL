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
    nameText = initText("Filex", 800, 300, 0, 0, 0, "../../Fonts/Dancing.ttf", 35);
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
                printf("%c\n", event.key.keysym.unicode);
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        initHomePage();
                        break;
                    
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

