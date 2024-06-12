#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100, 100);
    Simple_window win(x, 600, 400, "circles");

    Circle c1{Point{100, 200}, 50};
    Circle c2{Point{150, 200}, 100};
    Circle c3{Point{200, 200}, 150};

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    win.wait_for_button();
}