// Exercise 1 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl(100, 100); // to become top left corner of the window

    Simple_window win(tl, 600, 400, "Canvas");  // make a simple window

    Rectangle rect(Point(200, 200), 100, 50);
    rect.set_color(Color::blue);

    Polygon poly;   // make a shape (a polygon)
    poly.add(Point(250, 250));
    poly.add(Point(250, 350));
    poly.add(Point(300, 350));
    poly.add(Point(300, 250));

    poly.set_color(Color::red);

    win.attach(rect);
    win.attach(poly);

    win.set_label("Exercise 1");

    win.wait_for_button();  // display
}