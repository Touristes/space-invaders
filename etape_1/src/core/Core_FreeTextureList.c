#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_FreeTextureList(texture_t *list)
{
	texture_t *it;
	texture_t *freed;

	it = list;
	while (it != 0)
	{
		freed = it;
		free(freed->rect);
		SDL_DestroyTexture(freed->texture);
		it = it->next;
		free(freed);
	}
}