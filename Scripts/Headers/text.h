#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

typedef struct {
    SDL_Rect rect ;
    TTF_Font  * font ;
    SDL_Surface * surface ;
    SDL_Color color ;
    char text_string[200];
    int text_length; 
} Text; 


Text initText(char * text_string, int x, int y, int r, int g, int b, char * font, int font_size);
void display_text(Text * t, SDL_Surface* screen );
void update_text(Text * t, char new_text_char);
int checkTextHover(Text * t, int x, int y);