#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"
#include "../include/libSI.h"
void	intToString(int nbr, char *string) {
  int i;

  for (i = 8; i >= 0; i--) {
    string[i] = (nbr % 10) + '0';
    nbr = nbr / 10;
  }
  string[9] = '\0';
}

int	stringToInt(char *string) {
  int nbr;
  int i;

  nbr = 0;
  for (i = 8; i > 0 ;i--) {
    nbr = nbr + ((int)string[i] * i);
  }
  return (nbr);
}
