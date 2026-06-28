#include <iostream>
#include<curses.h>
#include "ui.h"
using namespace std;

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
    paint_border(COLS, LINES);
    tear_down_ui();
    return 0;
}