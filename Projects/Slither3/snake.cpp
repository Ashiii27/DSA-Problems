#include "snake.h"

int x,y;

void init_snake(){
    x = 10;
    y = 10;
}

void print_snake(){
    move(x,y);
    addch('#');
}