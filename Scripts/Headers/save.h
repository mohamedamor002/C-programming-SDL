
#include <stdlib.h>

#include <string.h>

#include <stdio.h>



void save(char * name, int score, int xcam, int xp){

}

void load(char * name,char nameS[50], char scoreS[50], char xcam[50], char xp[50]){
    FILE *f;
    
    do {
        fscanf(f, "%s , %s , %s , %s\n", nameS, scoreS, xcam, xp);
    } while ((nameS != name) && (nameS != ""));

    printf("%s , %s , %s , %s\n", nameS, scoreS, xcam, xp);
}