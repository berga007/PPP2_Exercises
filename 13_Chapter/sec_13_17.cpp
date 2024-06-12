#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100, 100);
    Simple_window win(x, 600, 400, "Images: Rita 9/21/05 4pm CDT Wednesday");

    Image rita{Point{0,0}, "rita.jpg"};
    Image path{Point{0,0}, "rita_path.gif"};
    path.set_mask(Point{50,250}, 600,400);   // select likely landfall

    win.attach(path);
    win.attach(rita);

    win.wait_for_button();
}