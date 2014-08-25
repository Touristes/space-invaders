#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void    Core_RenderObj(SDL_Renderer *renderer, obj_t *obj)
{
    SDL_Rect rect;

    if (obj->active_texture->texture)
    {
        rect.x = obj->rect->x;
        rect.y = obj->rect->y;
        rect.w = obj->active_texture->rect->w;
        rect.h = obj->active_texture->rect->h;
        SDL_RenderCopy(renderer, obj->active_texture->texture, NULL, &rect);
    }
    else
    {
        fprintf(stdout,"Échec la texture n'existe pas (%s)\n",SDL_GetError());
        exit(0);
    }
}
