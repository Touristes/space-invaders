#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_FindByName(obj_t *list, char *name)
{
	obj_t *it = list;

	if (list != 0){
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