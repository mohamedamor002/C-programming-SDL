#include "../Headers/minimap.h"


mini init_minimap(int mp, int p_index, int posx) {
  mini M;
  M.multi = mp;
  M.img = IMG_Load("Media/Minimap/mini.png");
  if (M.img == NULL) printf("no \n");
  M.pos.x = mp ? p_index * (1916 / 2) : 0;
  M.pos.y = 0;
  M.pos.w = 500; /// factor : 5   width :  200  height :156
  M.pos.h = 300;
  M.player = IMG_Load("Media/Minimap/point.png");
  M.posp.x = mp ? p_index * (1916 / 2) : 0;
  M.posp.y = 280;
  M.posp.w = 20;
  M.posp.h = 20;
  M.camera.x = (posx * 5143) / 16116;
  M.camera.y = 0;
  M.camera.w = 500;
  M.camera.h = 300;
  return M;
}

void display_minimap(mini M, SDL_Surface * screen) {
  SDL_BlitSurface(M.img, &M.camera, screen, & M.pos);
  SDL_BlitSurface(M.player, NULL, screen, & M.posp);
}

void update_mini(mini * M,  player * p, Background b, int index) {
  if (M->multi)
    if (index == 0)
      M -> posp.x = ( p -> pos.x * 500) / (1916 / 2);    
    else 
      M -> posp.x = (( (p -> pos.x -  (1916 / 2) ) * 500) / (1916 / 2)) +  (1916 / 2);    
      
  else {
    M -> posp.x = ( p -> pos.x * 500) / (1916);    
  }
  M->camera.x = (b.camera.x * 5143) / 16116;  
}