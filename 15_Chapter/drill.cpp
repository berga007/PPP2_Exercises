// Drill from Chapter 15 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------

double one(double){ return 1;}

double sloping_cos(double x){ return x/2 + cos(x) ;}

int main()
try{

    constexpr int xmax{600};    // window size
    constexpr int ymax{400};

    const Graph_lib::Point orig{300,300};

    constexpr int r_min{-10};
    constexpr int r_max{11};

    Graph_lib::Window win{Graph_lib::Point{100, 100}, 
        600, 400, "Function graphs"};
    int length{400};

    Graph_lib::Point x_orig{orig.x-length/2, orig.y};
    Graph_lib::Point y_orig{orig.x, orig.y+length/2};

    // build the axes
    Graph_lib::Axis xaxis{Graph_lib::Axis::x, x_orig, length, length/20, 
        "1==20 pixels"};

    Graph_lib::Axis yaxis{Graph_lib::Axis::y, y_orig, length, length/20,
        "1==20 pixels"};

    xaxis.set_color(Graph_lib::Color::red);
    yaxis.set_color(Graph_lib::Color::red);

    // Function
    Graph_lib::Function s{one, r_min, r_max, orig, 400, 20, 20};
    
    Graph_lib::Function s1{[] (double x) {return x/2; }, r_min, r_max, orig, 400, 20, 20};
    // Convert point (-10, -5) to coordinates in the screen
    Graph_lib::Point s1_bl{int(orig.x+20*-10), int(orig.y-20*-5-10)};
    Graph_lib::Text s1_label{s1_bl, "x/2"};

    // f(x) = x^2
    Graph_lib::Function s2{[] (double x){return x*x; }, r_min, r_max, orig, 400, 20, 20};

    // f(x) = cos()
    Graph_lib::Function s3{cos, r_min, r_max, orig, 400, 20, 20};
    s3.set_color(Graph_lib::Color::blue);

    Graph_lib::Function s4{sloping_cos, r_min, r_max, orig, 400, 20, 20};

    // attach shapes to window
    win.attach(xaxis);
    win.attach(yaxis);
    win.attach(s);
    win.attach(s1);
    win.attach(s1_label);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);

    // call the GUI engine
    Graph_lib::gui_main();
}
catch(exception& e){
    std::cerr<<e.what();
}
catch(...){

}