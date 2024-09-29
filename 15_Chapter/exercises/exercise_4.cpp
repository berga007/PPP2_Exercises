// Exercise 4 from Chapter 15 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
int main()
try{
    
    constexpr int xmax{600};        // window size
    constexpr int ymax{400};

    constexpr int xorig{xmax/2};    // (0,0) is at the window's centre
    constexpr int yorig{ymax/2};

    const Graph_lib::Point orig{xorig, yorig};

    constexpr int r_min{-10};
    constexpr int r_max{11};

    constexpr int x_scale{30};  // scaling factors
    constexpr int y_scale{30};

    constexpr int xlength = xmax - 40;  // axis a bit smaller than window
    constexpr int ylength = ymax - 40;

    Graph_lib::Window win{Graph_lib::Point{100, 100}, xmax, ymax, "Exercise 4"};
   

    Graph_lib::Point x_orig{xorig-xlength/2, yorig};
    Graph_lib::Point y_orig{xorig, yorig+ylength/2};

    // build the axes
    Graph_lib::Axis xaxis{Graph_lib::Axis::x, x_orig, xlength, xlength/x_scale, 
        "one notch == 1"};

    Graph_lib::Axis yaxis{Graph_lib::Axis::y, y_orig, ylength, ylength/y_scale,
        "one notch == 1"};

    xaxis.set_color(Graph_lib::Color::red);
    yaxis.set_color(Graph_lib::Color::red);

    // Graph the functions:
    Graph_lib::Function a{sin, r_min, r_max, orig, 100, x_scale, y_scale};
    a.set_style(Graph_lib::Line_style::dash);
    Graph_lib::Text a_label{Point{xorig-10, yorig+40}, "-- sin(x)"};

    Graph_lib::Function b{cos, r_min, r_max, orig, 100, x_scale, y_scale};
    Graph_lib::Text b_label{Point{xorig-10, yorig-50}, ".. cos(x)"};
    b.set_color(Graph_lib::Color::blue);
    b.set_style(Graph_lib::Line_style::dot);
    b_label.set_color(Graph_lib::Color::blue);

    Graph_lib::Function ab{[](double x) {return cos(x)+sin(x); }, r_min, r_max, orig, 100, x_scale, y_scale};
    Graph_lib::Text ab_label{Point{xorig-5, yorig-70}, "-. sin(x)+cos(x)"};
    ab.set_style(Graph_lib::Line_style::dashdot);
    ab.set_color(Graph_lib::Color::green);
    ab_label.set_color(Graph_lib::Color::green);

    Graph_lib::Function d{[](double x) {return pow(cos(x),2)+pow(sin(x),2); }, 
        r_min, r_max, orig, 100, x_scale, y_scale};
    Graph_lib::Text d_label{Point{xorig-5, yorig-90}, "-.. sin^2(x)+cos^2(x)"};
    d.set_style(Graph_lib::Line_style::dashdotdot);
    d.set_color(Graph_lib::Color::magenta);
    d_label.set_color(Graph_lib::Color::magenta);

    // attach shapes to the window
    win.attach(xaxis);
    win.attach(yaxis);

    win.attach(a);
    win.attach(a_label);

    win.attach(b);
    win.attach(b_label);

    win.attach(ab);
    win.attach(ab_label);

    win.attach(d);
    win.attach(d_label);

    // run the gui engine
    gui_main();

    return 0;
}
catch(exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    std::cerr << "Something went wrong somewhere";
    return 2;
}

//------------------------------------------------------------------------------