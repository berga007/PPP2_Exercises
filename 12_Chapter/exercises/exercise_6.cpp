// Exercise 6 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities

using namespace Graph_lib;  // our graphics facilities are in Graph_lib

void ex6_1()
{

    Point tl(400, 400); // to become top left corner of the window
    
    Simple_window win(tl, 800, 500, "Canvas");  // make a simple window

    // shape that does not fit in the window
    Rectangle rec(Point(100, 100), 850, 500);

    win.attach(rec);
    win.wait_for_button();
}

void ex6_2()
{
    Point tl(400, 400);
    // window which does not fit in the screen
    Simple_window win(tl, 3500, 4000, "Big window");

    win.wait_for_button();
}

int main()
{
    ex6_2();
}
