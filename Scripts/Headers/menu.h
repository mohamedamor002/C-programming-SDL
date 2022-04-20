#include "button.h"
#include "text.h"

typedef struct {
  SDL_Rect rect;
  SDL_Surface * img;
} menu_bg;

typedef struct {
    int button_ids[4];
    menu_bg bg[2];
    int currentMenuPage; 
    int number_of_buttons;
    int currentActiveButtonIndex;
} Menu;


void initMenu();
void initHomePage();
void initNameSelectionPage();
void displayMenu( SDL_Surface * screen);
void handleMenuHomeButtonClick( SDL_Event event, int * game_loop);
void handleMenuEvents( SDL_Event event, int * game_loop, int * currentPage);
void handleHomePageEvents(SDL_Event event, int * game_loop, int * currentPage);
void handleNameSelectionPageEvents(SDL_Event event, int * game_loop, int * currentPage);
void handleMenuEvents(SDL_Event event, int * game_loop, int * currentPage);