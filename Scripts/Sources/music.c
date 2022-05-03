#include "../Headers/music.h"

Mix_Music * music_game;

void initSound(char * path){
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
	    printf("%s", Mix_GetError());
    }
    music_game = Mix_LoadMUS(path)  ;
    Mix_PlayMusic(music_game,-1) ;
}

void updateVolume(float l){
    Mix_VolumeMusic(MIX_MAX_VOLUME * l);
}

void killMusic(){
    Mix_FreeMusic(music_game);
    Mix_CloseAudio();
}