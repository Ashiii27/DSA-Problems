#ifndef  DEF_SNAKE
#include <curses.h>
#include <deque>
#include <utility>
#include <vector>

#define DEF_SNAKE

void init_snake();
void move_snake(int direction);
void print_snake();
std::pair<int,int> get_snake_head();
void grow_snake();
bool check_self_collision();
std::vector<std::pair<int,int>> get_snake_body();

#endif