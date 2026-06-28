#include <SDL2/SDL.h>
#include "snake.h"
#include "food.h"
#include "game.h"

#define WIDTH 800
#define HEIGHT 600


int main(int argc, char *argv[])
{

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("SDL Init Failed: %s", SDL_GetError());
        return 1;
    }


    SDL_Window *window = SDL_CreateWindow(
        "Snake Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );


    if(window == NULL)
    {
        SDL_Log("Window Failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }


    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );


    if(renderer == NULL)
    {
        SDL_Log("Renderer Failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Snake snake;

    initSnake(&snake);

    Food food;

    generateFood(&food);

    int score = 0;
    int running = 1;

    SDL_Event event;

    while(running)
    {

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = 0;
            }

            if(event.type == SDL_KEYDOWN)
            {
                changeDirection(&snake,event);
            }
        }
        moveSnake(&snake);

        if(checkFood(&snake,&food))
        {
            growSnake(&snake);
            generateFood(&food);
            score++;
        }

        if(checkCollision(&snake))
        {
            running = 0;
        }

        SDL_SetRenderDrawColor(
            renderer,
            0,
            0,
            0,
            255
        );

        SDL_RenderClear(renderer);

        drawSnake(renderer,&snake);

        drawFood(renderer,&food);

        SDL_RenderPresent(renderer);

        SDL_Delay(100);
    }

    SDL_Log("Final Score: %d",score);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}