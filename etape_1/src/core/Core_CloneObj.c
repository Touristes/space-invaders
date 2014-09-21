#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t	*Core_CloneObj(obj_t *obj)
{
	obj_t *objCopy;

	objCopy = xmalloc(sizeof(obj_t));
	objCopy = memcpy(objCopy, obj, sizeof(obj_t));

	objCopy->rect = xmalloc(sizeof(SDL_Rect));
	objCopy->rect = memcpy(objCopy->rect, obj->rect, sizeof(SDL_Rect));

	objCopy->stat = xmalloc(sizeof(stat_t));
	objCopy->stat = memcpy(objCopy->stat, obj->stat, sizeof(stat_t));

	return (objCopy);
}

//tous les objets qui ont la meme texture pointent vers la meme texture