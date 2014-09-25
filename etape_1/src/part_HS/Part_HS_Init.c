#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_HS_Init(env_t *environ)
{
	input_t input;
	obj_t *layer;
	obj_t *nbr;
	int hs[10];

	memset(&input, 0, sizeof(input_t));

	layer = Core_CreateObj(0, "hs", Core_CreateRect(0, 0, 0, 0));
	Core_AddTextureToObj(0, "hs", layer, "./img/hs.bmp", environ->renderer);
	layer->active_texture = Core_FindTextureByName(layer, "hs");

	nbr = Core_CreateObj(1, "nbr", Core_CreateRect(0, 0, 0, 0));
	Core_AddTextureToObj(0, "0", nbr, "./img/0.bmp", environ->renderer);
	Core_AddTextureToObj(1, "1", nbr, "./img/1.bmp", environ->renderer);
	Core_AddTextureToObj(2, "2", nbr, "./img/2.bmp", environ->renderer);
	Core_AddTextureToObj(3, "3", nbr, "./img/3.bmp", environ->renderer);
	Core_AddTextureToObj(4, "4", nbr, "./img/4.bmp", environ->renderer);
	Core_AddTextureToObj(5, "5", nbr, "./img/5.bmp", environ->renderer);
	Core_AddTextureToObj(6, "6", nbr, "./img/6.bmp", environ->renderer);
	Core_AddTextureToObj(7, "7", nbr, "./img/7.bmp", environ->renderer);
	Core_AddTextureToObj(8, "8", nbr, "./img/8.bmp", environ->renderer);
	Core_AddTextureToObj(9, "9", nbr, "./img/9.bmp", environ->renderer);
	nbr->active_texture = Core_FindTextureByName(nbr, "0");

	Part_HS_Init_Read(hs, environ->score);
	SDL_RenderClear(environ->renderer);
 	Core_RenderList(layer, environ->renderer);

	for (int i = 0; i < 5; ++i)
	{
		Part_HS_Init_Display(environ, nbr, Core_CreateRect(400, 200+i*nbr->active_texture->rect->h,0,0), hs[i]);
	}

    SDL_RenderPresent(environ->renderer);
	Core_Pause();
    return (0);
}

void Part_HS_Init_Read(int *hs, int score)
{
	FILE *fd;
	char *grou;
	size_t len;

	grou = 0;
	len = 10;
	if ((fd = fopen("./src/part_HS/HS.txt", "r+")))
	{
		for (int i = 0; i < 10; i++)
		{
			getline(&grou, &len, fd);
			if (atoi(grou) > score || score == 0)
			{
				hs[i] = atoi(grou);
			}
			else
			{
				hs[i] = score;
				score = 0;
				if (i != 9)
				{
					hs[++i] = atoi(grou);
				}
			}
		}
		fclose(fd);
		fd = fopen("./src/part_HS/HS.txt", "w+");
		for (int i = 0; i < 10; i++)
		{
			fprintf(fd, "%d\n", hs[i]);
		}
	}
	else
	{
		fd = fopen("./src/part_HS/HS.txt", "w+");
		hs[0] = score;
		fprintf(fd, "%d\n", score);
		for (int i = 1; i < 10; i++)
		{
			hs[i] = 0;
			fprintf(fd, "0\n");
		}
	}
	fclose(fd);
}

obj_t *Part_HS_Init_Display(env_t *environ, obj_t *models, SDL_Rect *pos, int score)
{
	int digit;
	obj_t *list;
	obj_t *new;
	int i;
	list = 0;
	i = 0;
	while (score != 0)
	{
		digit = score % 10;
		score = score/10;
		
		new = Core_CloneObj(models);
		new->active_texture = Core_FindTextureById(new, digit);
		new->rect->x = pos->x - (i * new->active_texture->rect->w);
		new->rect->y = pos->y;
		list = Core_AddElemToList(list, new);
		i++;
	}
	Core_RenderList(list, environ->renderer);
	Core_FreeObjList(list);

	return (0);
}


