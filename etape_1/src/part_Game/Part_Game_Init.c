#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

char *mob_pink[] = {
	"down", "./img/mob_pink.bmp",
	0
};

char *mob_yellow[] = {
	"down", "./img/mob_yellow.bmp",
	0
};

char *bunker[] = {
	"ok", "./img/bunker_ok.bmp",
	"mid", "./img/bunker_mid.bmp",
	"ko", "./img/bunker_ko.bmp",
	0
};

char *player[] = {
	"up", "./img/spaceship.bmp",
	0
};

char *m_bullet[] = {
	"fire", "./img/bullet_dr.bmp",
	0
};

char *p_bullet[] = {
	"fire", "./img/bullet_w.bmp",
	0
};

int	Part_Game_Init(env_t *environ)
{
	game_t game;
	int nb_line;

	nb_line= (rand()%(6-3))+3;
	game.model = Core_AddElemToList(0, Part_Game_Init_Model("mob_pink", mob_pink, 
	 			 Core_CreateStat(1,0.1,350, &Part_Game_Ia), environ));
	game.model = Core_AddElemToList(game.model, Part_Game_Init_Model("mob_yellow", mob_yellow, 
		         Core_CreateStat(1,0.1,350, &Part_Game_Ia), environ));
	game.model = Core_AddElemToList(game.model, Part_Game_Init_Model("bunker", bunker, 
				 Core_CreateStat(12,0,0, &Part_Game_Ia), environ));
	game.model = Core_AddElemToList(game.model, Part_Game_Init_Model("player", player, 
				 Core_CreateStat(3,0.3,175, &Part_Game_Ia), environ));
	game.model = Core_AddElemToList(game.model, Part_Game_Init_Model("m_bullet", m_bullet, 
				 Core_CreateStat(1,0.7,0, &Part_Game_Ia), environ));
	game.bullet = 0;
	game.model = Core_AddElemToList(game.model, Part_Game_Init_Model("p_bullet", p_bullet, 
				 Core_CreateStat(1,0.7,0, &Part_Game_Ia), environ));

	game.mob = 0;
	for (int i = 0; i < nb_line; i++)
	{
		game.mob = Part_Game_Init_Line((rand()%(200-100))+100, 30 , WIDTH -(rand()%(200-100))+100, ((1+i++)*60), game.mob, Core_FindByName(game.model, "mob_yellow"));
		game.mob = Part_Game_Init_Line((rand()%(200-100))+100, 30 , WIDTH -(rand()%(200-100))+100, ((1+i)*60), game.mob, Core_FindByName(game.model, "mob_pink"));
	}

	game.bunker = Part_Game_Init_Line(20, 60, 560, HEIGHT - 40, 0, Core_FindByName(game.model, "bunker"));
	game.player = Part_Game_Init_Line(320, 0, 321, HEIGHT - 10, 0, Core_FindByName(game.model, "player"));
	game.player = Part_Game_Init_Line(320+WIDTH, 0, 321 + WIDTH, HEIGHT - 10, game.player, Core_FindByName(game.model, "player"));
	SDL_RenderClear(environ->renderer);
	Core_RenderList(game.mob, environ->renderer);
	Core_RenderList(game.bunker, environ->renderer);
	Core_RenderList(game.player, environ->renderer);

    SDL_RenderPresent(environ->renderer);
    environ->time = SDL_GetTicks();
    environ->score = 0;
    Part_Game_Loop(environ, &game);

	// ne pas oublier de free game et les sous listes
	Part_Game_Init_Free(&game);
    return (0);
}

void Part_Game_Init_Free(game_t *game)
{
	Core_FreeObjList(game->mob);
	Core_FreeObjList(game->bunker);
	Core_FreeObjList(game->player);
	Core_FreeObjList(game->bullet);
	Core_FreeList(game->model);
}

obj_t *Part_Game_Init_Model(char *name, char **texture, stat_t *stat, env_t *environ)
{
	int id;
	int i;
	obj_t *newMob;

	i = 0;
	id = 1;
	newMob = xmalloc(sizeof(obj_t));
	newMob = Core_CreateObj(1, name, Core_CreateRect(0, 0, 0, 0));
	newMob->stat = stat;
	while (texture[i])
	{
		Core_AddTextureToObj(id, texture[i], newMob, texture[i+1], environ->renderer);
		id++;
		i += 2;
	}
	
	newMob->active_texture = Core_FindTextureByName(newMob, texture[0]);
	return (newMob);	
}

obj_t	*Part_Game_Init_Line(int start_x, int inter_x, int finish_x, int y, obj_t *objList, obj_t *model)
{
	obj_t *clone;

	while (start_x < finish_x)
	{
		clone = Core_CloneObj(model);
		clone->rect->x = start_x;
		clone->rect->y = y;

		start_x = start_x + clone->active_texture->rect->w + inter_x;
		objList = Core_AddElemToList(objList, clone);
	}
	return (objList);
}
