#include "snake.h"

#include <deque>
#include <utility>
#include <vector>
#include <curses.h>

static std::deque<std::pair<int,int>> body;
static bool growing = false;

void init_snake(){
    body.clear();
    // start near the center
    int start_row = LINES/2;
    int start_col = COLS/2;
    body.push_back({start_row, start_col});
    body.push_back({start_row+1, start_col});
    body.push_back({start_row+2, start_col});
    growing = false;
}

void move_snake(int direction){
    if(body.empty()) return;
    auto head = body.front();
    int r = head.first;
    int c = head.second;
    if(direction == 'w') r -= 1;
    else if(direction == 's') r += 1;
    else if(direction == 'a') c -= 1;
    else if(direction == 'd') c += 1;

    body.push_front({r,c});
    if(!growing) body.pop_back();
    else growing = false;
}

void grow_snake(){
    growing = true;
}

void print_snake(){
    // draw each segment (head first)
    bool first = true;
    for(auto &p : body){
        if(first){
            if(has_colors()) attron(COLOR_PAIR(1) | A_BOLD);
            mvaddch(p.first, p.second, 'O');
            if(has_colors()) attroff(COLOR_PAIR(1) | A_BOLD);
            first = false;
        } else {
            if(has_colors()) attron(COLOR_PAIR(1));
            mvaddch(p.first, p.second, 'o');
            if(has_colors()) attroff(COLOR_PAIR(1));
        }
    }
}

std::pair<int,int> get_snake_head(){
    if(body.empty()) return {0,0};
    return body.front();
}

bool check_self_collision(){
    if(body.size() < 4) return false;
    auto head = body.front();
    auto it = body.begin();
    ++it; // skip head
    for(; it != body.end(); ++it){
        if(*it == head) return true;
    }
    return false;
}

std::vector<std::pair<int,int>> get_snake_body(){
    return std::vector<std::pair<int,int>>(body.begin(), body.end());
}