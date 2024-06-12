#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100, 100);
    Simple_window win(x, 600, 400, "ellipses");

    Ellipse e1{Point{200,200}, 50,50};
    Ellipse e2{Point{200,200}, 100, 50};
    Ellipse e3{Point{200,200},100, 150};

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);

    win.wait_for_button();
}