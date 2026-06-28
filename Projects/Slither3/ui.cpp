#include "ui.h"

char border_char = (char)219; // Character used for the border
void init_ui() {
    // Initialize the user interface components here
    // This may include setting up windows, buttons, and other UI elements
    initscr(); // Initialize the ncurses screen
}

void tear_down_ui() {
    // Tear down the user interface components here
    // This may include cleaning up resources, closing windows, and other cleanup tasks
    endwin(); // End the ncurses session
}


void paint_border(int width, int height) {
    // Paint the border of the UI here
    // This may include drawing lines, boxes, or other visual elements to create a border
    for(int i = 0; i < width; i++) {
        mvaddch(0, i, border_char); // Top border
        mvaddch(height - 1, i, border_char); // Bottom border
    }
    for(int i = 0; i < height; i++) {
        mvaddch(i, 0, border_char); // Left border
        mvaddch(i, width - 1, border_char); // Right border
    }
    getch(); // Wait for user input before proceeding
}