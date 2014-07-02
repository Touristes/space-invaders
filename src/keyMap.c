#include "../SDL2/SDL.h"
#include <stdio.h>
#include "struct.c"

struct key getKey(struct key key) {
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  exit(0);
	  break;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_SPACE:
	      key.attack = 1;
	      break;
	    case SDLK_LEFT:
	      key.left = 1;
	      break;
	    case SDLK_RIGHT:
	      key.right = 1;
	      break;
	    case SDLK_DOWN:
	      key.down = 1;
	      break;
	    case SDLK_UP:
	      key.up = 1;
	      break;
            case SDLK_RETURN:
	      key.enter = 1;
	      break;
	    case SDLK_ESCAPE:
	    key.exit = 1;
	    break;
	    default:
	      break;
	    }
	  break;
	case SDL_KEYUP:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_SPACE:
	      key.attack = 0;
	      break;
	    case SDLK_LEFT:
	      key.left = 0;
	      break;
	    case SDLK_RIGHT:
	      key.right = 0;
	      break;
	    case SDLK_DOWN:
	      key.down = 0;
	      break;
	    case SDLK_UP:
	      key.up = 0;
	      break;
            case SDLK_RETURN:
              key.enter = 0;
              break;
            case SDLK_ESCAPE:
              key.exit = 0;
              break;
	    default:
	      break;
	    }
	  break;
	}
    }
  return (key);
}
