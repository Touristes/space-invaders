#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_Opt_Init(env_t* environ)
{
	obj_t *list;
	input_t input;
	obj_t *new;
	list = 0;

	memset(&input, 0, sizeof(input_t));
	
	new = Core_CreateObj(1, "opt_menu", Core_CreateRect(0, 0, 0, 0));

	Core_AddTextureToObj(1, "opt_menu", new, "./img/opt_menu.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "opt_menu");
	list = Core_AddElemToList(list, new);

	new = Core_CreateObj(2, "return", Core_CreateRect(80, 699, 0, 0));
	Core_AddTextureToObj(1, "button", new, "./img/return_button.bmp", environ->renderer);
	Core_AddTextureToObj(2, "hover", new, "./img/return_hover.bmp", environ->renderer);
	Core_AddTextureToObj(3, "down", new, "./img/return_down.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "hover");
	list = Core_AddElemToList(list, new);

	Core_RenderList(list, environ->renderer);
    SDL_RenderPresent(environ->renderer);

    Part_Opt_Loop(environ, list);
    printf("PWET PWET LAGALEEEEEEETTE !!!\n");
    Core_FreeList(list);
    return (0);
}


