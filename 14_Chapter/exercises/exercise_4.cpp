// Exercise 4 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 4"};

    Immobile_Circle c1{Point{250, 250}, 100};

    win.attach(c1);

    win.wait_for_button();

    // c1.move(10, 10);
}
catch(exception& e){

}
catch(...)
{

}