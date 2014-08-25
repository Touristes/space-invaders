#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_CheckIfRectTouch(SDL_Rect *rect, obj_t *list)
{
	obj_t *tmp;
	SDL_Rect rmp;
	SDL_Rect sum;

	if (list != 0)
	{
		tmp = list;
		while (tmp != 0)
		{
			int intersect;

			sum.x = tmp->rect->x;
			sum.y = tmp->rect->y;
			sum.h = tmp->active_texture->rect->h;
			sum.w = tmp->active_texture->rect->w;

			intersect = SDL_IntersectRect(rect, &sum, &rmp);
			if (intersect == SDL_TRUE)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}