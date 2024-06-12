// Exercise 3 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

// Define class arrow, which draws a line with an arrowhead

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 800, 1000, "Arrow class");

    Arrow a1{Point{10, 100}, Point{20, 200}};

    win.attach(a1);

    win.wait_for_button();
}