#include "../SDL2/SDL.h"
#include "../SDL2/SDL_TTF.h"
#include <stdio.h>
#include "../include/libSI.h"
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
  TTF_Init();
  /* Création de la fenêtre */
  SDL_Window* pWindow = NULL;
  SDL_Renderer* pRenderer = NULL;
  SDL_Surface* pSurface = NULL;
  TTF_Font* font = TTF_OpenFont("/Library/Fonts/Microsoft/Arial.ttf", 72);
  pWindow = SDL_CreateWindow("Space Invaders",SDL_WINDOWPOS_UNDEFINED,
			     SDL_WINDOWPOS_UNDEFINED,
			     640,
			     480,
			     SDL_WINDOW_SHOWN);
  pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
  /* Initialisation du texte */
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
	  if (key.down == 1 && selectedMenu < 4)
	    selectedMenu++;
	  else if (key.up == 1 && selectedMenu > 1)
	    selectedMenu--;
	  else if (key.enter == 1) {
	    if (selectedMenu == 1)
	      menu = 0;
	    else if (selectedMenu == 2)
	      menu = 1; //doing nothing yet
	    else if (selectedMenu == 3)
	      menu = 2;
            else if (selectedMenu == 4)
              loop = 0;
	  }
	  pRenderer = drawMenu(pRenderer, selectedMenu, font, pSurface);
	}
	else if (menu == 2) {
	  if (key.enter == 1)
	    menu = 1;
	  else
	    pRenderer = drawHighScores(pRenderer, font, pSurface);
	}
	else
	  pRenderer = drawGame(pRenderer);
	SDL_Delay(100);
	}
    }
  TTF_CloseFont(font);
  SDL_DestroyWindow(pWindow);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
