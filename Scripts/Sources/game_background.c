#include "../Headers/game_background.h"

#define startY 490

void initBackgroundSingle(Background * bg, int session){
    bg->rect.x = 0;
    bg->rect.y = 0;
    bg->bg_img = IMG_Load("Media/Game/background.png"); 
    bg->rect.w =  bg->bg_img->w;
    bg->rect.h = 914;
    // default 0
    bg->camera.x = session;
    bg->camera.y = 250;
    bg->camera.w = 1916;
    bg->camera.h = 914;
    bg->lastx = session;
}

void initBackgroundMulti(Background * bg, int bg_index){
    bg->rect.y = 0;
    bg->bg_img = IMG_Load("Media/Game/background.png"); 
    bg->rect.h = 914;
    bg->rect.w = bg->bg_img->w;
    bg->rect.x = bg_index == 0 ? 0 : 1916 / 2;
    bg->camera.x = 0;
    bg->camera.y = 250;
    bg->camera.w = 1916 / 2;
    bg->camera.h = 914;
    bg->lastx = 0;
}

void displayBackground(Background bg, SDL_Surface * screen){
      SDL_BlitSurface(bg.bg_img, &bg.camera, screen, &bg.rect);
}

void scrollBackground(Background * bg, int direction, double acc, double speed, int dt, int py){
    int dx = 0.5 * acc * dt * dt + speed * dt;
    bg->lastx = bg->camera.x;
    if (direction && (bg->camera.x >= dx))
        bg->camera.x -= dx;
    else if (!direction && (bg->camera.x + dx <= 15000))
        bg->camera.x += dx;
    bg->camera.y = 250 - (startY - py);
    
}