#include "../Headers/text.h"

Text initText(char * text_string, int x, int y, int r, int g, int b, char * font, int font_size){
    Text t;
    strcpy(t.text_string, text_string);
    t.text_length = strlen(t.text_string);
    t.surface = NULL ;
    t.rect.x = x;
    t.rect.y = y ;
    t.rect.w = 700;
    t.rect.h = 100;
    t.color.r = r;
    t.color.g = g;
    t.color.b = b;
    t.font = TTF_OpenFont(font, font_size)  ;
    if (t.font == NULL)
        printf("FAILEDFONT\n");
    return t ;
}

void display_text(Text * t, SDL_Surface* screen ){
    t->surface = TTF_RenderText_Solid(t->font, t->text_string, t->color);
    SDL_BlitSurface(t->surface, NULL, screen, &t->rect);
}

void update_text(Text * t, char new_text_char){
   t->text_string[t->text_length] = new_text_char;
   t->text_string[t->text_length + 1] = '\0';
   t->text_length++;
}

int checkTextHover(Text * t, int x, int y){
    // check for x axis
    if (t->rect.x <= x && t->rect.x + t->rect.w >= x)
      // check for y axis
      if (t->rect.y <= y && t->rect.y + t->rect.h >= y){
        t->color.r = 255;
        t->color.g = 0;
        t->color.b = 0;
        return 1;
      }
    t->color.r = 255;
    t->color.g = 255;
    t->color.b = 255;
    return 0;
}