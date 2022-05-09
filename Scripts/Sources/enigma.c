#include "../Headers/enigma.h"

int stringTointeger1(char * str)
{
    int temp = 0;
    for (int i = 0; i < strlen(str); i++) {
  
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get 
        // the integer value of the digit.
        temp = temp * 10 + ((int) str[i] - '0');
    }
    return temp;
}

void loadTextEnigmasFromFile(TextEnigma * e, int p_index){
    if (p_index == -1)
        p_index = 0;
    FILE *f; 
    f = fopen( "enigmas_text", "r");
    char count[10]; 
    fscanf(f, "%s\n", count);
    e->enigmasCount = stringTointeger1(count);
    for (int i = 0; i < e->enigmasCount; i++){
        char question[200];
        fscanf(f, "%s ", question);
        e->er[i] = 4;
        char right_index[10];
        fscanf(f, "%s\n", right_index);
        e->right[i] = stringTointeger1(right_index);
        e->question[i] = initText(question, (1916/2) * p_index + 10, 20, 255, 255, 0, "Fonts/Dancing.ttf", 50);
        for (int j = 0; j < e->er[i]; j++){
            char answer[200];
            if (j + 1 == e->er[i])
                fscanf(f, "%s\n", answer);
            else 
                fscanf(f, "%s ", answer);
            e->choices[i][j] = initText(answer, 100 +  (1916/2) * p_index, 350 +  (120 * j), 255, 255, 255, "Fonts/Dancing.ttf", 25);
            
        }
    }
}

void loadEnigmasFromFile(Enigma * e, int p_index){
    if (p_index == -1)
        p_index = 0;
    FILE *f; 
    f = fopen( "enigmas", "r");
    char count[10]; 
    fscanf(f, "%s\n", count);
    e->enigmasCount = stringTointeger1(count);
    for (int i = 0; i < e->enigmasCount; i++){
        char count_pics[10]; 
        fscanf(f, "%s\n", count_pics);
        e->er[i] = stringTointeger1(count_pics);
        char right_index[10];
        fscanf(f, "%s\n", right_index);
        e->right[i] = stringTointeger1(right_index);
        char question_path[50];
        fscanf(f, "%s ", question_path);
        e->question[i] = initButton((1916/2) * p_index, 0, 500, 122, question_path, question_path);
        for (int j = 0; j < e->er[i]; j++){
            char path1[50], path2[50];
            if (j + 1 == e->er[i])
                fscanf(f, "%s %s\n", path1, path2);
            else 
                fscanf(f, "%s %s ", path1, path2);
            e->choices[i][j] = initButton((1916/2) * p_index + (150 * j), 200, 150, 122, path1, path2);
        }
    }
}


Enigma initEnigma(int p_index){
    Enigma e;
    e.currentButton = -1;
    loadEnigmasFromFile(&e, p_index);
    if (p_index == -1) {
        e.bg = initButton(0,0, 1916, 916, "Media/Enigma/bg.png", "Media/Enigma/bg.png");
    } else {
        e.bg = initButton((1916 / 2) * p_index, 0, (1916 / 2), 916, "Media/Enigma/bg.png", "Media/Enigma/bg.png");
    }
    swapEnigma(&e);
    return e;
}

TextEnigma initTextEnigma(int p_index){
    TextEnigma e;
    e.currentButton = -1;
    loadTextEnigmasFromFile(&e, p_index);
    if (p_index == -1) {
        e.bg = initButton(0,0, 1916, 916, "Media/Enigma/bg.png", "Media/Enigma/bg.png");
    } else {
        e.bg = initButton((1916 / 2) * p_index, 0, (1916 / 2), 916, "Media/Enigma/bg.png", "Media/Enigma/bg.png");
    }
    swapTextEnigma(&e);
    return e;
}


void swapTextEnigma(TextEnigma * e){
    srand(time(NULL));
    e->currentEnigma =  rand() % e->enigmasCount;
}

void swapEnigma(Enigma * e){
    srand(time(NULL));
    e->currentEnigma =  rand() % e->enigmasCount;
}

void displayEnigma(Enigma e, SDL_Surface * screen){
    displayButton(e.bg, screen);
    displayButton(e.question[e.currentEnigma], screen); 
    for (int i = 0; i < e.er[e.currentEnigma]; i++){
        displayButton(e.choices[e.currentEnigma][i], screen); 
    }
}

void displayTextEnigma(TextEnigma e, SDL_Surface * screen){
    displayButton(e.bg, screen);
    display_text(&e.question[e.currentEnigma], screen); 
        for (int i = 0; i < e.er[e.currentEnigma]; i++){
        display_text(&e.choices[e.currentEnigma][i], screen); 
    }

}


