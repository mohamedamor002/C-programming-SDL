#include "sound.h"


void initSound(char * path){
  if( SDL_Init(SDL_INIT_AUDIO) < 0)
    return;
  music = Mix_LoadWAV(path);
  Mix_PlayChannel(-1, music, 0);
}

void killMusic(){
  Mix_FreeChunk(music);
  Mix_CloseAudio();
}
