// Exercise 19 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    const Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 19"};

    Star s{Point{250, 250}, 7, 200, 2};
    s.set_color(Color::black);
    win.attach(s);
    win.wait_for_button();
    
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}