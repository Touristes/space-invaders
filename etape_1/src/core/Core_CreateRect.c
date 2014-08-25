#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

SDL_Rect	*Core_CreateRect(int x, int y, int w, int h)
{
	SDL_Rect *new;
	printf("In Core_CreateRect\n");

	new = xmalloc(sizeof(*new));
	memset(new, 0, sizeof(*new));
	new->x = x;
	new->y = y;
	new->w = w;
	new->h = h;
	
	return (new);
}