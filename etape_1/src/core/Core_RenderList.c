#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_RenderList(obj_t *list, SDL_Renderer *renderer)
{
	obj_t *it;

	it = list;
	while (it != 0)
	{
		Core_RenderObj(renderer, it);
		it = it->next;
	}
}
