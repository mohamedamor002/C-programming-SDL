#include "../Headers/text.h"

Text initText(char * text_string, int x, int y, int r, int g, int b, char * font, int font_size){
    Text t;
    strcpy(t.text_string, text_string);
    t.surface = NULL ;
    t.rect.x = x;
    t.rect.y = y ;
    t.color.r = r;
    t.color.g = g;
    t.color.b = b;
    t.font = TTF_OpenFont(font, font_size)  ;
    return t ;
}

void display_text(Text * t, SDL_Surface* screen ){
    t->surface = TTF_RenderText_Solid(t->font, t->text_string, t->color);
    SDL_BlitSurface(t->surface, NULL, screen, &t->rect);
}

void update_text(Text * t, char * new_text_string){
    strcpy(t->text_string, new_text_string);
}