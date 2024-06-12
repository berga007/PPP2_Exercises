#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib

    constexpr Point x(100, 100);

    Simple_window win(x, 600, 400, "Open polyline");

    Open_polyline opl = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };

    win.attach(opl);
    win.wait_for_button();
}