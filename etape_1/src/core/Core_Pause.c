#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_Pause()
{
	SDL_Event event;
	input_t input;
	int test;

	test = 1;
	SDL_Delay(1000);
	Core_UpdateEvents(&input);
	while (test)
	{
		SDL_WaitEvent(&event);
			test = 0;
	}
}