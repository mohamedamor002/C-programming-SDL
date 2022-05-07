#include "../Headers/collider.h"

SDL_Surface * mask; 

Box_C Boxes[2]; 

SDL_Color GetPixelColor(const SDL_Surface* pSurface, const int X, const int Y)
{
	const Uint8 Bpp = pSurface->format->BytesPerPixel;

	Uint8* pPixel = (Uint8*)pSurface->pixels + Y * pSurface->pitch + X * Bpp;

	Uint32 PixelData = *(Uint32*)pPixel;

	SDL_Color Color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

	SDL_GetRGB(PixelData, pSurface->format, &Color.r, &Color.g, &Color.b);
	return Color;
}

void initMaskSurface(){
    mask = IMG_Load("Media/Game/mask.png");
}

void initBox(int x, int y, int w, int h, int p_index){
    Boxes[p_index].x = x; 
    Boxes[p_index].y = y; 
    Boxes[p_index].w = w; 
    Boxes[p_index].h = h;
}


void updateBox(int p_index, int x, int y ){
    Boxes[p_index].x = x; 
    Boxes[p_index].y = y; 
}

int checkCollision(int p_index, int y, int x, int cx){
    for (int i = Boxes[p_index].x; i < Boxes[p_index].x + Boxes[p_index].w; i++ ){
        SDL_Color color = GetPixelColor(mask, cx + i, Boxes[p_index].y + Boxes[p_index].h);
        if (color.r == color.b && color.g == color.r && color.r == 0){
            return 1;  
        }
    }
    return 0;
}