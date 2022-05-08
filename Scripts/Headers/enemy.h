#include "minimap.h"



typedef struct {
  SDL_Rect pos;
  SDL_Surface * pic[8];
  int active_pic; //which image is being displaying
  int direction; //in which direction is the enemy moving 0 for right and 1 for left
  int state; //dead or alive 0 if dead and 1 if alive
  int TotalNumber; //of the enemy picture
}
Enemy;


void liberateEnemy(Enemy E);
void initEnemy(Enemy * E , int p_index);
void displayEnemy(Enemy E, SDL_Surface * screen);
void animateEnemy(Enemy * E);
void updateWithBackground(Enemy * E, int cx, int lx, int dir, int index);
void moveEnemy(Enemy * E, int index);
int CollisonBB(player P, Enemy E);
void checkcollision(player * P, Enemy E);
void moveIA(player * P, Enemy * E);