#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"
#include "../include/libSI.h"
int	writeScore(char *name, int points) {
 FILE *file;
 int i;
 char strPoints[10];
 //char **score = NULL
 i = 0;
   //score = readScore();
 file = fopen("score" , "w");
 if(file == NULL) {
   return(-1);
 }
 fputs(name,file);
 fputs("\n",file);
 intToString(points, strPoints);
 fputs(strPoints, file);
 fputs("\n",file);
 fclose(file);;
 return(0);
}
