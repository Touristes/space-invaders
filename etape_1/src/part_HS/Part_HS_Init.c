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
	printf("%d\n", hs[0]);
/*	Core_RenderList(list, environ->renderer);
    SDL_RenderPresent(environ->renderer);

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

	printf("In read\n");
	len = 0;
	if ((fd = fopen("./src/part_HS/HS.txt", "r+")))
	{
		printf("avantfor1\n");
		for (int i = 0; i < 10; i++)
		{
			getline(&grou, &len, fd);
			printf("%s\n", grou);
			if (atoi(grou) > score)
			{
				printf("in atoi de grou\n");
				hs[i] = atoi(grou);
			}
			else
			{
				hs[i] = score;
				if (i != 9)
				{
					hs[i++] = atoi(grou);
				}
			}
		}
		fseek(fd, SEEK_SET, 0);
		printf("avantfor2\n");
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
}
