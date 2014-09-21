#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_Game_Loop(env_t *environ, game_t *game)
{
	int loop;
	input_t input;
	int stime;
	
	memset(&input, 0, sizeof(input_t));
	loop = 1;
	while (loop)
    {
		stime = SDL_GetTicks();
		Core_UpdateEvents(&input);

		Part_Game_PlayerAction(&input, game);
		Part_Game_Ia_Loop(game);
		Part_Game_Ia_Bullet(game->bullet, game);

	    if (input.key[SDL_SCANCODE_ESCAPE])
	    	{
	    		loop = 0;
	    	}
		Part_Game_Loop_Refresh(environ, game);
    	SDL_Delay(30 - (SDL_GetTicks() - stime));
    }
	return (0);
}

void Part_Game_Loop_Refresh(env_t *environ, game_t *game)
{
	SDL_RenderClear(environ->renderer);
	Core_RenderList(game->mob, environ->renderer);
	Core_RenderList(game->player, environ->renderer);
	Core_RenderList(game->bullet, environ->renderer);
	Core_RenderList(game->bunker, environ->renderer);
	SDL_RenderPresent(environ->renderer);
}
