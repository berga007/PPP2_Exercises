// Drills from Ch. 12 A Display Model from the book
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

// #include "std_lib_facilities.h"

#include "GUI/Simple_window.h" 
#include "GUI/Graph.h"

int main()
try{
    using namespace Graph_lib;  // graphics facilities are in Graph_lib
    Point tl(100, 100); // to become top left corner of the window

    Simple_window win(tl, 600, 400, "Canvas"); // make a simple window
    // screen coordinate tl for top left corner
    // window size (600*400)
    // title: Canvas

    win.wait_for_button();  // give control to the display engine
}

catch(exception& e){
    return 1;
}
catch(...){
    return 2;
}