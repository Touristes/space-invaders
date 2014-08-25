#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_MainMenu_Init(env_t* environ)
{
	obj_t *list;
	input_t input;
	obj_t *new;

	printf("Part_MainMenu_Init\n");

	
	list = 0;
	memset(&input, 0, sizeof(input_t));
	
	printf("Part_MainMenu_Init : before Core_CreateObj\n");
	new = Core_CreateObj(1, "start", Core_CreateRect(80, 300, 0, 0));

	printf("Part_MainMenu_Init : after Core_CreateObj\n");
	Core_AddTextureToObj(1, "button", new, "./img/start_button.bmp", environ->renderer);
	Core_AddTextureToObj(2, "hover", new, "./img/start_hover.bmp", environ->renderer);
	Core_AddTextureToObj(3, "down", new, "./img/start_down.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "hover");
	list = Core_AddElemToList(list, new);

	new = Core_CreateObj(2, "opt", Core_CreateRect(80, 430, 0, 0));
	Core_AddTextureToObj(1, "button", new, "./img/opt_button.bmp", environ->renderer);
	Core_AddTextureToObj(2, "hover", new, "./img/opt_hover.bmp", environ->renderer);
	Core_AddTextureToObj(3, "down", new, "./img/opt_down.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "button");
	list = Core_AddElemToList(list, new);

	new = Core_CreateObj(3, "hs", Core_CreateRect(80, 566, 0, 0));
	Core_AddTextureToObj(1, "button", new, "./img/hs_button.bmp", environ->renderer);
	Core_AddTextureToObj(2, "hover", new, "./img/hs_hover.bmp", environ->renderer);
	Core_AddTextureToObj(3, "down", new, "./img/hs_down.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "button");
	list = Core_AddElemToList(list, new);

	new = Core_CreateObj(4, "exit", Core_CreateRect(80, 699, 0, 0));
	Core_AddTextureToObj(1, "button", new, "./img/exit_button.bmp", environ->renderer);
	Core_AddTextureToObj(2, "hover", new, "./img/exit_hover.bmp", environ->renderer);
	Core_AddTextureToObj(3, "down", new, "./img/exit_down.bmp", environ->renderer);
	new->active_texture = Core_FindTextureByName(new, "button");
	list = Core_AddElemToList(list, new);

	Core_RenderList(list, environ->renderer);
    SDL_RenderPresent(environ->renderer);

    Part_MainMenu_Loop(environ, list);
    return (0);
}

/*obj_t *Part_MainMenu_ListCeption(char *name, int *id, obj_t *list, SDL_Renderer *renderer, int x, int y, char *file)
{
	obj_t *new;

	new = Core_RenderBMP(renderer, x, y, file);
	new->name = name;
	new->id = id;
	list = Core_AddElemToList(list, new);

	return (list);
}*/

/*obj_t *Part_MainMenu_Display(obj_t *list, int btn, int state)
{

	return (list);
}*/