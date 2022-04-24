#include "../../Headers/Enigma/enigmatext.h"

void Init_Enigma_text(Enigma * e, char * filename) {
  int length_question, length_answer_1, length_answer_2, length_answer_3, length_answer_4, length_correct_answer;
  int i = 0, randomvalue;
  FILE * f;
  f = fopen(filename, "r");
  srand(time(NULL));
  randomvalue = (rand() % (3));
  while ((fscanf(f, "%s %s %s %s %s %s\n", e -> t[0].text, e -> t[1].text, e -> t[2].text, e -> t[3].text, e -> t[4].text, e -> correctanswer)) && (randomvalue != i)) {
    i++;

  }

  length_question = strlen(e -> t[0].text);
  length_answer_1 = strlen(e -> t[1].text);
  length_answer_2 = strlen(e -> t[2].text);
  length_answer_3 = strlen(e -> t[3].text);
  length_answer_4 = strlen(e -> t[4].text);
  length_correct_answer = strlen(e -> correctanswer);

  for (i = 0; i < length_question; i++) {
    if (e -> t[0].text[i] == 95) {
      e -> t[0].text[i] = 32;
    }
  }

  for (i = 0; i < length_answer_1; i++) {
    if (e -> t[1].text[i] == 95) {
      e -> t[1].text[i] = 32;
    }
  }

  for (i = 0; i < length_answer_2; i++) {
    if (e -> t[2].text[i] == 95) {
      e -> t[2].text[i] = 32;
    }
  }

  for (i = 0; i < length_answer_3; i++) {
    if (e -> t[3].text[i] == 95) {
      e -> t[3].text[i] = 32;
    }
  }

  for (i = 0; i < length_answer_4; i++) {
    if (e -> t[4].text[i] == 95) {
      e -> t[4].text[i] = 32;
    }
  }

  for (i = 0; i < length_correct_answer; i++) {
    if (e -> correctanswer[i] == 95) {
      e -> correctanswer[i] = 32;
    }
  }

  // *********init question
  e -> t[0].position.x = 30;
  e -> t[0].position.y = 100;
  e -> t[0].textcolor.r = 255;
  e -> t[0].textcolor.g = 0;
  e -> t[0].textcolor.b = 0;
  e -> t[0].font = TTF_OpenFont("trajan.ttf", 32);

  // *********init answer1
  e -> t[1].position.x = 300;
  e -> t[1].position.y = 300;

  e -> t[1].textcolor.r = 200;
  e -> t[1].textcolor.g = 100;
  e -> t[1].textcolor.b = 155;
  e -> t[1].font = TTF_OpenFont("trajan.ttf", 35);
  e -> t[1].surfacetexte = TTF_RenderText_Solid(e -> t[1].font, e -> t[1].text, e -> t[1].textcolor);
  // *********init answer2
  e -> t[2].position.x = 600;
  e -> t[2].position.y = 300;

  e -> t[2].textcolor.r = 200;
  e -> t[2].textcolor.g = 100;
  e -> t[2].textcolor.b = 155;
  e -> t[2].font = TTF_OpenFont("trajan.ttf", 35);
  e -> t[2].surfacetexte = TTF_RenderText_Solid(e -> t[2].font, e -> t[2].text, e -> t[2].textcolor);
  // *********init answer3
  e -> t[3].position.x = 300;
  e -> t[3].position.y = 500;

  e -> t[3].textcolor.r = 200;
  e -> t[3].textcolor.g = 100;
  e -> t[3].textcolor.b = 155;
  e -> t[3].font = TTF_OpenFont("trajan.ttf", 35);
  e -> t[3].surfacetexte = TTF_RenderText_Solid(e -> t[3].font, e -> t[3].text, e -> t[3].textcolor);
  // *********init answer4
  e -> t[4].position.x = 600;
  e -> t[4].position.y = 500;

  e -> t[4].textcolor.r = 200;
  e -> t[4].textcolor.g = 100;
  e -> t[4].textcolor.b = 155;
  e -> t[4].font = TTF_OpenFont("trajan.ttf", 35);
  e -> t[4].surfacetexte = TTF_RenderText_Solid(e -> t[4].font, e -> t[4].text, e -> t[4].textcolor);
  //**********inti text animation 
  e -> w.position.x = 50;
  e -> w.position.y = 800;

  e -> w.fontColor.r = 200;
  e -> w.fontColor.g = 100;
  e -> w.fontColor.b = 155;
  e -> w.fontTest = TTF_OpenFont("trajan.ttf", 35);
  sprintf(e -> w.timeText, "%d", SDL_GetTicks());
  //e->w.stopwatch=TTF_RenderText_Blended(e->w.fontColor,e->w.timeText,e->w.fontColor);

}

