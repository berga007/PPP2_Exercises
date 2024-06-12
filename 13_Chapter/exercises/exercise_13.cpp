// Exercise 13 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    const Point tl{100,100};
    Simple_window win{tl, 1000, 1000, "Exercise 13"};
 
    Vector_ref<Rectangle> vr;
    for(int i=0; i<16; ++i)
        for(int j=0; j<16; ++j){
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            vr[vr.size()-1].set_color(Color::invisible);
            win.attach(vr[vr.size()-1]);
        }
    
    win.wait_for_button();

}
catch(exception& e){

}
catch(...){

}