// Exercise 2 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

// Define class Box which draws a rounded rectangle

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 800, 1000, "Box class");

    Box b1{Point{30,30}, 100, 80};

    win.attach(b1);

    win.wait_for_button();
}