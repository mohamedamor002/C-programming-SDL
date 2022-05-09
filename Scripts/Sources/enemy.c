#include "../Headers/enemy.h"

int posMax = 700;
int posMin = 300;


void initEnemy(Enemy * E, int p_index) {
  E -> pic[0] = IMG_Load("Media/Enemy/stand1.png");
  E -> pic[1] = IMG_Load("Media/Enemy/right4.png");
  E -> pic[2] = IMG_Load("Media/Enemy/right5.png");
  E -> pic[3] = IMG_Load("Media/Enemy/right6.png");
  E -> pic[4] = IMG_Load("Media/Enemy/left4.png");
  E -> pic[5] = IMG_Load("Media/Enemy/left5.png");
  E -> pic[6] = IMG_Load("Media/Enemy/left6.png");
  E -> pic[7] = IMG_Load("Media/Enemy/dead1.png");
  if ((E -> pic[0] == NULL)) {
    printf("There has been an error. \n");
  } else {
    E -> pos.x = 580 + (1916 / 2) * p_index;
    E -> pos.y = 490;
    E -> pos.w = 0;
    E -> pos.h = 0;
    E -> active_pic = 0;
    E -> state = 1;
    E -> direction = 0;
    E -> TotalNumber = 8;
  }
}

void liberateEnemy(Enemy E) {
  int i;
  for (i = 0; i < E.TotalNumber; i++) SDL_FreeSurface(E.pic[i]);
}

void displayEnemy(Enemy E, SDL_Surface * screen) //dipslay picture
{
  if (E.state == 1) {
    SDL_BlitSurface(E.pic[E.active_pic], NULL, screen, & E.pos);
  } else {
    SDL_BlitSurface(E.pic[7], NULL, screen, & E.pos);
  }
}

void moveEnemy(Enemy * E, int index) {
  if (E -> pos.x > posMax + (1916 / 2) * index) {
    E -> direction = 1;
  }
  if (E -> pos.x < posMin + (1916 / 2) * index) {
    E -> direction = 0;
  }
  if (E -> direction == 0) {
    E -> pos.x++;
  } else {
    E -> pos.x--;
  }
}

void updateWithBackground(Enemy * E, int cx, int lx, int dir, int index){
    if (cx == lx)
      return;
    if (dir == 0){
        posMin += abs(cx - lx);
        posMax -= abs(cx - lx); 
        E->pos.x -= abs(cx - lx); 
      } else {
        posMin -= abs(cx - lx);
        posMax += abs(cx - lx); 
        E->pos.x += abs(cx - lx); 
    }     
    if (index == 1){
      if (dir == 0 && E->pos.x <= 1916/2 && E->pos.x > 0)
        E->pos.x = -200;
      else if (dir == 1 && E->pos.x > -10)
        E->pos.x = 1916/2;
    }
    if (E->pos.x > 3000 || E->pos.x < -3000){
      if (dir == 1){
        posMax = 400 + (1916 / 2) * index;
        posMin = 0 + (1916 / 2) * index;
        E->pos.x = (1916 / 2) * index;
      } else if (dir == 0){
        posMax = (1916 / 2) * index;
        posMin = (1916 / 2) * index - 400;
        E->pos.x =  (1916/2) + (1916 / 2) * index;
      }
    }
}


void animateEnemy(Enemy * E) {
  if (E -> direction == 0) {
    if (E -> active_pic < 3) {
      E -> active_pic++;
    } else {
      E -> active_pic = 1;
    }
  }
  if (E -> direction == 1) {
    if ((E -> active_pic < 4) || (E -> active_pic == 6)) {
      E -> active_pic = 4;
    } else {
      E -> active_pic++;
    }
  }
}

int CollisonBB(player P, Enemy E) {
  int collision;
  if ( ((P.pos.x >= E.pos.x - abs(P.speed) * 2) && (P.pos.x <= abs(P.speed) * 2 + E.pos.x + E.pos.w)) || ((P.pos.x + P.pos.w >= E.pos.x - abs(P.speed) * 2) &&  (P.pos.x + P.pos.w < abs(P.speed) * 2 + E.pos.x + E.pos.w) ) ) {
    if ((P.pos.y >= E.pos.y) || (P.pos.y + P.pos.h >= E.pos.y))
      collision = 1;
  } else {
    collision = 0;
  }
  return collision;
}


void checkcollision(player * P, Enemy E) //P is the player who will look dead if there is a collision 
{
  int collision;
  collision = CollisonBB( * P, E);
  if (collision == 1) {
    P -> s . value_score -= 500;
    if (P->enigma_up != 1)
      P->enigma_up = 1;
    if (P -> nb == 0)
      P -> pos.x = 50;
    else 
      P -> pos.x = (1916/2) + 50;
    }
}

void moveIA(player * P, Enemy * E){
  if ((P->pos.x >= posMin) && (P->pos.x <= posMax))
    if (P->pos.x - E ->pos.x > 0)
      E -> direction = 0;
    else if (P->pos.x - E ->pos.x <= 0)
      E -> direction = 1;
}