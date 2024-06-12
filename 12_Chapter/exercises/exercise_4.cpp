// Exercise 4 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities
#include <iostream>

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl(400, 400); // to become top left corner of the window

    Simple_window win(tl, 600, 400, "Canvas");  // make a simple window

    int grid_size(3);

    float width(win.x_max()/grid_size);
    float height(win.y_max()/grid_size);

    Point rec_tl(0,0);
    
    // defining the rectangles
    Rectangle rec_1(rec_tl, width, height);
    rec_1.set_fill_color(Color::red);

    rec_tl.x = win.x_max()/3;
    Rectangle rec_2(rec_tl, width, height);
    rec_2.set_fill_color(Color::white);

    rec_tl.x *= 2;
    Rectangle rec_3(rec_tl, width, height);
    rec_3.set_fill_color(Color::red);

    rec_tl.x = 0;
    rec_tl.y = win.y_max()/3;
    Rectangle rec_4(rec_tl, width, height);
    rec_4.set_fill_color(Color::white);

    rec_tl.x = win.x_max()/3;
    Rectangle rec_5(rec_tl, width, height);
    rec_5.set_fill_color(Color::red);

    rec_tl.x *= 2;
    Rectangle rec_6(rec_tl, width, height);
    rec_6.set_fill_color(Color::white);

    rec_tl.x = 0;
    rec_tl.y *= 2;
    Rectangle rec_7(rec_tl, width, height);
    rec_7.set_fill_color(Color::red);

    rec_tl.x = win.x_max()/3;
    Rectangle rec_8(rec_tl, width, height);
    rec_8.set_fill_color(Color::white);

    rec_tl.x *= 2;
    Rectangle rec_9(rec_tl, width, height);
    rec_9.set_fill_color(Color::red);

    // Attach all rectangles to window
    win.attach(rec_1);
    win.attach(rec_2);
    win.attach(rec_3);
    win.attach(rec_4);
    win.attach(rec_5);
    win.attach(rec_6);
    win.attach(rec_7);
    win.attach(rec_8);
    win.attach(rec_9);

    win.set_label("Exercise 4");

    win.wait_for_button();  // display
    
}