#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_FreeObjList(obj_t *list)
{
	obj_t *it;
	obj_t *freed;

	it = list;
	while (it != 0)
	{
		freed = it;
		free(freed->rect);
		if (freed->stat != 0)
		{
			free(freed->stat);
		}
		it = it->next;
		free(freed);
	}
}