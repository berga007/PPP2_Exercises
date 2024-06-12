#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100,100);
    Simple_window win(x, 600, 400, "16x16 color matrix");

    Vector_ref<Rectangle> rect;

    Rectangle x{Point{100,200}, Point{200,300}};
    rect.push_back(x);  // add named

    rect.push_back(new Rectangle{Point{50,60}, Point{80,90}});  // add unnamed

    for(int i=0; i<rect.size()-1; ++i) rect[i].move(10, 10);    // use rect

    // color chart
    Vector_ref<Rectangle> vr;
    for(int i=0; i<16; ++i)
        for(int j=0; j<16; ++j){
            // each rectangle is 20x20
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            // set the color
            vr[vr.size()-1].set_fill_color(Color{i*16 + j});
            win.attach(vr[vr.size()-1]);
        }
}