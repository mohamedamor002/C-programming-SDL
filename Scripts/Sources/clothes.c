#include "../Headers/clothes.h"

char cloth[2][100] = {
    "Media/Player/perso.png",
    "Media/Player/perso1.png"
}; 


void initImg(img * i,int x, int y, int w, int h, char * path){
    i->rect.x = x;
    i->rect.y = y;
    i->rect.w = w;
    i->rect.h = h;
    i->src = IMG_Load(path);
    if (i->src == NULL)
        printf("FAIL img");
}

clothesPage initClothes(){
    clothesPage c; 
    c.nb_clothes = 2; 
    c.rect.x = 0;
    c.rect.y = 200;
    c.rect.h = 100;
    c.rect.w = 100;
    for (int i = 0; i < c.nb_clothes; i++){
        initImg(&c.cloth[i], 850, 620, 500, 500, cloth[i]); 
    }
    c.currentCloth = 0;
    return c; 
}


void displayClothesPage(clothesPage c, SDL_Surface * screen){
    SDL_BlitSurface(c.cloth[c.currentCloth].src, &c.rect, screen, &c.cloth[c.currentCloth].rect);
}