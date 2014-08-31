#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_Game(env_t *environ)
{
	int	save;
	SDL_Texture *texture;

	printf("Part_Game \n" );

	texture = Core_GetWindowCopy(environ);
	save = Part_Game_Init(environ);
	Core_SetWindowCopy(environ, texture);

	return (0);
}