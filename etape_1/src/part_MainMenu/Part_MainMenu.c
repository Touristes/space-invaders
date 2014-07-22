#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_MainMenu(env_t* environ)
{
	int	save;
	//variable pour sauvegarder l'image

	Core_GetWindowCopy(environ);
	save = Part_MainMenu_Init(environ);
	Core_SetWindowCopy(environ);
}