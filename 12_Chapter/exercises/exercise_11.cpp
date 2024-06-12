// Exercise 11 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities
#include <cmath>                   // get access to trig functions

int main()
{
    using namespace Graph_lib;
    
    Point tl(200, 200);     // top left corner of window
    Simple_window win(tl, 1200, 800, "Exercise 11");

    // regular triangle
    float tri_length(500);  // length of each side
    Point tri_P1(600, 100);   // set the 1st point

    // 2nd point
    float y(sin(pi/3) * tri_length);
    float x_coord(tri_P1.x - tri_length/2);
    float y_coord(tri_P1.y + y);
    Point tri_P2(x_coord, y_coord);

    // 3rd point
    x_coord = tri_P1.x + tri_length/2;
    Point tri_P3(x_coord, y_coord);

    // compose triangle as Polygon with 3 points
    Polygon triangle;
    triangle.add(tri_P1);
    triangle.add(tri_P2);
    triangle.add(tri_P3);

    win.attach(triangle);

    // square
    float square_side(tri_P3.x-tri_P2.x);
    Point square_tl(tri_P2.x, tri_P1.y);

    Rectangle square(square_tl, square_side, square_side);
    
    win.attach(square);
    win.wait_for_button();
    
    // pentagon
}