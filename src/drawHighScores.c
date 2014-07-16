#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"
#include "../include/libSI.h"
SDL_Renderer* drawHighScores(SDL_Renderer* pRenderer, TTF_Font* font, SDL_Surface* pSurface)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
  //char Scores[10][60] = {{' ','J','o','u','e','u','r',' ','1',' ',' ',' ',' ',' ',' ','\0'},
  //			 {' ',' ',' ',' ',' ',' ','1','0','0','0','0','0','0','0','0','\0'},
  //			 {' ','J','o','u','e','u','r',' ','2',' ',' ',' ',' ',' ',' ','\0'},
  //			 {' ',' ',' ',' ',' ',' ','0','0','0','0','5','0','0','0','0','\0'}};
  char Scores[10][60];
  readScore(Scores);
  SDL_Texture *pTexture = NULL;
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(pRenderer);
  SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  SDL_Rect r = {40,40,300,40};
  SDL_Rect r2 = {300,40,300,40};
  SDL_Color color={255,255,255,255};
  for (int i = 0; i < 4 && r.y < 430 ; i++) {
    SDL_RenderFillRect(pRenderer, &r);
    pSurface = TTF_RenderText_Solid(font,Scores[i],color);
    pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    SDL_RenderCopy(pRenderer, pTexture, NULL, &r);
    r.y += 60;
    i++;
    SDL_RenderFillRect(pRenderer, &r2);
    pSurface = TTF_RenderText_Solid(font,Scores[i],color);
    pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    SDL_RenderCopy(pRenderer, pTexture, NULL, &r2);
    r2.y += 60;
  }
  SDL_SetRenderDrawColor(pRenderer, 80, 80, 80, 255);
  SDL_Rect r3 = {50,430,540,40};
  SDL_RenderFillRect(pRenderer, &r3);
  pSurface = TTF_RenderText_Solid(font,"Press enter to return to the main menu",color);
  pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
  SDL_RenderCopy(pRenderer, pTexture, NULL, &r3);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}
