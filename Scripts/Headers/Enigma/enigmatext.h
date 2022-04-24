#ifndef enigmatext_H
#define enigmatext_h
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
//*********text structure 
typedef struct {
SDL_Rect position;
TTF_Font *font;
SDL_Surface *surfacetexte;
SDL_Color textcolor;
char text[100];
}Text1;
//**********textwatch animation 
typedef struct{
TTF_Font *fontTest;
 SDL_Color fontColor;
 SDL_Surface *stopwatch;
 char timeText[20];
 SDL_Rect position;
}Watch;
//**********images structure
typedef struct{
SDL_Rect pos ; 
SDL_Surface * img ;
} Image ; 

typedef struct {
Image image[3];
Text1 t[6];
Watch w;
int current_text_on;
int number_of_text;
char correctanswer[80];
}Enigma;


void Init_Enigma_text(Enigma * e, char *filename);
void display_Enigma_text(Enigma e, SDL_Surface * screen);
void load_win_image_enigma_text(Enigma * e ) ;
void display_win_image_enigma_text(Enigma  e , SDL_Surface * screen ) ;
void load_lose_image_enigma_text(Enigma * e ) ;
void display_lose_image_enigma_text(Enigma  e , SDL_Surface * screen ) ;
void load_enigma_text_background(Enigma * e ) ;
void display_enigma_text_background(Enigma  e, SDL_Surface * screen ) ;
int isMouseOvertext_enigma_text(int mouse_x, int mouse_y, int entity_x, int entity_y, int entity_w, int entity_h);
//void freeall_enigma_text(Text1 t[],Image image[]);//free function 
//new 
void printbutton_enigma_text(Enigma * e,SDL_Event event ,int * change,SDL_Surface *screen,int * done );
void current_text_on_1_enigma(Enigma * e,int * change );
void current_text_on_2_enigma(Enigma * e,int * change );
void display_win_lose_enigma_text(Enigma * e,SDL_Surface *screen ,int change  );
void mouse_motion_enigma_text(Enigma * e,int texton[],SDL_Event event);
void mouse_button_up_enigma_text(Enigma e, int texton[],SDL_Event event, SDL_Surface *screen   );


#endif
