#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    // draw two lines
    constexpr Point x(100, 100);

    Simple_window win1(x, 600, 400, "two lines");

    Line horizontal(x, Point(200, 100)); // make a horizontal line
    Line vertical(Point(150, 50), Point(150, 150));    // make a vertical line

    win1.attach(horizontal);
    win1.attach(vertical);

    win1.wait_for_button();
}

