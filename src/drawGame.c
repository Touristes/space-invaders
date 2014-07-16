#include "../SDL2/SDL.h"
#include <stdio.h>
#include "../SDL2/SDL_ttf.h"
#include "../include/libSI.h"
SDL_Renderer* drawGame(SDL_Renderer* pRenderer)
{
  // Remplis le renderer de noir, efface l'écran et l'affiche.
  //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(pRenderer);
  SDL_RenderPresent(pRenderer);
  return (pRenderer);
}
