// Exercise 1 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

// Define class Arc, which draws part of an ellipse

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 800, 1000, "Arc class");

    Arc a1{Point(400, 400), 50, 100, 0, 90};

    win.attach(a1);

    win.wait_for_button();
}