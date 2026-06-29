#include "game.h"
#include "settings_constants.h"
#include "snake.h"

int game_state = before_start;
int direction;
void start_game(){
    init_snake();
    // init_food();
    direction = up;
    game_state = after_start;
}

//int x,y;

void game_logic() {
    const char start_text[] = "Press space to start the game";
    int key = getch();

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
        if (key == up && direction != down) {
            direction = up;
        } else if (key == down && direction != up) {
            direction = down;
        } else if (key == left && direction != right) {
            direction = left;
        } else if (key == right && direction != left) {
            direction = right;
        }

        print_snake();
    }

    paint_border(COLS, LINES);
}
