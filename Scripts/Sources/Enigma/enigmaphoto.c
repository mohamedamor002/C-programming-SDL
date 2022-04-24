#include "../../Headers/Enigma/enigmaphoto.h"

#define choice_W 150
#define choice_H 122


enigma enigma_menu;
int old_active1 = 0;
int change1 = 0;
  


void initEnigma(enigma *e,char *filename,int *j){
FILE *f;
int i=0;
char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50],ch7[50],ch8[50];
  enigma_menu.current_choice = -1;
  enigma_menu.bg = initBackground("Media/Enigma/bg.png", 1000, 780);

f=fopen(filename,"r");
if (f==NULL)
{printf("could not open the file\n");
return ;}
srand(time(NULL));
*j=(rand()% (3));
while((fscanf(f,"%s , %s , %s , %s , %s , %s , %s , %s\n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8))&&(i!=*j))
{i++;}
  enigma_menu.btn_list[0] = initchoices(ch1, ch5, 0, 0, choice_W, choice_H);
  enigma_menu.btn_list[1] = initchoices(ch2, ch6, 200,150 , choice_W, choice_H);
  enigma_menu.btn_list[2] = initchoices(ch3, ch7, 350,300 , choice_W, choice_H);
  enigma_menu.btn_list[3] = initchoices(ch4, ch8, 500,450 , choice_W, choice_H);
fclose(f);
enigma_menu.t[0].position.x=200;
enigma_menu.t[0].position.y=600;
 
enigma_menu.t[0].textcolor.r=255;
enigma_menu.t[0].textcolor.g=0;
enigma_menu.t[0].textcolor.b=0;
enigma_menu.t[0].font =TTF_OpenFont("Fonts/Dancing.ttf",40);
enigma_menu.t[1].position.x=800;
enigma_menu.t[1].position.y=200;
 
enigma_menu.t[1].textcolor.r=255;
enigma_menu.t[1].textcolor.g=0;
enigma_menu.t[1].textcolor.b=0;
enigma_menu.t[1].font =TTF_OpenFont("Fonts/Dancing.ttf",40);
enigma_menu.t[3].position.x=200;
enigma_menu.t[3].position.y=100;
 
enigma_menu.t[3].textcolor.r=255;
enigma_menu.t[3].textcolor.g=0;
enigma_menu.t[3].textcolor.b=0;
enigma_menu.t[3].font =TTF_OpenFont("Fonts/Dancing.ttf",40);
  enigma_menu.active_choice = 4;
  

}





void display(SDL_Surface * screen,char ch[50]){
  displayBackgroundE(enigma_menu.bg, screen);
  display_enigma(screen);
enigma_menu.t[0].surfacetexte=TTF_RenderText_Solid(enigma_menu.t[0].font,"it's quizz time",enigma_menu.t[0].textcolor);
SDL_BlitSurface(enigma_menu.t[0].surfacetexte,NULL,screen,&enigma_menu.t[0].position);
enigma_menu.t[1].surfacetexte=TTF_RenderText_Solid(enigma_menu.t[1].font,ch,enigma_menu.t[1].textcolor);
SDL_BlitSurface(enigma_menu.t[1].surfacetexte,NULL,screen,&enigma_menu.t[1].position);
enigma_menu.t[3].surfacetexte=TTF_RenderText_Solid(enigma_menu.t[3].font,"choose the right answer",enigma_menu.t[1].textcolor);
SDL_BlitSurface(enigma_menu.t[3].surfacetexte,NULL,screen,&enigma_menu.t[3].position);
  SDL_Flip(screen);

}




void display_enigma(SDL_Surface* screen){
  for (int i = 0; i < enigma_menu.active_choice; i++){
    if (i == enigma_menu.current_choice){
      displaychoices(enigma_menu.btn_list[i],screen, 1);
      continue;
    }
    displaychoices(enigma_menu.btn_list[i],screen, 0);
  }
}



void onKeyDown_enigma(SDL_Event event, int * quit, SDL_Surface* screen, char ch[50] ,int *j){
  //int current_on_button;
  if ((event.key.keysym.sym == SDLK_DOWN) || (event.key.keysym.sym == SDLK_UP) ){
    animer(event.key.keysym.sym);
  }
else 
if (event.key.keysym.sym == SDLK_RETURN)
{

   choiceActive_enigma(quit,screen,ch,j);
  }
else if (event.key.keysym.sym == SDLK_ESCAPE)
{*quit=1;
change1=1;}
}



void animer(SDLKey key){
   if (key == SDLK_DOWN){
    if (enigma_menu.current_choice == enigma_menu.active_choice){
      enigma_menu.current_choice  = 0;

    } else {
      (enigma_menu.current_choice )++;
    }
  } else  {
    if (enigma_menu.current_choice  == -1){
      enigma_menu.current_choice  = enigma_menu.active_choice - 1;
    } else {
      (enigma_menu.current_choice )--;
    }
  }

  change1 = 1;
}

void update_enigma(SDL_Surface * screen,char ch[50]){
  
if (change1){


    display(screen,ch);
 SDL_Flip(screen);
    change1 = 0;
  }
}


void onMouseHover_enigma(int x, int y){

old_active1 = enigma_menu.current_choice;

  for (int i = 0; i < enigma_menu.active_choice; i++){
    if (isMouseOverchoice(x, y, enigma_menu.btn_list[i].rect.x,enigma_menu.btn_list[i].rect.y,enigma_menu.btn_list[i].rect.w,enigma_menu.btn_list[i].rect.h)){
      enigma_menu.current_choice = i;
      change1 = 1;
      return;
    }

  }
  enigma_menu.current_choice = -1;
  change1 = 1;
}




void choiceActive_enigma(int * quit,SDL_Surface * screen,char ch[50],int *j){

switch(*j)
{case 0:switch(enigma_menu.current_choice)
{ case 1: 
strcpy(ch,"you win");
//*quit=1;
change1=1;


break;
case 2 : 
strcpy(ch,"you lose");
//*quit=1;
change1=1;



break;
case 3 : 
strcpy(ch,"you lose");
//*quit=1;
change1=1;



break ;
}
break;
case 1:switch(enigma_menu.current_choice)
{ case 1: 
strcpy(ch,"you lose");
//*quit=1;
change1=1;


break;
case 2 : 
strcpy(ch,"you win");
//*quit=1;
change1=1;



break;
case 3 : 
strcpy(ch,"you lose");
//*quit=1;
change1=1;



break ;
}break;
case 2: switch(enigma_menu.current_choice)
{ case 1: 
strcpy(ch,"you win");
//*quit=1;
change1=1;


break;
case 2 : 
strcpy(ch,"you lose");
//*quit=1;
change1=1;



break;
case 3 : 
strcpy(ch,"you lose");
//*quit=1;
change1=1;



break ;
}
break;

 }
}





