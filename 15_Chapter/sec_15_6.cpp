// Code for section 15.6 Graphing Data, of "Programming: Principles and Practice Using C++"

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

using namespace Graph_lib;

struct Distribution{
    int year, young, adults, elders;
};

istream& operator>>(istream& is, Distribution& d){
    // read from is into d
    // each "entry" has the format (year: young adults elders)
    char ch1, ch2, ch3;
    int year, children, adults, elders;

    if(is >> ch1 && ch1 != '('){
        is.unget(); // put the character back into the stream
        is.clear(ios_base::failbit);
        return is;
    }

    if(is>>year>>ch2>>children>>adults>>elders>>ch3){
        if(ch2 !=':' || ch3!=')'){
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else{
        return is; 
    }
    d.year = year;
    d.young = children;
    d.adults = adults;
    d.elders = elders;

    return is;
}

class Scale{    // data value to coordinate conversion
    int cbase;  // coordinate base
    int vbase;  // base of values
    double scale;
public: 
    Scale(int cb, int vb, double s)
        :cbase{cb}, vbase{vb}, scale{s} { }
    
    double operator() (int v){
        return (v-vbase)*scale + cbase;
    }
};

int main()
try{
    constexpr int xmax{600}; // window size
    constexpr int ymax{400};
    constexpr int xoffset{100}; // distance from left side of window
    constexpr int yoffset{60};  // distamce from bottom of window to x axis
    constexpr int xspace{40};   // space beyond axis
    constexpr int yspace{40};

    // Length of axes
    constexpr int xlength{xmax-xspace-xoffset};
    constexpr int ylength{ymax-yoffset-yspace};

    constexpr int base_year{1960};
    constexpr int end_year{2040};
    constexpr double xscale{double{xlength}/(end_year-base_year)};
    constexpr double yscale{double{ylength}/100};

    // scales
    Scale xs{xoffset, base_year, xscale};
    Scale ys{ymax-yoffset, 0, -yscale};

    // Window
    Graph_lib::Window win{Point{100, 100}, xmax, ymax, "Aging Japan"};

    // Axis
    Axis xaxis{Axis::x, Point{xoffset, ymax-yoffset}, xlength, 
        end_year-base_year/10,
        "year    1960   1970    1980    1990    "
        "2000   2010    2020    2030    2040    "};

    Axis yaxis{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 10,
        "% of population"};

    // Make a vertical line in the year 2008
    Line current_year{Point{xs(2008), ys(0)}, Point{xs(2008), ys(100)}};
    current_year.set_style(Line_style::dash);

    // one Open_polyline per age group
    Open_polyline children;
    Open_polyline adults;
    Open_polyline elders;

    // reading loop
    string filename{"japanese-age-data.txt"};
    ifstream ifs{filename};

    if(!ifs) error("File not found", filename);

    for(Distribution d; ifs>>d; ){
        // some basic checks to verify data integrity
        if(d.year < base_year || d.year>end_year) error("Year outside range");
        if(d.young+d.adults+d.elders != 100)
            error("Group percentages don't add to 100");

        // adding points to each Open_polyline
        const int x{xs(d.year)};    // convert year to x coordinate

        children.add(Point{x, ys(d.young)});
        adults.add(Point{x, ys(d.adults)});
        elders.add(Point{x, ys(d.elders)});

    }

    // adding some labels
    Text children_label{Point{-20, children.point(0).y}, "0-14"};
    children.set_color(Color::red);
    children_label.set_color(Color::red);

    Text adults_label{Point{-20, adults.point(0).y}, "15-64"};
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);

    Text elders_label{Point{-20, elders.point(0).y}, "65+"};
    elders.set_color(Color::green);
    elders_label.set_color(Color::green);

    // attach shapes to window
    win.attach(children);
    win.attach(children_label);
    win.attach(adults);
    win.attach(adults_label);
    win.attach(elders);
    win.attach(elders_label);

    win.attach(current_year);
    win.attach(xaxis);
    win.attach(yaxis);

    // calling the GUI engine
    gui_main();
    return 0;
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}