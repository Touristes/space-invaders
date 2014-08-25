#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

SDL_Texture *Core_GetWindowCopy(env_t *environ)
{
	SDL_Texture *texture;

	texture = SDL_CreateTexture(environ->renderer,
                               	SDL_PIXELFORMAT_UNKNOWN,
                               	SDL_TEXTUREACCESS_STATIC, 
                               	WIDTH,
                               	HEIGHT);
	return (texture);
	
}