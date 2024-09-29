// Exercise 2 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 2"};
    Rectangle r1{Point{100, 100}, 40, 60};

    win.attach(r1);

    // Trying to copy a Shape object
    // Should not work because the copy operator was declared deleted

    // Rectangle r2{r1};

    // An error at compile time is generated
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...)
{

}
