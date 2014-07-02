#include "../SDL2/SDL.h"
#include <stdio.h>

SDL_Renderer* drawGame(SDL_Renderer* pRenderer);
SDL_Renderer* drawMenu(SDL_Renderer* pRenderer, int selectedMenu);
struct key getKey(struct key key);
