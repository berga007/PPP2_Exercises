#include "GUI/Simple_window.h"  // get access to our windows lbrary
#include "GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    Point tl(100, 100);     // to become top left corner of the window

    Simple_window win(tl, 600, 400, "Canvas");  // make a simple window

    Polygon poly;   // make a shape (a polygon)

    poly.add(Graph_lib::Point(300, 200));  // add a point
    poly.add(Graph_lib::Point(350, 100));  // add another point
    poly.add(Graph_lib::Point(400, 200));  // add a third point

    poly.set_color(Graph_lib::Color::red); // adjust the properties of poly

    win.attach(poly);   // connects poly to the window

    win.wait_for_button();  // give control to the display engine
}