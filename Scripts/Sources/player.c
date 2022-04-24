#include "../Headers/player.h"

static int multi = 0;

void initPlayerSingle(player * p) {
  multi = 0;
  p -> multi = 0;
  p -> spritesheet = IMG_Load("Media/Player/perso.png");

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

  p -> s =  init_score(0);
  p -> l =  init_life(0);

}

void initPlayerMulti(player * p, int p_index) {
  multi = 1;
  p -> multi = 1;
  p -> spritesheet = IMG_Load("Media/Player/perso.png");

  p -> pos.x = p_index == 0 ? 50 : 50 + ( (int) 1916 / 2) ;
  p -> pos.y = 490;

  p -> direction = 2; // right

  p -> acceleration = 0;
  p -> speed = 0;
  p -> speedV = 0;

  p -> pos_sprite.x = 0;
  p -> pos_sprite.y = 200;
  p -> pos_sprite.h = 100;
  p -> pos_sprite.w = 100;

  p -> s =  init_score(p_index);
  p -> l =  init_life(p_index);

}



void displayplayer(player p, SDL_Surface * screen) {
  SDL_BlitSurface(p.spritesheet, & p.pos_sprite, screen, & p.pos);
}

void moveplayer(player * p, int dt) {
  double dx;
  dx = 0.5 * p -> acceleration * dt * dt + p -> speed * dt;
  if (p -> direction == 0) // || (p->direction==2)
  {
    if ((multi = 1 && p->pos.x >= 1916 / 4) || (!multi && p->pos.x >= 1916 / 2))
        return; 
    p -> pos.x += dx;
  } else if (p -> direction == 1) {
    if ((multi = 1 && p->pos.x <= 50) || (!multi && p->pos.x <= 50))
        return;
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

void update_player(player * p, int right, int left, int up) {
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
void check(player * p, int dir1, int * up ) {
  if ((p -> speed == 0) && (p -> acceleration == 0)) {
    p -> direction = dir1; //MEMORIZATION OF THE DIRECTION OF THE player 1
  }

  p -> pos.y += p -> speedV;
  p -> speedV += 10;
  if (p -> pos.y >= 490) {
    p -> speedV = 0; //THE player 1 GO BACK DOWN ALONE
    p -> pos.y = 490;
    *up = 0;
  }
}
score init_score(int p_index) {
  score s;
  s.font = TTF_OpenFont("Fonts/Dancing.ttf", 25);
  s.white.r = 0;
  s.white.g = 0;
  s.white.b = 0;
  s.texte1 = TTF_RenderText_Blended(s.font, "SCORE :", s.white);
  s.position_textt.y = 20;
  if (!multi){
    s.position_textt.x = 590;
  } else {
    s.position_textt.x = 590 + ((1916 / 2) * p_index );
  }
  return s;

}
void manage_score(player * p, int p_index) {

  strcpy(p->s.number, "");
  p->s.value_score += 1; // p.value_score=p.value_score+1;
  sprintf(p->s.number, "%d", (p->s.value_score)); // converion of an integer into a string of characters

  p->s.number1 = TTF_RenderText_Blended(p->s.font, p->s.number, p->s.white);

  p->s.position_number.y = 20;
  if (!p->multi){
    p->s.position_number.x = 700;
  } else {
    p->s.position_number.x = 700 + ((1916 / 2) * p_index );
  }

}

life init_life(int p_index) {
  life l;
  l.text = TTF_OpenFont("Fonts/Dancing.ttf", 25);
  l.color.r = 0;
  l.color.g = 0;
  l.color.b = 0;
  l.texte = TTF_RenderText_Blended(l.text, "LIVES", l.color);
  l.position_text.y = 60;

  /*LIFE player 1*/
  l.image_life[0] = IMG_Load("Media/Game/heart3.png");
  l.image_life[1] = IMG_Load("Media/Game/heart2.png");
  l.image_life[2] = IMG_Load("Media/Game/heart1.png");
  l.image_life[3] = IMG_Load("Media/Game/heart0.png");
  /* POSITION OF LIFE1*/
  if (!multi){
    l.position_text.x = 670;
    l.position_life.x = 590;
  } else {
    l.position_text.x = 670 + ((1916 / 2) * p_index );
    l.position_life.x = 590 + ((1916 / 2) * p_index );
  }

  l.position_life.y = 42;
  l.val = 4;
  return l;

}
void manage_life(life * l) {
  if (  l->val == 3) {
    SDL_FreeSurface(l -> image_life[3]);
  } else if (  l->val == 2) {
    SDL_FreeSurface(l -> image_life[0]);
  } else if (  l->val == 1) {
    SDL_FreeSurface(l -> image_life[1]);
  } else if (  l->val == 0) {
    SDL_FreeSurface(l -> image_life[2]);
  }
}
void display_all(player p, SDL_Surface * screen) {
  SDL_BlitSurface(p.l.image_life[p.l.val > 0 ? p.l.val - 1 : 0], NULL, screen, ( & p.l.position_life));
  SDL_BlitSurface(p.l.texte, NULL, screen, & (p.l.position_text));
  SDL_BlitSurface(p.s.texte1, NULL, screen, & p.s.position_textt);
  SDL_BlitSurface(p.s.number1, NULL, screen, & p.s.position_number);
}