#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

texture_t	*Core_FindTextureById(obj_t *obj, int id)
{

	texture_t *it = obj->list_texture;

	if (obj->list_texture != 0){
		while (it != 0)
		{
			if (it->id == id)
			{
				return (it);
			}
			it = it->next;
		}
	}
	return (0);
}