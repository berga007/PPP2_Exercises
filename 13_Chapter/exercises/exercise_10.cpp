// Exercise 10 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()

try{
    const Point x(100, 100);
    Simple_window win(x, 1000, 1000, "Regular polygon");

    int n_sides{8};
    int length{50};

    Regular_polygon pent{Point{100, 100}, n_sides, length};
    
    win.attach(pent);
    win.wait_for_button();

}
catch(exception& e){

}
catch(...){

}