// Exercise 5 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities
#include <iostream>

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl(400, 400); // to become top left corner of the window

    Simple_window win(tl, 1000, 600, "Canvas");  // make a simple window

    float rec_width(2 * x_max()/3);
    float rec_height(3 * y_max()/4);

    Rectangle rec(Point(20,20), rec_width, rec_height);

    Point frame_tl(44, 44);
    float frame_width(rec_width-48);
    float frame_height(rec_height-48);

    Rectangle frame(frame_tl, frame_width, frame_height);
    frame.set_color(Color::red);

    // attach to window
    win.attach(rec);
    win.attach(frame);
    win.set_label("Exercise 5");
    win.wait_for_button();
}