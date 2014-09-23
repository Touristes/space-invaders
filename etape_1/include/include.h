#ifndef __INCLUDE__
#define __INCLUDE__

#include "../../SDL2/SDL.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 800
#define WIDTH 640
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define WIN 1
#define LOOSE 2
#define TIMESCORE 30000

typedef struct env_s
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  int score;
  int time;

}	env_t;

typedef struct texture_s
{
	int id;
	char *name;
	SDL_Rect *rect;
	SDL_Texture *texture;
	struct texture_s *next;
	struct texture_s *prev;

}	texture_t;

typedef struct obj_s
{
	int id;
	char *name;
	struct stat_s *stat;
	SDL_Rect *rect;
	texture_t *list_texture;
	texture_t *active_texture;
	struct obj_s *next;
	struct obj_s *prev;

} 	obj_t;

typedef struct input_s
{
	int key[SDL_NUM_SCANCODES];
	SDL_Rect coord;
	int mousexrel;
	int mouseyrel;
	int mousebuttons[8];
	char quit;

} 	input_t;

typedef struct s_func_ptr{
	char *flag;
	int (*func)(env_t *);
}	t_func_ptr;

typedef struct game_s
{
	obj_t *mob;
	obj_t *player;
	obj_t *bullet;
	obj_t *bunker;
	obj_t *model;

} 	game_t;

typedef struct stat_s
{
	int hp;
	float speed; //pixels/ms
	int dir; //direction
	int firerate; //ms between 2 shots
	int fire_time; //ms last shoot time
	void (*ia)(obj_t *, game_t *);

}	stat_t;

#include "core.h"

// Part-MainMenu
int		Part_MainMenu_Init(env_t *environ);
int		Part_MainMenu(env_t *environ);
int		Part_MainMenu_Loop(env_t *environ, obj_t *list);
void	Part_MainMenu_SwitchBtnTexture(obj_t *list, int btnhover, SDL_Renderer *renderer, char *state);
obj_t	*Part_MainMenu_ListCeption(char *name, obj_t *list, SDL_Renderer *renderer, int x, int y, char *file);

//Part_Opt_Menu
int		Part_Opt_Init(env_t* environ);
int		Part_Opt(env_t *environ);
void	Part_Opt_SwitchBtnTexture(obj_t *button, SDL_Renderer *renderer);
int		Part_Opt_Loop(env_t *environ, obj_t *list);

//Part_Game
int		Part_Game(env_t *environ);
int		Part_Game_Init(env_t *environ);
obj_t 	*Part_Game_Init_Model(char *name, char **texture, stat_t *stat, env_t *environ);
obj_t	*Part_Game_Init_Line(int start_x, int inter_x, int finish_x, int y, obj_t *new_obj, obj_t *model);
void 	Part_Game_Init_Free(game_t *game);
void	Part_Game_Ia(obj_t *subject, game_t *game);
void	Part_Game_Ia_Loop(game_t *game);
void	Part_Game_Ia_Bullet(obj_t *subject, game_t *game, env_t *environ);
int 	Part_Game_Loop(env_t *environ, game_t *game);
void	Part_Game_Loop_Refresh(env_t *environ, game_t *game);
void	Part_Game_PlayerAction(input_t *input, game_t *game);
void 	Part_Game_PlayerMove(int mdir, obj_t *playerList);
void 	Part_Game_PlayerFire(obj_t *playerList, game_t *game);
void 	Part_Game_Loop_End(int end, env_t *environ);
	
//Part_HS
int		Part_HS(env_t *environ);
int 	Part_HS_Init(env_t *environ);
void 	Part_HS_Init_Read(int *hs, int score);

#include "x_func.h"

#endif