#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

stat_t	*Core_CreateStat(int hp, float speed, int firerate, void (*ia)(obj_t *, game_t *))
{
	stat_t *stat;

	stat = xmalloc(sizeof(*stat));
	memset(stat, 0, sizeof(stat_t));
	stat->hp = hp;
	stat->speed = speed;
	stat->firerate = firerate;
	stat->ia = ia;
	
	return (stat);
}