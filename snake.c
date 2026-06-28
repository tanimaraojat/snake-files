#include "snake.h"



void initSnake(Snake *snake)
{
    snake->length = 3;


    snake->x[0] = 400;
    snake->y[0] = 300;


    snake->x[1] = 380;
    snake->y[1] = 300;


    snake->x[2] = 360;
    snake->y[2] = 300;



    snake->dx = BLOCK;
    snake->dy = 0;
}

void moveSnake(Snake *snake)
{

    for(int i = snake->length-1; i>0; i--)
    {
        snake->x[i]=snake->x[i-1];
        snake->y[i]=snake->y[i-1];
    }

    snake->x[0]+=snake->dx;
    snake->y[0]+=snake->dy;

}

void growSnake(Snake *snake)
{
    if(snake->length < MAX_LENGTH)
    {
        snake->length++;
    }
}

void drawSnake(SDL_Renderer *renderer, Snake *snake)
{

    SDL_SetRenderDrawColor(
        renderer,
        0,
        255,
        0,
        255
    );

    for(int i=0;i<snake->length;i++)
    {
        SDL_Rect block =
        {
            snake->x[i],
            snake->y[i],
            BLOCK,
            BLOCK
        };


        SDL_RenderFillRect(renderer,&block);
    }

}

void changeDirection(Snake *snake, SDL_Event event)
{

    switch(event.key.keysym.sym)
    {

        case SDLK_UP:
            snake->dx=0;
            snake->dy=-BLOCK;
            break;


        case SDLK_DOWN:
            snake->dx=0;
            snake->dy=BLOCK;
            break;


        case SDLK_LEFT:
            snake->dx=-BLOCK;
            snake->dy=0;
            break;


        case SDLK_RIGHT:
            snake->dx=BLOCK;
            snake->dy=0;
            break;

    }

}