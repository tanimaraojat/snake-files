#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>


#define BLOCK 20
#define MAX_LENGTH 100


typedef struct
{
    int x[MAX_LENGTH];
    int y[MAX_LENGTH];

    int length;

    int dx;
    int dy;

}Snake;



void initSnake(Snake *snake);

void moveSnake(Snake *snake);

void growSnake(Snake *snake);

void drawSnake(SDL_Renderer *renderer, Snake *snake);

void changeDirection(Snake *snake, SDL_Event event);



#endif