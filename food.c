#include "food.h"
#include <stdlib.h>
#define BLOCK 20

void generateFood(Food *food)
{
    food->x = (rand()%40)*BLOCK;
    food->y = (rand()%30)*BLOCK;
}
void drawFood(SDL_Renderer *renderer, Food *food)
{
    SDL_SetRenderDrawColor(
        renderer,
        255,
        0,
        0,
        255
    );

    SDL_Rect rect =
    {
        food->x,
        food->y,
        BLOCK,
        BLOCK
    };

    SDL_RenderFillRect(renderer,&rect);

}