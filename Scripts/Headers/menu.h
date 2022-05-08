#include "clothes.h"

typedef struct {
  SDL_Rect rect;
  SDL_Surface * img;
} menu_bg;

typedef struct {
    int button_ids[8];
    menu_bg bg[5];
    int lamin_but;
    int currentMenuPage; 
    int number_of_buttons;
    int currentActiveButtonIndex;
    int startButtonIndex;
    int nb;
    float volume;
    int cloth_index; 
    clothesPage c; 
} Menu;


void initMenu();
void initHomePage();
void initNameSelectionPage();
void initSettingsPage();
void initBestScorePage();
void initClothesPage();
void displayMenu( SDL_Surface * screen);
void handleMenuHomeButtonClick( SDL_Event event, int * game_loop);
void handleMenuEvents( SDL_Event event, int * game_loop, int * currentPage, int * nb, int * tiktakon);
void handleHomePageEvents(SDL_Event event, int * game_loop, int * currentPage, int * tiktakon);
void handleNameSelectionPageEvents(SDL_Event event, int * game_loop, int * currentPage);
void handleSettingsPageEvents(SDL_Event event, int * game_loop, int * currentPage, int * nb);
void handleMenuSettingsButtonClick(SDL_Event event, int * game_loop, int * nb);
void handleBestScorePageEvents(SDL_Event event, int * game_loop, int * currentPage);
