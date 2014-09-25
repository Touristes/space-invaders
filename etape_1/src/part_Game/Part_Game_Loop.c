#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

int Part_Game_Loop(env_t *environ, game_t *game)
{
    int loop;
    input_t input;
    int stime;
    SDL_Rect *bottom;

    bottom = Core_CreateRect(0, HEIGHT - 10, WIDTH, 10 );

    memset(&input, 0, sizeof(input_t));
    loop = 1;
    while (loop)
    {
        stime = SDL_GetTicks();
        Core_UpdateEvents(&input);

        Part_Game_PlayerAction(&input, game, environ);
        Part_Game_Ia_Loop(game);
        Part_Game_Ia_Bullet(game->bullet, game, environ);

        if (input.key[SDL_SCANCODE_ESCAPE] ||
            game->mob == 0 ||
            game->player->next == 0 || Core_CheckIfRectTouch(bottom, game->mob))
            {
                loop = 0;
                if (game->mob == 0)
                {
                    Part_Game_Loop_End(1, environ);
                }
                else if (game->player->next == 0 || Core_CheckIfRectTouch(bottom, game->mob))
                {
                    Part_Game_Loop_End(2, environ);
                }
            }
        else
        {
            Part_Game_Loop_Refresh(environ, game);
            SDL_Delay(30 - (SDL_GetTicks() - stime));
        }
    }
    free(bottom);
    return (0);
}

void Part_Game_Loop_Refresh(env_t *environ, game_t *game)
{
    SDL_RenderClear(environ->renderer);
    Core_RenderList(game->mob, environ->renderer);
    Core_RenderList(game->player, environ->renderer);
    Core_RenderList(game->bullet, environ->renderer);
    Core_RenderList(game->bunker, environ->renderer);
    SDL_RenderPresent(environ->renderer);
}

void Part_Game_Loop_End(int end, env_t *environ)
{
    obj_t *new;

    new = Core_CreateObj(6, "end", Core_CreateRect(0, 0, 640, 800));
    if (end == 1)
    {
        Core_AddTextureToObj(1, "win", new, "./img/victory.bmp", environ->renderer);
        new->active_texture = Core_FindTextureByName(new, "win");
    }
    else
    {
        Core_AddTextureToObj(1, "loose", new, "./img/game_over.bmp", environ->renderer);
        new->active_texture = Core_FindTextureByName(new, "loose");     
    }
    SDL_RenderClear(environ->renderer);
    Core_RenderList(new, environ->renderer);
    SDL_RenderPresent(environ->renderer);
    Core_Pause();
    Part_HS(environ);

}

