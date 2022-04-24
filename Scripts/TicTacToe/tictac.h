/**
 * @file main.c
 * @author Ahmed Debbech
 * @brief The main entry point to the program, all the function calls are here.
 */
#include <stdio.h>

#include <stdlib.h>

#include "SDL/SDL_image.h"

#include "SDL/SDL.h"

#include "SDL/SDL_mixer.h"

#include "SDL/SDL_ttf.h"

#include <string.h>


#include "graphics.h"

#include "store.h"

#include "core.h"

int initTicTacToe(SDL_Surface * screen, int * tiktakon);