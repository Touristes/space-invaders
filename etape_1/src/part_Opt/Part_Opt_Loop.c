#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_Opt_Loop(env_t *environ, obj_t *list)
{
	int loop;
	input_t input;
	int action;

	action = 0;
	memset(&input, 0, sizeof(input_t));
	loop = 1;
	while (loop)
    {
		Core_UpdateEvents(&input);
    	if (action == 1)
    	{
	   		Part_Opt_SwitchBtnTexture(list, environ->renderer);
 			SDL_Delay(300);
    		action = 0;
    		loop = 0;
    	}
    	else 
    	{
	    	if (input.key[SDL_SCANCODE_ESCAPE] ||
	    		(input.key[SDL_SCANCODE_RETURN] ) ||
	    		(input.mousebuttons[SDL_BUTTON_LEFT] && Core_CheckIfRectTouch(&input.coord, Core_FindByName(list, "return"))))
	    		action = 1;
    	}
    	SDL_Delay(30);
    }
	return (0);
}

void	Part_Opt_SwitchBtnTexture(obj_t *list, SDL_Renderer *renderer)
{
	obj_t *button = Core_FindByName(list, "return");

	button->active_texture = Core_FindTextureByName(button, "down");	
	SDL_RenderClear(renderer);
	Core_RenderList(list, renderer);
	SDL_RenderPresent(renderer);
}