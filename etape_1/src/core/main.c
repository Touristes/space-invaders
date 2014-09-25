#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	main()
{
	env_t	environ;
  srand(time(0));
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      return (-1);
    }

    environ.window = SDL_CreateWindow("Space Invaders",
					    				SDL_WINDOWPOS_UNDEFINED,
								    	SDL_WINDOWPOS_UNDEFINED,
								     	WIDTH,
                      HEIGHT,
								     	SDL_WINDOW_SHOWN);

    environ.renderer = SDL_CreateRenderer(environ.window, -1, SDL_RENDERER_PRESENTVSYNC);
    environ.score = 0;
    Part_MainMenu(&environ);

    SDL_DestroyWindow(environ.window);
    SDL_Quit();

}
