#ifndef __INCLUDE__
#define __INCLUDE__

#include "../../SDL2/SDL.h"

#define HEIGHT 800
#define WIDTH 640

typedef struct env_s
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;

} env_t;

typedef struct texture_s
{
	int id;
	char *name;
	SDL_Rect *rect;
	SDL_Texture *texture;
	struct texture_s *next;
	struct texture_s *prev;

} texture_t;

typedef struct obj_s
{
	int id;
	char *name;
	SDL_Rect *rect;
	texture_t *list_texture;
	texture_t *active_texture;
	struct obj_s *next;
	struct obj_s *prev;

} obj_t;

typedef struct input_s
{
	int key[SDL_NUM_SCANCODES];
	SDL_Rect coord;
	int mousexrel;
	int mouseyrel;
	int mousebuttons[8];
	char quit;

} input_t;

typedef struct s_func_ptr{
	char *flag;
	int (*func)(env_t *);
} 	       t_func_ptr;

#include "core.h"

// Part-MainMenu
int	Part_MainMenu_Init(env_t *environ);
int	Part_MainMenu(env_t *environ);
int	Part_MainMenu_Loop(env_t *environ, obj_t *list);
void	Part_MainMenu_SwitchBtnTexture(obj_t *list, int btnhover, SDL_Renderer *renderer, char *state);
obj_t *Part_MainMenu_ListCeption(char *name, obj_t *list, SDL_Renderer *renderer, int x, int y, char *file);

//Part_Opt_Menu
int	Part_Opt_Init(env_t* environ);
int	Part_Opt(env_t *environ);
void	Part_Opt_SwitchBtnTexture(obj_t *button, SDL_Renderer *renderer);
int	Part_Opt_Loop(env_t *environ, obj_t *list);

//Part_Game
int	Part_Game(env_t *environ);

//Part_HS
int	Part_HS(env_t *environ);


#include "x_func.h"

#endif