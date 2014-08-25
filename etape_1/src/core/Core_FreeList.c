#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_FreeList(obj_t *list)
{
	obj_t *it;
	obj_t *freed;

	it = list;
	while (it != 0)
	{
		freed = it;
		free(freed->rect);
		Core_FreeTextureList(freed->list_texture);
		it = it->next;
		free(freed);
	}
}