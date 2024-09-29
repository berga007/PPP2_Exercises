// Exercise 5 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 5"};

    Striped_rectangle r1{Point{35, 35}, 40, 25};
    r1.set_fill_color(Color::blue);

    win.attach(r1);

    win.wait_for_button();
}
catch(exception& e)
{

}
catch(...)
{

}
