#include "game.h"
#include "settings_constants.h"
#include "snake.h"
#include "food.h"

#include <utility>
#include <cstdlib>
#include <chrono>

int game_state = before_start;
int direction;
int score = 0;
bool game_over = false;

void start_game(){
    init_snake();
    init_food_and_obstacles(15);
    direction = up;
    score = 0;
    game_over = false;
    game_state = after_start;
}

void game_logic() {
    const char start_text[] = "Press space to start the game";
    int key = getch();

    static auto last_move = std::chrono::steady_clock::now();

    if (game_state == before_start) {
        int msg_x = (COLS - ((int)sizeof(start_text) - 1)) / 2;
        if (msg_x < 0) msg_x = 0;
        int msg_y = LINES / 2;
        move(msg_y, msg_x);
        addstr(start_text);

        if (key == ' ') {
            start_game();
        }
    } else {
        if(game_over){
            const char over_text[] = "Game Over! Press 'r' to restart or 'q' to quit";
            int msg_x = (COLS - ((int)sizeof(over_text) - 1)) / 2;
            int msg_y = LINES / 2;
            mvaddstr(msg_y, msg_x, over_text);
            mvprintw(msg_y+1, msg_x, "Score: %d", score);
            if(key == 'r') start_game();
            if(key == 'q') { endwin(); exit(0); }
            return;
        }

        if (key == up && direction != down) direction = up;
        else if (key == down && direction != up) direction = down;
        else if (key == left && direction != right) direction = left;
        else if (key == right && direction != left) direction = right;

        // Move snake only on move timer to control speed uniformly
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - last_move).count();
        if(elapsed >= SNAKE_MOVE_DELAY){
            move_snake(direction);
            last_move = now;
        }

        auto head = get_snake_head();
        // check border collision
        if(head.first <= 0 || head.first >= LINES-1 || head.second <= 0 || head.second >= COLS-1){
            game_over = true;
        }
        // check self collision
        if(check_self_collision()) game_over = true;
        // check obstacle collision
        if(is_obstacle(head)) game_over = true;

        // check food
        if(check_and_eat_food(head)){
            grow_snake();
            score += 10;
        }

        // draw elements
        draw_food();
        draw_obstacles();
        print_snake();

        // show score
        mvprintw(0,2, "Score: %d", score);
    }

    paint_border(COLS, LINES);
}
