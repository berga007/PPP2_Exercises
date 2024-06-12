// Exercise 9 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()

try{
    const Point x(100, 100);
    Simple_window win(x, 1000, 1000, "Win full of hexagons");

    int hex_side{40};

    Vector_ref<Regular_hexagon> vr;

    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j){
            int y = round(sqrt(3)*hex_side*(i+0.5));
            vr.push_back(new Regular_hexagon{Point{hex_side*(2*j+1), y}, hex_side});
            win.attach(vr[vr.size()-1]);
        }

    win.wait_for_button();

}
catch(exception& e){

}
catch(...){

}