//*************display enigma
void display_Enigma_text(Enigma e, SDL_Surface * screen) {
  //question
  e.t[0].surfacetexte = TTF_RenderText_Solid(e.t[0].font, e.t[0].text, e.t[0].textcolor);
  SDL_BlitSurface(e.t[0].surfacetexte, NULL, screen, & e.t[0].position);
  //answer1
  e.t[1].surfacetexte = TTF_RenderText_Solid(e.t[1].font, e.t[1].text, e.t[1].textcolor);
  SDL_BlitSurface(e.t[1].surfacetexte, NULL, screen, & e.t[1].position);
  //answer2
  e.t[2].surfacetexte = TTF_RenderText_Solid(e.t[2].font, e.t[2].text, e.t[2].textcolor);
  SDL_BlitSurface(e.t[2].surfacetexte, NULL, screen, & e.t[2].position);
  //answer3
  e.t[3].surfacetexte = TTF_RenderText_Solid(e.t[3].font, e.t[3].text, e.t[3].textcolor);
  SDL_BlitSurface(e.t[3].surfacetexte, NULL, screen, & e.t[3].position);
  //answer4
  e.t[4].surfacetexte = TTF_RenderText_Solid(e.t[4].font, e.t[4].text, e.t[4].textcolor);
  SDL_BlitSurface(e.t[4].surfacetexte, NULL, screen, & e.t[4].position);
  //time animation

  // SDL_BlitSurface(e.w.stopwatch,NULL,screen,&e.w.position);
}

// optional********1
void load_enigma_text_background(Enigma * e) { //backg 
  e -> image[0].img = IMG_Load("Media/Enigma/bg.png");
  if (e -> image[0].img == NULL) {
    printf("Unable to load background: %s\n", SDL_GetError());
    return;
  }
  e -> image[0].pos.x = 0;
  e -> image[0].pos.y = 0;

  e -> image[0].pos.w = 1000;
  e -> image[0].pos.h = 780;
}
void display_enigma_text_background(Enigma e, SDL_Surface * screen) {
  SDL_BlitSurface(e.image[0].img, NULL, screen, & e.image[0].pos);
}
void load_win_image_enigma_text(Enigma * e) { //backg 
  e -> image[1].img = IMG_Load("win.jpg");
  if (e -> image[0].img == NULL) {
    printf("Unable to load background: %s\n", SDL_GetError());
    return;
  }
  e -> image[1].pos.x = 450;
  e -> image[1].pos.y = 550;

  e -> image[1].pos.w = 400;
  e -> image[1].pos.h = 225;
}
void display_win_image_enigma_text(Enigma e, SDL_Surface * screen) {
  SDL_BlitSurface(e.image[1].img, NULL, screen, & e.image[1].pos);
}

