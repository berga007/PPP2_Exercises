#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100, 100);
    Simple_window win(x, 600, 400, "marked polyline");

    Marked_polyline mpl{"1234"};
    mpl.add(Point{100,100});
    mpl.add(Point{150,200});
    mpl.add(Point{250,250});
    mpl.add(Point{300,200});

    win.attach(mpl);
    win.wait_for_button();
}