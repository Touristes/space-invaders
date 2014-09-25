#include "../../../SDL2/SDL.h"
#include "../../include/include.h"

obj_t *Core_AddElemToList(obj_t *start, obj_t *new)
{
    obj_t *it = start;

    new->next = 0 ;

    if (start != 0){
        while (it->next != 0)
        {
            it = it->next;
        }
        it->next = new;
        new->prev = it;
        return (start);
    }
    else
    {
        new->prev = 0;
        return (new);
    }
}