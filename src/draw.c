#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"
SDL_Renderer* drawGame(SDL_Renderer* pRenderer)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(pRenderer);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}

SDL_Renderer* drawMenu(SDL_Renderer* pRenderer, int selectedMenu, TTF_Font* font, SDL_Surface* pSurface)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
        //Le titre
  SDL_Texture *pTexture = NULL;
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(pRenderer);
  SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
    if (selectedMenu == 1)
    SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  else
    SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
  SDL_Rect r = {50,50,540,50};
  SDL_RenderFillRect(pRenderer, &r);
  if (selectedMenu == 2)
    SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  else
    SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
  SDL_Color color={255,255,255,255};
  pSurface = TTF_RenderText_Solid(font,"          Start Game           ",color);
  pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
  SDL_RenderCopy(pRenderer, pTexture, NULL, &r);
  r.y = 150;
  SDL_RenderFillRect(pRenderer, &r);
  pSurface = TTF_RenderText_Solid(font,"          Option           ",color);
  pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
  SDL_RenderCopy(pRenderer, pTexture, NULL, &r);
  if (selectedMenu == 3)
    SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  else
    SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
  r.y = 250;
  SDL_RenderFillRect(pRenderer, &r);
  pSurface = TTF_RenderText_Solid(font,"          High score           ",color);
  pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
  SDL_RenderCopy(pRenderer, pTexture, NULL, &r);
  if (selectedMenu == 4)
    SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  else
    SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
  r.y = 350;
  SDL_RenderFillRect(pRenderer, &r);
  pSurface = TTF_RenderText_Solid(font,"             Exit              ",color);
  pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
  SDL_RenderCopy(pRenderer, pTexture, NULL, &r);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}
