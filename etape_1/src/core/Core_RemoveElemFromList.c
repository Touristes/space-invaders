#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t *Core_RemoveElemFromList(obj_t *start, obj_t *elem)
{
	printf("->Core_RemoveElemFromList\n"	);
	printf("!=%p\n", elem);

	obj_t *tmp;
	if (elem == 0)
	{
		return start;
	}
	if (elem->prev == 0)
	{
		printf("Q\n" );

		free(elem->rect);
		tmp = elem->next;
		elem->next = 0;
		if (tmp)
			tmp->prev = 0;
		free(elem);
		
		printf("<-Core_RemoveElemFromList\n");
		return (tmp);
	}
	else
	{
		printf("A\n" );
		elem->prev->next = elem->next;
		if (elem->next != 0)
		{
			elem->next->prev = elem->prev;	
		}
		free(elem->rect);
		free(elem);

		printf("<-Core_RemoveElemFromList\n");
		return (start);
	}
}

