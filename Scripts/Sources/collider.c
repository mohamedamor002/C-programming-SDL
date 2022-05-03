#include "../Headers/collider.h"

SDL_Surface * mask; 


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

Box initBox(int x, int y, int w, int h){
    Box b; 
    b.x = x; 
    b.y = y; 
    b.w = w; 
    b.h = h;
    return b;  
}


void updateBox(Box * b, int x, int y ){
    b->x = x; 
    b->y = y; 
}

int checkCollision(Box b, int y, int x, int cx){
    for (int i = b.x; i < b.x + b.w; i++ ){
        SDL_Color color = GetPixelColor(mask, cx + i, b.y + b.h);
        if (color.r == color.b && color.g == color.r && color.r == 0){
            return 1;  
        }
    }
    return 0;
}