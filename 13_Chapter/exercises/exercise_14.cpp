// Exercise 14 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    const Point tl{100,100};
    Simple_window win{tl, 1000, 1000, "Exercise 14"};

    // origin of the octagon
    const Point oct_origin{500, 500};
    // length
    const int oct_len{100};

    Vector_ref<Right_triangle> vr;
    for(int i=0; i<9; ++i){
        Point p0{oct_origin};
        Point p1(oct_origin.x+round(oct_len*cos(i*pi/4)), oct_origin.y+round(oct_len*sin(i*pi/4)));
        Point p2(oct_origin.x+round(oct_len*cos((i+1)*pi/4)), oct_origin.y+round(oct_len*sin((i+1)*pi/4)));

        // calculating the middle point between p1 and p2

        // vector between point 1 and 2
        Point p1p2{p2.x-p1.x, p2.y-p1.y};

        // middle point
        Point p3(round(p1.x + 0.5*p1p2.x), round(p1.y + 0.5*p1p2.y));

        vr.push_back(new Right_triangle{p0, p1, p3});
        vr[vr.size()-1].set_fill_color(Color::blue);
        win.attach(vr[vr.size()-1]);


        vr.push_back(new Right_triangle{p0, p3, p2});
        vr[vr.size()-1].set_fill_color(Color::yellow);
        win.attach(vr[vr.size()-1]);
    }

    Circle c1{oct_origin, oct_len};

    win.attach(c1);

    win.wait_for_button();

}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}