// Exercise 5 from Chapter 15 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
// class Scale to convert from x or y values to coordinates
class Scale{    // data value to coordinate conversion
    int cbase;  // coordinate base
    int vbase;  // base of values
    double scale;
public: 
    Scale(int cb, int vb, double s)
        :cbase{cb}, vbase{vb}, scale{s} { }
    
    int operator() (double v){
        return int((v-vbase)*scale + cbase);
    }
};

//------------------------------------------------------------------------------
double leibniz(int n){
    // series: 1 - 1/3 + 1/5 /1/7 + 1/9 - 1/11
    double sum{0.00};
    for(int i=0; i<n; ++i){
        double term{pow(-1, i)*1/double(1+2*i)};
        sum += term;
    }

    return sum;
}

//------------------------------------------------------------------------------

int main()
try{

    constexpr int xmax{800};
    constexpr int ymax{800};

    constexpr int x_orig = xmax/2;  // origin (0,0) will be at the centre of the window
    constexpr int y_orig = ymax/2;

    Simple_window win{Point{x_orig, y_orig}, xmax, ymax, "Leibniz Series"};

    constexpr int r_min{0};
    constexpr int r_max{20};
    constexpr int xscale{25};
    constexpr int yscale{25};

    // Scales for xaxis and yaxis
    Scale xs{x_orig, 0, xscale};
    Scale ys{y_orig, 0, -yscale};

    // Axis
    constexpr int length{600};
    Graph_lib::Axis xaxis{Axis::x, Point{x_orig-length/2, y_orig}, length, 
        length/xscale, "one notch == 1"};
    Graph_lib::Axis yaxis{Axis::y, Point{x_orig, y_orig+length/2}, 
        length, length/yscale,"one notch == 1"};

    xaxis.set_color(Graph_lib::Color::red);
    yaxis.set_color(Graph_lib::Color::red);

    // horizontal line at y == pi/4
    Graph_lib::Line pi_4{Point{x_orig-length/2, ys(pi/4)}, Point{x_orig+length/2, ys(pi/4)}};
    pi_4.set_color(Color::black);
    pi_4.set_style(Graph_lib::Line_style::dash);

    // add a label
    Graph_lib::Text pi_4_label{Graph_lib::Point{xs(0)+8, ys(pi/4)-4}, "pi/4"};

    win.attach(xaxis);
    win.attach(yaxis);
    win.attach(pi_4);
    win.attach(pi_4_label);

    // Open polyline to hold the value of the sum of leibniz series with n elements
    Graph_lib::Open_polyline opl{};
    opl.set_color(Graph_lib::Color::blue);

    for(int n=0; n<11; ++n){
        win.attach(opl);
        ostringstream ss;
        ss << "Leibniz series; n==" << n;
        win.set_label(ss.str());

        // get next approximation:
        double y = leibniz(n);

        // add (n,y) to the OpenPolyline
        // convert the 'math' values to pixels on the screen using scale objects
        opl.add(Graph_lib::Point{xs(n), ys(y)});

        win.wait_for_button();
    }
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){
    std::cerr << "Unknown exception occurred";
}