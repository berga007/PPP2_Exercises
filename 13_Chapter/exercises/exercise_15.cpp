// Exercise 15 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    const Point tl{100, 100};
    Simple_window win{tl, 1000, 1000, "Exercise 15"};
    Vector_ref<Right_triangle> vr{};

    // number of triangles in the x direction
    int x_n_triangles{20};

    // number of triangles in the y direction
    int y_n_triangles{20};

    int base(round(win.x_max()/(2*x_n_triangles)));
    int height(round(win.y_max()/(2*y_n_triangles)));

    // initialise all points needed to build the 4 triangles
    Point p0{0, height};
    Point p1{base, 0};
    Point p2{base, height};
    Point p3{base, 2*height};
    Point p4{2*base, height};

    for(int i=0; i<y_n_triangles; ++i){
        for(int j=0; j<x_n_triangles; ++j){
            vr.push_back(new Right_triangle{p0, p1, p2});
            vr[vr.size()-1].set_fill_color(Color::blue);
            win.attach(vr[vr.size()-1]);

            vr.push_back(new Right_triangle{p1, p2, p4});
            vr[vr.size()-1].set_fill_color(Color::yellow);
            win.attach(vr[vr.size()-1]);

            vr.push_back(new Right_triangle{p0, p2, p3});
            vr[vr.size()-1].set_fill_color(Color::red);
            win.attach(vr[vr.size()-1]);

            vr.push_back(new Right_triangle{p2, p3, p4});
            vr[vr.size()-1].set_fill_color(Color::green);
            win.attach(vr[vr.size()-1]);
            
            // shift all points in the x direction by 2*base
            p0.x += 2*base;
            p1.x += 2*base;
            p2.x += 2*base;
            p3.x += 2*base;
            p4.x += 2*base;
        }
        
        // reset the x coordinate of all points as we will start a new row
        p0.x = 0;
        p1.x = base;
        p2.x = base;
        p3.x = base;
        p4.x = 2*base;

        // shift all points in the y direction by 2*height
        p0.y += 2*height;
        p1.y += 2*height;
        p2.y += 2*height;
        p3.y += 2*height;
        p4.y += 2*height;
    }
    win.wait_for_button();
}
catch(exception& e){

}
catch(...){

}
