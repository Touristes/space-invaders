#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Part_Game_PlayerAction(input_t *input, game_t *game)
{
	if (input->key[SDL_SCANCODE_A] || input->key[SDL_SCANCODE_LEFT])
	{
		Part_Game_PlayerMove((- 30 * game->player->stat->speed), game->player);	
	}
	else if (input->key[SDL_SCANCODE_D] || input->key[SDL_SCANCODE_RIGHT])
	{
		Part_Game_PlayerMove((30 * game->player->stat->speed), game->player);	
	}
	if (input->key[SDL_SCANCODE_W] || input->key[SDL_SCANCODE_UP])
	{
		input->key[SDL_SCANCODE_W] = 0;
		input->key[SDL_SCANCODE_UP] = 0;
		Part_Game_PlayerFire(game->player, game);
	}

}

void Part_Game_PlayerMove(int mdir, obj_t *playerList)
{
	obj_t *it;
	obj_t *player;

	it = playerList;
	while (it != 0)
	{
		player = it;
		it->rect->x += mdir;
		if (it->rect->x < (0 - it->active_texture->rect->w))
		{
			it->rect->x = WIDTH * 2 - it->active_texture->rect->w;
		}
		else if (it->rect->x > (WIDTH * 2 - it->active_texture->rect->w))
		{
			it->rect->x = -it->active_texture->rect->w;
		}
		it = it->next;
	}
}

void Part_Game_PlayerFire(obj_t *playerList, game_t *game)
{
	obj_t *it;
	obj_t *player;
	obj_t *clone;

	it = playerList;
	while (it != 0)
	{

		player = it;
		if (it->rect->x > (0 - it->active_texture->rect->w) &&
			it->rect->x <= (WIDTH - it->active_texture->rect->w/2) &&
			(int)(it->stat->fire_time - SDL_GetTicks()) < it->stat->firerate)
		{
			it->stat->fire_time = SDL_GetTicks();
			clone = Core_CloneObj(Core_FindByName(game->model, "p_bullet"));
			clone->rect->x = it->rect->x + it->active_texture->rect->w / 2 - clone->active_texture->rect->w / 2;
			clone->rect->y = it->rect->y - it->active_texture->rect->h;
			clone->stat->dir = UP;
			game->bullet = Core_AddElemToList(game->bullet, clone);
		}
		it = it->next;
	}
}
