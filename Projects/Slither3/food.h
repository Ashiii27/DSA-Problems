#ifndef  DEF_FOOD
#define DEF_FOOD

#include <utility>
#include <vector>

void init_food_and_obstacles(int obstacle_count=10);
std::pair<int,int> get_food_pos();
void draw_food();
bool check_and_eat_food(const std::pair<int,int>& head);
void draw_obstacles();
bool is_obstacle(const std::pair<int,int>& pos);

#endif