void load_lose_image_enigma_text(Enigma * e) { //backg 
  e -> image[2].img = IMG_Load("lose.jpeg");
  if (e -> image[2].img == NULL) {
    printf("Unable to load background: %s\n", SDL_GetError());
    return;
  }
  e -> image[2].pos.x = 450;
  e -> image[2].pos.y = 550;

  e -> image[2].pos.w = 400;
  e -> image[2].pos.h = 224;
}
void display_lose_image_enigma_text(Enigma e, SDL_Surface * screen) {
  SDL_BlitSurface(e.image[2].img, NULL, screen, & e.image[2].pos);
}

//***********mouse motion 
int isMouseOvertext_enigma_text(int mouse_x, int mouse_y, int entity_x, int entity_y, int entity_w, int entity_h) {
  printf("%d %d\n", mouse_x, mouse_y);

  if ((mouse_x >= entity_x) && (mouse_x <= entity_x + entity_w)) {
    if ((mouse_y >= entity_y) && (mouse_y <= entity_y + entity_h)) {
      return 1;
    }
  }
  return 0;
}

void printbutton_enigma_text(Enigma * e, SDL_Event event, int * change, SDL_Surface * screen, int * done) {
  int i;
  if (event.key.keysym.sym == SDLK_DOWN) {
    current_text_on_1_enigma(e, change);
  } else
  if (event.key.keysym.sym == SDLK_UP) {
    current_text_on_2_enigma(e, change);
  } else
  if (event.key.keysym.sym == SDLK_RETURN) {

    display_win_lose_enigma_text(e, screen, * change);

  } else if (event.key.keysym.sym == SDLK_ESCAPE) {
    ( * done) = 2;
  }
}

void current_text_on_1_enigma(Enigma * e, int * change) {
  if (( * change) == 0)
    e -> current_text_on++;
  if (e -> current_text_on == 0) {
    e -> t[1].textcolor.r = 0;
    e -> t[4].textcolor.r = 200;
    e -> t[2].textcolor.r = 200;
    e -> t[3].textcolor.r = 200;
  } else
  if (e -> current_text_on == 1) {
    e -> t[2].textcolor.r = 0;
    e -> t[1].textcolor.r = 200;
    e -> t[4].textcolor.r = 200;
    e -> t[3].textcolor.r = 200;
  } else
  if (e -> current_text_on == 2) {
    e -> t[3].textcolor.r = 0;
    e -> t[1].textcolor.r = 200;
    e -> t[4].textcolor.r = 200;
    e -> t[2].textcolor.r = 200;
  } else
  if (e -> current_text_on == 3) {
    e -> t[4].textcolor.r = 0;
    e -> t[1].textcolor.r = 200;
    e -> t[3].textcolor.r = 200;
    e -> t[2].textcolor.r = 200;
  }

  e -> current_text_on++;
  if (e -> current_text_on >= 4)
    e -> current_text_on = 0;
  ( * change) = 1;

}
void current_text_on_2_enigma(Enigma * e, int * change) {
  if (( * change) == 1)
    e -> current_text_on--;
  if (e -> current_text_on == 0) {
    e -> t[1].textcolor.r = 200;
    e -> t[4].textcolor.r = 0;
    e -> t[2].textcolor.r = 200;
    e -> t[3].textcolor.r = 200;
  } else
  if (e -> current_text_on == 1) {
    e -> t[2].textcolor.r = 200;
    e -> t[1].textcolor.r = 0;
    e -> t[4].textcolor.r = 200;
    e -> t[3].textcolor.r = 200;
  } else
  if (e -> current_text_on == 2) {
    e -> t[3].textcolor.r = 200;
    e -> t[1].textcolor.r = 200;
    e -> t[4].textcolor.r = 200;
    e -> t[2].textcolor.r = 0;
  } else
  if (e -> current_text_on == 3) {
    e -> t[4].textcolor.r = 200;
    e -> t[1].textcolor.r = 200;
    e -> t[3].textcolor.r = 0;
    e -> t[2].textcolor.r = 200;
  }
  e -> current_text_on--;
  if (e -> current_text_on <= -1)
    e -> current_text_on = 3;
  ( * change) = 0;

}

