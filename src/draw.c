#include "../SDL2/SDL.h"
#include <stdio.h>

SDL_Renderer* drawGame(SDL_Renderer* pRenderer)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(pRenderer);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}

SDL_Renderer* drawMenu(SDL_Renderer* pRenderer, int selectedMenu)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
  SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
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
  r.y = 150;
  SDL_RenderFillRect(pRenderer, &r);
  if (selectedMenu == 3)
    SDL_SetRenderDrawColor(pRenderer, 180, 180, 250, 255);
  else
    SDL_SetRenderDrawColor(pRenderer, 80, 80, 150, 255);
  r.y = 250;
  SDL_RenderFillRect(pRenderer, &r);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}
