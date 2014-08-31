#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_MainMenu(env_t *environ)
{
	int	save;
	SDL_Texture *texture;

	texture = Core_GetWindowCopy(environ);
	save = Part_MainMenu_Init(environ);
	Core_SetWindowCopy(environ, texture);
	return (save);
}