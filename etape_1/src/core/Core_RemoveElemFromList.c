#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t *Core_RemoveElemFromList(obj_t *start, obj_t *elem)
{
	obj_t *tmp;

	if (elem == 0)
	{
		return start;
	}
	if (elem->prev == 0)
	{

		free(elem->rect);
		tmp = elem->next;
		elem->next = 0;
		if (tmp)
			tmp->prev = 0;
		free(elem);
		
		return (tmp);
	}
	else
	{
		elem->prev->next = elem->next;
		if (elem->next != 0)
		{
			elem->next->prev = elem->prev;	
		}
		free(elem->rect);
		free(elem);

		return (start);
	}
}

