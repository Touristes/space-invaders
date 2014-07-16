#include "../SDL2/SDL.h"
#include "../SDL2/SDL_ttf.h"
#include <stdio.h>

SDL_Renderer* drawGame(SDL_Renderer* pRenderer);
SDL_Renderer* drawMenu(SDL_Renderer* pRenderer, int selectedMenu,TTF_Font* font, SDL_Surface* pSurface);
SDL_Renderer* drawHighScores(SDL_Renderer* pRenderer, TTF_Font* font, SDL_Surface* pSurface);
struct key getKey(struct key key);
void readScore(char score[10][60]);
int     writeScore(char *name, int points);
void    intToString(int nbr, char *string);
int     stringToInt(char *string);
