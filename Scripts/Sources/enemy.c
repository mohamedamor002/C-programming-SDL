#include "../Headers/enemy.h"

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
  if ((P.pos.w + P.pos.x < E.pos.x) || (P.pos.x > E.pos.x + E.pos.w) || (P.pos.h + P.pos.y < E.pos.y) || (P.pos.y > E.pos.y + E.pos.h)) {
    collision = 0;
  } else {
    collision = 1;
  }
  return collision;
}


void checkcollision(player * P, Enemy E) //P is the player who will look dead if there is a collision 
{
  int collision;
  collision = CollisonBB( * P, E);
  if ((collision == 1)) {
    P -> l.val -- ;
	P -> s . value_score -= 500;
    P -> pos.x = 50;
  }
}