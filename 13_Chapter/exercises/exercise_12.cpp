// Exercise 12 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    const Point tl{100,100};
    Simple_window win{tl, 1000, 1000, "Exercise 12"};

    Circle c1{Point{500, 500}, 100};
    win.attach(c1);
    
    for(int i=0; i<8; ++i){
        int x = c1.center().x + c1.radius()*cos(i*2*pi/8);
        int y = c1.center().x + c1.radius()*sin(i*2*pi/8);
        Mark m1{Point{x,y}, 'x'};

        win.attach(m1);
        win.wait_for_button();
    }

}
catch(exception& e){

}
catch(...){

}