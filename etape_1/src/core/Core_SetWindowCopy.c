#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void Core_SetWindowCopy(env_t *environ, SDL_Texture *texture)
{	
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WIDTH;
	rect.h = HEIGHT;

	SDL_RenderCopy(environ->renderer,
                   texture,
                   &rect,
                   &rect);
	SDL_RenderPresent(environ->renderer);
}