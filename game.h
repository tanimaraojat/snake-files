#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"


int checkCollision(Snake *snake);

int checkFood(Snake *snake, Food *food);


#endif