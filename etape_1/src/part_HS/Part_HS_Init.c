#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int	Part_HS_Init(env_t *environ)
{
	obj_t *list;
	input_t input;
	obj_t *new;
	int hs[10];

printf("In Init\n");

	list = 0;
	memset(&input, 0, sizeof(input_t));
	
	new = Core_CreateObj(1, "nbr", Core_CreateRect(0, 0, 0, 0));
	Core_AddTextureToObj(0, "0", new, "./img/0.bmp", environ->renderer);
	Core_AddTextureToObj(1, "1", new, "./img/1.bmp", environ->renderer);
	Core_AddTextureToObj(2, "2", new, "./img/2.bmp", environ->renderer);
	Core_AddTextureToObj(3, "3", new, "./img/3.bmp", environ->renderer);
	Core_AddTextureToObj(4, "4", new, "./img/4.bmp", environ->renderer);
	Core_AddTextureToObj(5, "5", new, "./img/5.bmp", environ->renderer);
	Core_AddTextureToObj(6, "6", new, "./img/6.bmp", environ->renderer);
	Core_AddTextureToObj(7, "7", new, "./img/7.bmp", environ->renderer);
	Core_AddTextureToObj(8, "8", new, "./img/8.bmp", environ->renderer);
	Core_AddTextureToObj(9, "9", new, "./img/9.bmp", environ->renderer);
	list = Core_AddElemToList(list, new);

	Part_HS_Init_Read(hs, environ->score);
	SDL_RenderClear(environ->renderer);
	Part_HS_Init_Display(environ, list, Core_CreateRect(400, 400,0,0), hs[0]);
    SDL_RenderPresent(environ->renderer);
	Core_Pause();
/*	Core_RenderList(list, environ->renderer);

    Part_MainMenu_Loop(environ, list);
*/  
exit(0);  
    return (0);
}

void Part_HS_Init_Read(int *hs, int score)
{
	FILE *fd;
	char *grou;
	size_t len;

	len = 0;
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
printf("tufyghjn\n");
	list = 0;
	i = 0;
	while (score != 0)
	{
		digit = score % 10;
		score = score/10;
		
		new = Core_CloneObj(models);
		printf("hghjkk\n");
		new->active_texture = Core_FindTextureById(new, digit);
printf("jhg\n");
		new->rect->x = pos->x - (i * new->active_texture->rect->w);
		new->rect->y = pos->y;
		list = Core_AddElemToList(list, new);
		i++;
	}
	printf("giuihiu\n");
	Core_RenderList(list, environ->renderer);
printf("vgchhj\n");
	Core_FreeObjList(list);

printf("njnkl\n");	free(pos);
	return (0);
}


