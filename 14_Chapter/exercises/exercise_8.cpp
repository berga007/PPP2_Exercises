// Exercise 8 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities
int main()
try{
    Point tl{100, 100};
    Simple_window win{tl, 600, 600, "Exercise 8"};

    Octagon oct{Point{200, 200}, 100};

    win.attach(oct);

    win.wait_for_button();
    
    std::cout << "\n<<<Tests to the class Octagon:\n";
    std::cout << "<<<Radius: " << oct.length() << '\n';
    std::cout << "<<<Number of points: " << oct.number_of_points() << '\n';
    std::cout << "<<<Center of the Octagon: " 
              << '<' << oct.center().x << ',' << oct.center().y << ">\n";

    std:: cout << "<<<Coordinates of 1st point: " << '<' << oct.point(0).x << ','
               << oct.point(0).y << ">\n";

    std::cout << '\n';

    oct.set_length(50);

    std::cout << "<<<New length: " << oct.length() << '\n';
    std::cout << "<<<New coordinates of 1st point: " 
              << '<' << oct.point(0).x << ',' << oct.point(0).y << ">\n";
    std::cout << "<<< Center of the Octagon: "
              << '<' << oct.center().x << ',' << oct.center().y << ">\n";
    
    oct.set_fill_color(Color::red);
    std::cout << "<<<Fill color has changed to " << oct.fill_color().as_int() << '\n';
    win.wait_for_button();

    oct.set_color(Color::blue);
    std::cout << "<<<Color has changed to: " << oct.color().as_int() << '\n';

    win.wait_for_button();

    oct.set_style(Line_style::dash);
    win.wait_for_button();

}
catch(exception& e){

}
catch(...){

}
