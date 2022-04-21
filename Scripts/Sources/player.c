#include "player.h"


void initplayer(player * p) {
  p -> spritesheet = IMG_Load("../../Media/Player/perso.png");

  p -> pos.x = 50;
  p -> pos.y = 490;

  p -> direction = 2; // right

  p -> acceleration = 0;
  p -> speed = 0;
  p -> speedV = 0;

  p -> pos_sprite.x = 0;
  p -> pos_sprite.y = 200;
  p -> pos_sprite.h = 100;
  p -> pos_sprite.w = 100;
}

void displayplayer(player p, SDL_Surface * screen) {
  SDL_BlitSurface(p.spritesheet, & p.pos_sprite, screen, & p.pos);
}

void moveplayer(player * p, int dt) {
  double dx;
  dx = 0.5 * p -> acceleration * dt * dt + p -> speed * dt;
  if (p -> direction == 0) // || (p->direction==2)
  {
    p -> pos.x += dx;
  } else if (p -> direction == 1) {
    p -> pos.x -= dx;
  }
}

void animeplayer(player * p) {
  p -> pos_sprite.x += 100;
  if (p -> pos_sprite.x >= 1500) {
    p -> pos_sprite.x = 0;
  }
  p -> pos_sprite.y = p -> direction * 100;
}

void jump(player * p) {
  if (p -> pos.y == 490) {
    p -> speedV = -50;
  }
}

void update(player * p, int right, int left, int up) {
  if (right == 1) {
    p -> speed = 10;
    p -> acceleration += 0.5;
    p -> direction = 0;
  }
  if (left == 1) {
    p -> speed = 10;
    p -> acceleration += 0.5;
    p -> direction = 1;
  }
  if (up == 1) {
    jump(p);
  }
}

void update_acceleration(player * p) {

  p -> acceleration -= 0.3;

  if (p -> acceleration < 0) {
    p -> acceleration = 0;
  }

  if (p -> acceleration > 4) {
    p -> acceleration = 4;
  }

}
void check(player * p, int dir1) {

  if ((p -> speed == 0) && (p -> acceleration == 0)) {
    p -> direction = dir1; //MEMORIZATION OF THE DIRECTION OF THE player 1
  }

  p -> pos.y += p -> speedV;
  p -> speedV += 10;
  if (p -> pos.y >= 490) {
    p -> speedV = 0; //THE player 1 GO BACK DOWN ALONE
    p -> pos.y = 490;
  }
}
score init_score() {
  score s;
  s.font = TTF_OpenFont("Fonts/Dancing.ttf", 25);
  s.white.r = 255;
  s.white.g = 255;
  s.white.b = 255;
  s.texte1 = TTF_RenderText_Blended(s.font, "SCORE :", s.white);
  s.position_textt.x = 15;
  s.position_textt.y = 20;
  return s;

}
void manage_score(score * s) {

  s -> number[20];
  s -> value_score = 99999; // p.value_score=p.value_score+1;
  sprintf(s -> number, "%d", (s -> value_score)); // converion of an integer into a string of characters

  s -> number1 = TTF_RenderText_Blended(s -> font, s -> number, s -> white);

  s -> position_number.x = 170;
  s -> position_number.y = 20;
  TTF_CloseFont(s -> font);

}

life init_life() {
  life l;
  l.text = TTF_OpenFont("Fonts/Dancing.ttf", 25);
  l.color.r = 255;
  l.color.g = 255;
  l.color.b = 255;
  l.texte = TTF_RenderText_Blended(l.text, "LIVES", l.color);
  l.position_text.x = 670;
  l.position_text.y = 20;
  TTF_CloseFont(l.text);

  /*LIFE player 1*/
  l.image_life[0] = IMG_Load("outils/heart3.png");
  l.image_life[1] = IMG_Load("outils/heart2.png");
  l.image_life[2] = IMG_Load("outils/heart1.png");
  l.image_life[3] = IMG_Load("outils/heart0.png");
  /* POSITION OF LIFE1*/
  l.position_life.x = 590;
  l.position_life.y = 1;
  l.val = 4;
  return l;

}
void manage_life(life * l, int * lifes) {
  ( * lifes) --;
  (l -> val) --;
  if ( * lifes == 3) {
    SDL_FreeSurface(l -> image_life[3]);
  } else if ( * lifes == 2) {
    SDL_FreeSurface(l -> image_life[0]);
  } else if ( * lifes == 1) {
    SDL_FreeSurface(l -> image_life[1]);
  } else if ( * lifes == 0) {
    SDL_FreeSurface(l -> image_life[2]);
  }

}
void display_all(life l, score s, SDL_Surface * screen) {
  SDL_BlitSurface(l.image_life[l.val], NULL, screen, ( & l.position_life));
  SDL_BlitSurface(l.texte, NULL, screen, & (l.position_text));
  SDL_BlitSurface(s.texte1, NULL, screen, & s.position_textt);
  SDL_BlitSurface(s.number1, NULL, screen, & s.position_number);
  SDL_Delay(50);
}