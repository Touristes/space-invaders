#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

t_func_ptr func_tab[]= {
	{"start",	Part_Game},
	{"hs",		Part_HS},
	{"opt",		Part_Opt},
	{0, 0}
};

int	Part_MainMenu_Loop(env_t *environ, obj_t *list)
{
	int loop;
	input_t input;
	int btnhover;
	obj_t *ayw;
	int action;

	btnhover = 1;
	action = 0;
	
	memset(&input, 0, sizeof(input_t));
	loop = 1;
	while (loop)
    {
		Core_UpdateEvents(&input);
    	if (action == 1)
    	{
    		if (btnhover == 4)
    		{
		   		loop = 0;
    		}
    		Part_MainMenu_SwitchBtnTexture(list, btnhover, environ->renderer, "down");
 			SDL_Delay(300);
    		for (int i = 0; func_tab[i].flag != 0; i++)
    		{
    			if (func_tab[i].flag == Core_FindById(list, btnhover)->name)
    				func_tab[i].func(environ);
    		}
    		action = 0;
			memset(&input, 0, sizeof(input_t));
    	}
    	else
    	{
	    	if (input.key[SDL_SCANCODE_UP] && btnhover > 1)
	    	{
	    		btnhover--;
	    		input.key[SDL_SCANCODE_UP] = 0;	
	    	}
	    	else if (input.key[SDL_SCANCODE_DOWN] && btnhover < 4)
	    	{
	    		btnhover++;
	    		input.key[SDL_SCANCODE_DOWN] = 0;
	    	}
	     	if (input.key[SDL_SCANCODE_RETURN] || 
	     		(input.mousebuttons[SDL_BUTTON_LEFT] && Core_CheckIfRectTouch(&input.coord, list)))
	     		action = 1;
	     	if ((ayw = Core_CheckIfRectTouch(&input.coord, list)))
	    		btnhover = ayw->id;
	    	if (input.key[SDL_SCANCODE_ESCAPE] ||
	    		(input.key[SDL_SCANCODE_RETURN] && btnhover == 4 ) ||
	    		(input.mousebuttons[SDL_BUTTON_LEFT] && Core_CheckIfRectTouch(&input.coord, Core_FindByName(list, "exit"))))
	    	{
	    		btnhover = 4;
	    		action = 1;
	    	}
	    	Part_MainMenu_SwitchBtnTexture(list, btnhover, environ->renderer, "hover");
    	}
    	SDL_Delay(30);
    }
	return (0);
}

void	Part_MainMenu_SwitchBtnTexture(obj_t *list, int btnhover, SDL_Renderer *renderer, char *state)
{
	obj_t *it;

	it = list;
	while (it != 0)
	{
		if (it->id == btnhover)
		{
			it->active_texture = Core_FindTextureByName(it, state);
		}
		else
		{
			it->active_texture = Core_FindTextureByName(it, "button");	
		}
		it = it->next;
	}
	SDL_RenderClear(renderer);

	it = Core_CreateObj(0, "main_menu", Core_CreateRect(0, 0, 0, 0));
	Core_AddTextureToObj(1, "main_menu", it, "./img/main_menu.bmp", renderer);
	it->active_texture = Core_FindTextureByName(it, "main_menu");
	Core_RenderList(it, renderer);
	Core_RenderList(list, renderer);
	SDL_RenderPresent(renderer);
	Core_FreeList(it);

}