#include "food.h"
#include <curses.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

static std::pair<int,int> food_pos = {0,0};
static std::vector<std::pair<int,int>> obstacles;

static bool overlaps_with_obstacle_or_food(int r, int c){
	if(food_pos.first == r && food_pos.second == c) return true;
	for(auto &o : obstacles) if(o.first == r && o.second == c) return true;
	return false;
}

void init_food_and_obstacles(int obstacle_count){
	srand((unsigned)time(nullptr));
	// spawn food
	int h = LINES;
	int w = COLS;
	do{
		food_pos.first = 1 + rand() % (h-2);
		food_pos.second = 1 + rand() % (w-2);
	} while(false);

	// spawn obstacles
	obstacles.clear();
	for(int i=0;i<obstacle_count;i++){
		int r,c;
		do{
			r = 1 + rand() % (h-2);
			c = 1 + rand() % (w-2);
		} while(overlaps_with_obstacle_or_food(r,c));
		obstacles.push_back({r,c});
	}
}

std::pair<int,int> get_food_pos(){
	return food_pos;
}

void draw_food(){
	if(has_colors()) attron(COLOR_PAIR(2) | A_BOLD);
	mvaddch(food_pos.first, food_pos.second, '@');
	if(has_colors()) attroff(COLOR_PAIR(2) | A_BOLD);
}

bool check_and_eat_food(const std::pair<int,int>& head){
	if(head == food_pos){
		// relocate food to a new random empty cell
		int h = LINES;
		int w = COLS;
		int r,c;
		do{
			r = 1 + rand() % (h-2);
			c = 1 + rand() % (w-2);
		} while(overlaps_with_obstacle_or_food(r,c));
		food_pos = {r,c};
		return true;
	}
	return false;
}

void draw_obstacles(){
	for(auto &o : obstacles) {
		if(has_colors()) attron(COLOR_PAIR(3) | A_BOLD);
		mvaddch(o.first, o.second, '#');
		if(has_colors()) attroff(COLOR_PAIR(3) | A_BOLD);
	}
}

bool is_obstacle(const std::pair<int,int>& pos){
	for(auto &o : obstacles) if(o == pos) return true;
	return false;
}
