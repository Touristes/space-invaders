#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_UpdateEvents(input_t *input)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)		
			input->key[event.key.keysym.scancode] = 1;
		if (event.type == SDL_KEYUP)
			input->key[event.key.keysym.scancode] = 0;
		if (event.type == SDL_MOUSEMOTION)
		{
			input->coord.x = event.motion.x;
			input->coord.y = event.motion.y;
			input->coord.w = 1;
			input->coord.h = 1;
			input->mousexrel = event.motion.xrel;
			input->mouseyrel = event.motion.yrel;
		}

		if (event.type == SDL_MOUSEBUTTONDOWN)
			input->mousebuttons[event.button.button] = 1;
		if (event.type == SDL_MOUSEBUTTONUP)
			input->mousebuttons[event.button.button] = 0;
		if (event.type == SDL_QUIT)
			input->quit = 1;
	}

}