#include "game.h"



int checkFood(Snake *snake, Food *food)
{

    if(
       snake->x[0]==food->x &&
       snake->y[0]==food->y
      )
    {
        return 1;
    }


    return 0;
}

int checkCollision(Snake *snake)
{

    if(
       snake->x[0]<0 ||
       snake->x[0]>=800 ||
       snake->y[0]<0 ||
       snake->y[0]>=600
      )
    {
        return 1;
    }

    for(int i=1;i<snake->length;i++)
    {
        if(
           snake->x[0]==snake->x[i] &&
           snake->y[0]==snake->y[i]
          )
        {
            return 1;
        }
    }

    return 0;
}