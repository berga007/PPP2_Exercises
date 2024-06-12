// Exercise 8 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()

try{
    using namespace Graph_lib;

    const Point x(100, 100);
    Simple_window win(x, 1000, 1000, "Regular Hexagon");

    Regular_hexagon hex{Point{100, 100}, 40};
    
    win.attach(hex);
    win.wait_for_button();
}
catch(exception& e){
    
}
catch(...){

}