#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_HS(env_t *environ)
{
//	int	save;
	SDL_Texture *texture;

	texture = Core_GetWindowCopy(environ);
//	save = Part_Opt_Init(environ);
	environ = 0;
	Core_SetWindowCopy(environ, texture);

	return (0);
}