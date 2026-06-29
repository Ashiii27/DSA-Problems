#include <iostream>
#include <curses.h>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "settings_constants.h"

using namespace std;



void event_loop() {
    // Implement the event loop here
    // This may include handling user input, updating game state, and rendering the UI
    // auto last_time = chrono::system_clock::now();
    int dt;
    while (true) {
        auto last_time = chrono::system_clock::now();
        // Handle other input and update game state as needed
        erase(); // Clear the screen before repainting
        game_logic(); // Call the game logic function to update the game state
        refresh();// Refresh the screen to display updates
        

        do {
            auto current_time = chrono::system_clock::now();
            dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
        } while (dt < TIME_DELAY_BETWEEN_FRAMES);
    }
}

int main() {
    // int width = 20;
    // int height = 20;

    // for(int i = 0 ; i < width-1 ; i++) {
    //     cout<<"# ";
    // }
    // cout<<endl;
    // for(int i =1 ; i < height-1 ; i++){
    //     cout<<"#";
    //     for(int j = 1 ; j < width-1 ; j++){
    //         cout<<"  ";
    //     }
    //     cout<<"#";
    //     cout<<endl;
    // }
    
    // for(int i = 0 ; i < width-1 ; i++) {
    //     cout<<"# ";
    // }
    // cout<<endl;

    init_ui();
    event_loop(); // Start the event loop to handle user input and game logic
    tear_down_ui();
    return 0;
}