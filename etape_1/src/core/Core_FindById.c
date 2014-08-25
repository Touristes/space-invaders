#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_FindById(obj_t *list, int id)
{
	obj_t *it = list;

	if (list != 0){
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