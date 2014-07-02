#include "../SDL2/SDL.h"
#include <stdio.h>
#include "libSI.h"
#include "struct.c"

int main(int argc , char ** argv)
{
  char a;
  struct key key;
  int loop;
  int menu;
  int selectedMenu;
  /* Initialisation simple */
  if (argc == 1)
    a = argv[0][0];
  if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      return -1;
    }
    /* Création de la fenêtre */
    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRenderer = NULL;
    pWindow = SDL_CreateWindow("Space Invaders",SDL_WINDOWPOS_UNDEFINED,
			       SDL_WINDOWPOS_UNDEFINED,
			       640,
			       480,
			       SDL_WINDOW_SHOWN);
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if ( pWindow )
      {
	loop = 1;
	menu = 1;
	selectedMenu = 1;
	while (loop == 1) {
	  key = getKey(key);
	if (key.exit == 1)
	  loop = 0;
	if (menu == 1) {
	  if (key.down == 1 && selectedMenu < 3)
	    selectedMenu++;
	  else if (key.up == 1 && selectedMenu > 1)
	    selectedMenu--;
	  pRenderer = drawMenu(pRenderer, selectedMenu);
	}
	else
	  pRenderer = drawGame(pRenderer);
	SDL_Delay(100);
	}
      }
  SDL_DestroyWindow(pWindow);
  SDL_Quit();
  return 0;
}
