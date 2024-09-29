// Exercise 10 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities
int main()
try{
    Point tl{200, 200};
    Simple_window win{tl, 500, 500, "Exercise 10"};

    Pseudo_window pwin{Point{100, 100}, 300, 300, "Pseudo window"};

    win.attach(pwin);

    win.wait_for_button();
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}