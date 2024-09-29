// Exercise 6 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities
 int main()
 try
 {
    Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 6"};

    Striped_circle st_circle{Point{250, 250}, 200};
    st_circle.set_fill_color(Color::blue);

    win.attach(st_circle);

    win.wait_for_button();

 }
 catch(exception& e)
 {

 }
 catch(...)
 {

 }