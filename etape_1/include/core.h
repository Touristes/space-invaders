#ifndef __CORE__
#define __CORE__

#include "include.h"

SDL_Texture	*Core_GetWindowCopy(env_t* environ);
void 	Core_SetWindowCopy(env_t* environ, SDL_Texture* texture);
void	Core_Pause();
void	Core_RenderList(obj_t *list, SDL_Renderer *renderer);
obj_t	*Core_AddElemToList(obj_t *start, obj_t *new);
SDL_Rect	*Core_Clic();
obj_t	*Core_CheckIfRectTouch(SDL_Rect *rect, obj_t *list);
void    Core_RenderObj(SDL_Renderer *renderer, obj_t *obj);
void	Core_UpdateEvents(input_t *input);
obj_t	*Core_FindByName(obj_t *list, char *name);
obj_t	*Core_FindById(obj_t *list, int id);
obj_t	*Core_CreateObj(int id, char *name, SDL_Rect *rect);
SDL_Rect	*Core_CreateRect(int x, int y, int w, int h);
void	Core_AddTextureToObj(int id, char *name, obj_t *obj, char *file, SDL_Renderer *renderer);
texture_t	*Core_FindTextureByName(obj_t *obj, char *name);
texture_t	*Core_FindTextureById(obj_t *obj, int id);
void	Core_FreeTextureList(texture_t *list);
void	Core_FreeList(obj_t *list);
stat_t	*Core_CreateStat(int hp, float speed, int firerate, void (*ia)(obj_t *, game_t *));
obj_t	*Core_CloneObj(obj_t *obj);


#endif