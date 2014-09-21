#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_CheckIfObjTouch(obj_t *obj, obj_t *list)
{
	obj_t *tmp;
	SDL_Rect rmp;
	SDL_Rect sum;
	SDL_Rect tmpr;

	if (list != 0 && obj != 0)
	{
		tmpr.x = obj->rect->x;
		tmpr.y = obj->rect->y;
		tmpr.h = obj->active_texture->rect->h;
		tmpr.w = obj->active_texture->rect->w;

		tmp = list;
		while (tmp != 0)
		{
			int intersect;

			sum.x = tmp->rect->x;
			sum.y = tmp->rect->y;
			sum.h = tmp->active_texture->rect->h;
			sum.w = tmp->active_texture->rect->w;


			intersect = SDL_IntersectRect(&tmpr, &sum, &rmp);
			if (intersect == SDL_TRUE)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}