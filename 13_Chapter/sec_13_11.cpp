#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib
    constexpr Point x(100, 100);
    Simple_window win(x, 600, 400, "Closed polyline");

    Closed_polyline cpl = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };

    cpl.add(Point{100, 250});

    Text t{Point{200,200}, "A closed polyline which is not a polygon!"}
    t.set_color(Color::blue);

    win.attach(cpl);
    win.attach(t);
    win.wait_for_button();
}