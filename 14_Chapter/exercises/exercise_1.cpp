// Exercise 1 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{

    const Point tl{100, 100};
    Simple_window win{tl, 500, 500, "Exercise 1"};

    Smiley sm1{Point{20, 50}, 20};
    Frowny fr1{Point{90, 50}, 20};
    Hat_Frowny hfr{Point{200, 200}, 20};

    win.attach(sm1);
    win.attach(fr1);
    win.attach(hfr);

    win.wait_for_button();

    fr1.set_color(Color::blue);

    win.wait_for_button();

    return 0;
}
catch(exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    return 2;
}