void mouse_motion_enigma_text(Enigma * e, int texton[], SDL_Event event) {
  int i, length_answer_1, length_answer_2, length_answer_3, length_answer_4;
  length_answer_1 = 15 * strlen(e -> t[1].text);
  length_answer_2 = 15 * strlen(e -> t[2].text);
  length_answer_3 = 15 * strlen(e -> t[3].text);
  length_answer_4 = 15 * strlen(e -> t[4].text);
  texton[0] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 300, 300, length_answer_1, 50);
  texton[1] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 600, 300, length_answer_2, 50);
  texton[2] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 300, 500, length_answer_3, 50);
  texton[3] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 600, 500, length_answer_4, 50);

  for (i = 1; i < 5; i++) {
    if (texton[i - 1] == 1)
      e -> t[i].textcolor.r = 44;
    else if (texton[i - 1] == 0)
      e -> t[i].textcolor.r = 200;
  }

}

void display_win_lose_enigma_text(Enigma * e, SDL_Surface * screen, int change) {
  int i;
  if ((e -> current_text_on == 0) && (change == 1) && (strcmp(e -> t[4].text, e -> correctanswer) == 0)) {
    load_win_image_enigma_text(e);
    display_win_image_enigma_text( * e, screen);
  } else
  if ((e -> current_text_on == 0) && (change == 1) && (strcmp(e -> t[4].text, e -> correctanswer) != 0)) {
    load_lose_image_enigma_text(e);
    display_lose_image_enigma_text( * e, screen);
  }
  for (i = 1; i < 5; i++) {
    if ((e -> current_text_on == i) && (change == 1) && (strcmp(e -> t[i].text, e -> correctanswer) == 0)) {
      load_win_image_enigma_text(e);
      display_win_image_enigma_text( * e, screen); // display win image
    } else
    if ((e -> current_text_on == i - 1) && (change == 0) && (strcmp(e -> t[i].text, e -> correctanswer) == 0)) {
      load_win_image_enigma_text(e);
      display_win_image_enigma_text( * e, screen); // display win image
    } else
    if ((e -> current_text_on == i) && (change == 1) && (strcmp(e -> t[i].text, e -> correctanswer) != 0)) {
      load_lose_image_enigma_text(e);
      display_lose_image_enigma_text( * e, screen);
    } else
    if ((e -> current_text_on == i - 1) && (change == 0) && (strcmp(e -> t[i].text, e -> correctanswer) != 0)) {
      load_lose_image_enigma_text(e);
      display_lose_image_enigma_text( * e, screen);
    }
  }

}
void mouse_button_up_enigma_text(Enigma e, int texton[], SDL_Event event, SDL_Surface * screen) {
  int i, length_answer_1, length_answer_2, length_answer_3, length_answer_4;
  length_answer_1 = 15 * strlen(e.t[1].text);
  length_answer_2 = 15 * strlen(e.t[2].text);
  length_answer_3 = 15 * strlen(e.t[3].text);
  length_answer_4 = 15 * strlen(e.t[4].text);
  texton[0] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 300, 300, length_answer_1, 50);
  texton[1] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 600, 300, length_answer_2, 50);
  texton[2] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 300, 500, length_answer_3, 50);
  texton[3] = isMouseOvertext_enigma_text(event.motion.x, event.motion.y, 600, 500, length_answer_4, 50);

  for (i = 1; i < 5; i++) {
    if ((texton[i - 1] == 1) && (strcmp(e.t[i].text, e.correctanswer) == 0)) {
      load_win_image_enigma_text( & e);
      display_win_image_enigma_text(e, screen);
    } else
    if ((texton[i - 1] == 1) && (strcmp(e.t[i].text, e.correctanswer) != 0)) {
      load_lose_image_enigma_text( & e);
      display_lose_image_enigma_text(e, screen);
    }
  }
}