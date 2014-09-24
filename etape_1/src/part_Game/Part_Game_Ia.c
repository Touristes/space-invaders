#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

void	Part_Game_Ia(obj_t *subject, game_t *game)
{
	obj_t *clone;

	if (subject->stat->dir == RIGHT)
	{
		subject->rect->x += 30 * subject->stat->speed;
		if (subject->rect->x > (WIDTH - subject->active_texture->rect->w * 2))
		{
			subject->stat->dir = DOWN;
		}
	}
	else if (subject->stat->dir == DOWN)
	{
		subject->rect->y += 30 * subject->stat->speed;

		if ((subject->rect->y % subject->active_texture->rect->h) < ((int)(subject->rect->y - 30 * subject->stat->speed) % subject->active_texture->rect->h))
		{
			if (subject->rect->x > WIDTH/2)
			{
				subject->stat->dir = LEFT;
			}
			else
			{
				subject->stat->dir = RIGHT;
			}
		}
	}
	else if (subject->stat->dir == LEFT)
	{
		subject->rect->x -= 30 * subject->stat->speed;
		if (subject->rect->x < (subject->active_texture->rect->w))
		{
			subject->stat->dir = DOWN;
		}
	}

	if (0 == (rand()%(100-0))+0 && (int)(subject->stat->fire_time - SDL_GetTicks()) < subject->stat->firerate)
	{
		subject->stat->fire_time = SDL_GetTicks();
		clone = Core_CloneObj(Core_FindByName(game->model, "m_bullet"));
		clone->rect->x = subject->rect->x + subject->active_texture->rect->w / 2 - clone->active_texture->rect->w / 2;
		clone->rect->y = subject->rect->y - subject->active_texture->rect->h;
		clone->stat->dir = DOWN;
		game->bullet = Core_AddElemToList(game->bullet, clone);
	}
}

void Part_Game_Ia_Loop(game_t *game)
{
	obj_t *it;

	it = game->mob;
	while (it != 0)
	{
		it->stat->ia(it, game);

		it = it->next;
	}
}

void	Part_Game_Ia_Bullet(obj_t *subject, game_t *game, env_t *environ)
{
	obj_t *checkret;
	obj_t *tmp;

	while (subject != 0)
	{	
		checkret = 0;
		if (subject->stat->dir == UP)
		{
			subject->rect->y -= 30 * subject->stat->speed;
			if ((checkret = Core_CheckIfObjTouch(subject, game->mob)))
			{
				if ((TIMESCORE - (int)(SDL_GetTicks() - environ->time)) >= 0)
				{
					environ->score += (100 * (TIMESCORE - (int)(SDL_GetTicks() - environ->time)))/TIMESCORE;
				}
				game->mob = Core_RemoveElemFromList(game->mob, checkret);
			}
		}
		else if (subject->stat->dir == DOWN)
		{
			subject->rect->y += 30 * subject->stat->speed;
			if ((checkret = Core_CheckIfObjTouch(subject, game->player)))
			{
				if (game->player->stat->hp != 0)
				{
					game->player->stat->hp -= 1;
				}
				else
				{
					game->player = Core_RemoveElemFromList(game->player, checkret);					
				}
			}
		}
		if (checkret == 0)
		{
			if ((checkret = Core_CheckIfObjTouch(subject, game->bunker)))
			{
				checkret->stat->hp--;
				if (checkret->stat->hp == 0)
				{
					game->bunker = Core_RemoveElemFromList(game->bunker, checkret);					
				}
				else
				{
					if (checkret->stat->hp == 4)
					{
						checkret->active_texture = Core_FindTextureByName(checkret, "mid");
					}
					else if (checkret->stat->hp == 2)
					{
						checkret->active_texture = Core_FindTextureByName(checkret, "ko");	
					}
				}
			}
		}
		tmp = subject;
		subject = subject->next;
		if (checkret != 0 || 
			(tmp->rect->y > HEIGHT + tmp->active_texture->rect->h) || 
			(tmp->rect->y < -tmp->active_texture->rect->h))
		{
			game->bullet = Core_RemoveElemFromList(game->bullet, tmp);	
		}
	}
}