void handleEnigmaEvents(SDL_Event event, int * game_loop, Enigma * e,  int * enigma_up){
    switch(event.type){
        case SDL_QUIT:
            *game_loop = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((e->currentButton != -1) && (e->currentButton == e->right[e->currentEnigma] - 1))
                *enigma_up = 2;
            else if ((e->currentButton != -1) && (e->currentButton != e->right[e->currentEnigma] - 1))
                *enigma_up = 3;
            break;
        case SDL_MOUSEMOTION:
            for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                if (checkButtonHover(e -> choices[e->currentEnigma][i], event.motion.x, event.motion.y))
                    e -> currentButton = i;
                else if (e->currentButton != i)
                    updateButtonState(e -> choices[e->currentEnigma][i], 0);
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    if (e -> currentButton == -1)
                        e -> currentButton = ((e -> er[e -> currentEnigma] )- 1); 
                    else 
                        e -> currentButton = e -> currentButton - 1;
                    for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                        if (i == e->currentButton)
                            updateButtonState(e -> choices[e->currentEnigma][i], 1);
                        else
                            updateButtonState(e -> choices[e->currentEnigma][i], 0);
                    break;
                case SDLK_RIGHT: 
                    if (e -> currentButton == (e -> er[e -> currentEnigma]) - 1)
                        e -> currentButton = 0; 
                    else 
                        e -> currentButton = e -> currentButton + 1;
                    for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                        if (i == e->currentButton)
                            updateButtonState(e -> choices[e->currentEnigma][i], 1);
                        else
                            updateButtonState(e -> choices[e->currentEnigma][i], 0);
                    break;
                case SDLK_RETURN:
                    if ((e->currentButton != -1) && (e->currentButton == e->right[e->currentEnigma] - 1))
                        *enigma_up = 2;
                    else if ((e->currentButton != -1) && (e->currentButton != e->right[e->currentEnigma] - 1))
                        *enigma_up = 3;
                    break;

            }

    }
}

void handleTextEnigmaEvents(SDL_Event event, int * game_loop, TextEnigma * e,  int * enigma_up){
    switch(event.type){
        case SDL_QUIT:
            *game_loop = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((e->currentButton != -1) && (e->currentButton == e->right[e->currentEnigma] - 1))
                *enigma_up = 2;
            else if ((e->currentButton != -1) && (e->currentButton != e->right[e->currentEnigma] - 1))
                *enigma_up = 3;
            break;
        case SDL_MOUSEMOTION:
            for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                if (checkTextHover(&e -> choices[e->currentEnigma][i], event.motion.x, event.motion.y))
                    e -> currentButton = i;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_UP:
                    if (e -> currentButton == -1)
                        e -> currentButton = ((e -> er[e -> currentEnigma] )- 1); 
                    else 
                        e -> currentButton = e -> currentButton - 1;
                    for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                        if (i == e->currentButton){
                            e -> choices[e->currentEnigma][i].color.r = 255;
                            e -> choices[e->currentEnigma][i].color.g = 0;
                            e -> choices[e->currentEnigma][i].color.b = 0;
                        }
                        else
                            {
                            e -> choices[e->currentEnigma][i].color.r = 255;
                            e -> choices[e->currentEnigma][i].color.g = 255;
                            e -> choices[e->currentEnigma][i].color.b = 255;
                        }
                    break;
                case SDLK_DOWN: 
                    if (e -> currentButton == (e -> er[e -> currentEnigma]) - 1)
                        e -> currentButton = 0; 
                    else 
                        e -> currentButton = e -> currentButton + 1;
                    for (int i = 0; i< e -> er[e -> currentEnigma]; i++)
                        if (i == e->currentButton){
                            e -> choices[e->currentEnigma][i].color.r = 255;
                            e -> choices[e->currentEnigma][i].color.g = 0;
                            e -> choices[e->currentEnigma][i].color.b = 0;
                        }
                        else
                            {
                            e -> choices[e->currentEnigma][i].color.r = 255;
                            e -> choices[e->currentEnigma][i].color.g = 255;
                            e -> choices[e->currentEnigma][i].color.b = 255;
                        }
                    break;
                case SDLK_RETURN:
                    if ((e->currentButton != -1) && (e->currentButton == e->right[e->currentEnigma] - 1))
                        *enigma_up = 2;
                    else if ((e->currentButton != -1) && (e->currentButton != e->right[e->currentEnigma] - 1))
                        *enigma_up = 3;
                    break;

            }
    }
}





