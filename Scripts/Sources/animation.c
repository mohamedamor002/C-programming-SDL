#include "../Headers/animation.h"

Animation1 a[2]; 
Animation2 b[2]; 

void initAnim1(int p_index){
    a[p_index].rect.x = p_index * (1916/2) + 50;
    a[p_index].rect.y = 50; 
    a[p_index].img[0] = IMG_Load("Media/Animation/t2.png");
    a[p_index].img[1] = IMG_Load("Media/Animation/t1.png");
    a[p_index].state = 0;
    a[p_index].lastTimeChanged = SDL_GetTicks(); 
}


void initAnim2(int p_index, int mp){
    srand(time(NULL));
    int x; 
    if (mp)
        x = rand() % (1916/2) + (1916/2) * p_index;
    else 
        x = rand() % 1916; 
    b[p_index].rect.x = x;
    b[p_index].rect.y = rand() % 300; 
    b[p_index].img = IMG_Load("Media/Animation/star.png");
    b[p_index].lastTimeChanged = SDL_GetTicks(); 
}


void updateAnim1(int p_index){
    if (SDL_GetTicks() - a[p_index].lastTimeChanged  >= 1000){
        a[p_index].state = !a[p_index].state; 
        a[p_index].lastTimeChanged = SDL_GetTicks();
    }
}


void updateAnim2(int mp, int p_index){
    srand(time(NULL));
    int x; 
    if (mp)
        x = rand() % (1916/2) + (1916/2) * p_index;
    else 
        x = rand() % 1916; 
    if (SDL_GetTicks() - b[p_index].lastTimeChanged  >= 1000){
        b[p_index].rect.x = x;
        b[p_index].rect.y = rand() % 300;
        b[p_index].lastTimeChanged = SDL_GetTicks();
    }

}


void displayAnime(SDL_Surface * screen, int p_index){
    SDL_BlitSurface(a[p_index].img[a[p_index].state], NULL, screen, &a[p_index].rect);
    SDL_BlitSurface(b[p_index].img, NULL, screen, &b[p_index].rect);
}