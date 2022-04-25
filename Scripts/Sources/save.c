#include "../Headers/save.h"

int stringTointeger(char * str)
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

int addToSaved(saved * s, char * name, int score, int xcam, int xp){
    int found = -1; 
    for (int i = 0; i < s->nb_saves; i++ ){
        if (strcmp(s->names[i], name) == 0){
            found = i; 
            break;
        }
    }
    if (found == -1){
        found = s->nb_saves;   
        s->nb_saves++;
    }    
    strcpy(s->names[found], name);
    s->scores[found] = score;
    s->xcam[found] = xcam;
    s->xpos[found] = xp;
    
    if (found == -1)
        return 0;
    else 
        return 1;
}


void save(saved * s, char * name, int score, int xcam, int xp){
    int found = addToSaved(s, name, score, xcam, xp);
    remove("save");
    FILE * fp;
    fp = fopen("save", "w");
    fprintf(fp, "%d\n", s->nb_saves);
    for (int i = 0; i < s->nb_saves; i++){
        fprintf(fp, "%s %d %d %d\n", s->names[i], s->scores[i], s->xcam[i], s->xpos[i]);
    }
    fclose(fp);
}

saved load(){
    FILE *f;
    saved s;
    s.nb_saves = 0;
    char xcc[50];
    char xpc[50];
    char score[50];
    char nb_acc[50];
    f = fopen ("save", "r");
    fscanf(f, "%s\n", nb_acc);
    int i = stringTointeger(nb_acc);
    do {
        fscanf(f, "%s %s %s %s\n", s.names[s.nb_saves], score, xcc, xpc);
        s.scores[s.nb_saves] = stringTointeger(score);
        s.xcam[s.nb_saves] = stringTointeger(xcc);
        s.xpos[s.nb_saves] = stringTointeger(xpc);
        s.nb_saves++;
    } while (s.nb_saves < i);
    fclose(f);
    return s;
}

int getBestScore(saved s){
    int best_index = 0;
    for (int i = 1; i < s.nb_saves; i++)
        if (s.scores[i] > s.scores[best_index])
            best_index = i;
    return best_index;
}   