#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"

void readScore(char score[10][60]) {
 FILE *file;
 int i;

 file = fopen("score" , "r");
 for(i = 0; fgets(score[i], 60, file) != NULL && i < 10; i++) {
   //puts(score[i]);
 }
 fclose(file);
}
