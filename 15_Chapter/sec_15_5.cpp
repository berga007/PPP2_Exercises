// Code for section 15.5 Approximation, of "Programming: Principles and Practice Using C++"

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
int fac(int n) // factorial(n); n!
{
    int r = 1;
    while(n>1){
        r*=n;
        --n;
    }
    return r;
}

//------------------------------------------------------------------------------
double term(double x, int n){   // nth term of the approximatiomation series
    return pow(x,n)/fac(n);
}

//------------------------------------------------------------------------------
double expe(double x, int n){   // sum of terms for x
    double sum = 0;
    for(int i=0; i<n; ++i) sum += term(x,i);
    return sum;
}

//------------------------------------------------------------------------------
int main()
try{

    constexpr int xmax = 600;   // window size
    constexpr int ymax = 400;

    constexpr int x_orig = xmax/2;  // position (0,0) is at the centre of window
    constexpr int y_orig = ymax/2;
    const Graph_lib::Point orig{x_orig, y_orig};

    constexpr int r_min = -10;  // range [-10, 11)
    constexpr int r_max = 11;

    constexpr int n_points = 400;   // no. of points used in range

    constexpr int x_scale = 30;     // scaling factors
    constexpr int y_scale = 30;

    Simple_window win{Point{100, 100}, xmax, ymax, "Aproximation of e^x"};

    constexpr int xlength = xmax - 40;  // make the axis a bit smaller than the window
    constexpr int ylength = ymax - 40;

    Graph_lib::Axis xaxis{Graph_lib::Axis::x, Graph_lib::Point{20, y_orig},
        xlength, xlength/x_scale, "one notch == 1"};

    Graph_lib::Axis yaxis{Graph_lib::Axis::y, Graph_lib::Point{x_orig, ylength+20},
        ylength, ylength/y_scale, "one notch == 1"};

    xaxis.set_color(Graph_lib::Color::red);
    yaxis.set_color(Graph_lib::Color::red);

    Function real_exp{exp, r_min, r_max, orig, 200, x_scale, y_scale};
    real_exp.set_color(Graph_lib::Color::blue);

    for(int n=0; n<50; ++n)
    {
        ostringstream ss;
        ss << "exp aproximation; n==" << n;
        win.set_label(ss.str());
        // get next aproximation:
        Function e{[n] (double x) -> double {return expe(x,n); },
            r_min, r_max, orig, 200, x_scale, y_scale};
        
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }

}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){
    std::cerr << "Unknown exception thrown...";
}

//------------------------------------------------------------------------------