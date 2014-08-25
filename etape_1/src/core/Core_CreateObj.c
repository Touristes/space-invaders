#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_CreateObj(int id, char *name, SDL_Rect *rect)
{
	obj_t *new;

	printf("In Core_CreateObj : Rect %p\n", rect);

	new = xmalloc(sizeof(*new));
	printf("In Core_CreateObj : after xmalloc\n");

	memset(new, 0, sizeof(obj_t));
	new->id = id;
	new->name = name;
	new->rect = rect;
	
	return (new);
}