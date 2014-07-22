#ifndef __INCLUDE__
#define __INCLUDE__

#include "../../SDL2/SDL.h"


#define HEIGHT 800
#define WIDTH 640

typedef struct env_s
{
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* surface;

} env_t;

#endif