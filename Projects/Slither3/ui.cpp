#include "ui.h"

char border_char = (char)219; // Character used for the border
void init_ui() {
    // Initialize the user interface components here
    initscr(); // Initialize the ncurses screen
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // This will make getch non-blocking
    curs_set(0);
    clear();
    if(has_colors()){
        start_color();
        use_default_colors();
        init_pair(1, COLOR_GREEN, -1); // snake
        init_pair(2, COLOR_RED, -1); // food
        init_pair(3, COLOR_YELLOW, -1); // obstacles
        init_pair(4, COLOR_CYAN, -1); // border
    }
}

void tear_down_ui() {
    // Tear down the user interface components here
    // This may include cleaning up resources, closing windows, and other cleanup tasks
    endwin(); // End the ncurses session
}


void paint_border(int width, int height) {
    // Paint the border of the UI here
    // This may include drawing lines, boxes, or other visual elements to create a border
    int pair = has_colors() ? 4 : 0;
    for(int i = 0; i < width; i++) {
        if(pair) attron(COLOR_PAIR(pair));
        mvaddch(0, i, border_char); // Top border
        mvaddch(height - 1, i, border_char); // Bottom border
        if(pair) attroff(COLOR_PAIR(pair));
    }
    for(int i = 0; i < height; i++) {
        if(pair) attron(COLOR_PAIR(pair));
        mvaddch(i, 0, border_char); // Left border
        mvaddch(i, width - 1, border_char); // Right border
        if(pair) attroff(COLOR_PAIR(pair));
    }
    //getch(); // Wait for user input before proceeding
}