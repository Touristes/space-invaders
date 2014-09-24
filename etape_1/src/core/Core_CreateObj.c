#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_CreateObj(int id, char *name, SDL_Rect *rect)
{
	obj_t *new;

	new = xmalloc(sizeof(*new));
	memset(new, 0, sizeof(obj_t));
	new->id = id;
	new->name = name;
	new->rect = rect;
	new->stat = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}