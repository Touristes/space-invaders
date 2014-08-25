#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_Pause()
{
	SDL_Event event;
	int test;

	test = 1;

	while (test)
	{
		SDL_WaitEvent(&event);
		if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		{
			test = 0;
		}
	}
}