#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

SDL_Rect	*Core_Clic()
{
	SDL_Event event;
	int test;
	SDL_Rect *rect;

	test = 1;
	while (test)
	{
		SDL_WaitEvent(&event);
		if (event.button.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
		{
			rect = xmalloc(sizeof(*rect));
			rect->x = event.button.x;
			rect->y = event.button.y;
			rect->w = 1;
			rect->h = 1;
			return (rect);
		}
	}
	return (0);
}
