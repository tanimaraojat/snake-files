#ifndef FOOD_H
#define FOOD_H


#include <SDL2/SDL.h>


typedef struct
{
    int x;
    int y;

}Food;



void generateFood(Food *food);

void drawFood(SDL_Renderer *renderer, Food *food);


#endif