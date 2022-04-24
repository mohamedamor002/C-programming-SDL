#include "../Headers/music.h"

Mix_Music * music;


void initSound(char * path){
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
	    printf("%s", Mix_GetError());
    }
    music = Mix_LoadMUS(path)  ;
    Mix_PlayMusic(music,-1) ;
}

void updateVolume(float l){
    Mix_VolumeMusic(MIX_MAX_VOLUME * l);
}

void killMusic(){
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}