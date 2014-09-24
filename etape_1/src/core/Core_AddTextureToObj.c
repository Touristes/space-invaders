#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Core_AddTextureToObj(int id, char *name, obj_t *obj, char *file, SDL_Renderer *renderer)
{
	texture_t *new;
	new = xmalloc(sizeof(*new));
	
	SDL_Surface *sprite = SDL_LoadBMP(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, sprite);
    new->rect = xmalloc(sizeof(SDL_Rect));
    new->id = id;
    new->name = name;
	    
     if (sprite)
     {
	    if (texture)
	    {
	    	new->rect = Core_CreateRect(0, 0, sprite->w, sprite->h);
			new->texture = texture;
	    }
	    else
	    {
	        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
	        exit(0);
	    }
	    
	    SDL_FreeSurface(sprite);
    }
    else
    {
        fprintf(stdout,"Échec de la création du sprite (%s)\n",SDL_GetError());
        exit(0);
    }
	texture_t *it;

	it = obj->list_texture;
	new->next = 0 ;
	if (obj->list_texture != 0){
		while (it->next != 0)
		{
			it = it->next;
		}
		it->next = new;
		new->prev = it;
	}
	else
	{
		new->prev = 0;
		obj->list_texture = new;
	}
}