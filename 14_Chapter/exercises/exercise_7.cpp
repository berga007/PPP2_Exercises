// Exercise 7 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities
int main()
try{
    Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 7"};

    Striped_closed_polyline strips{};
    strips.add(Point{20, 40});
    strips.add(Point{20, 240});
    strips.add(Point{120, 240});

    strips.set_fill_color(Color::blue);

    win.attach(strips);

    win.wait_for_button();
   
}
catch(exception& e){

}
catch(...){

}
