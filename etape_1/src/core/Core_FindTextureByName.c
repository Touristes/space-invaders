#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

texture_t	*Core_FindTextureByName(obj_t *obj, char *name)
{
	texture_t *it = obj->list_texture;

	if (obj->list_texture != 0){
		while (it != 0)
		{
			if (strcmp(it->name, name) == 0)
			{
				return (it);
			}
			it = it->next;
		}
	}
	return (0);
}