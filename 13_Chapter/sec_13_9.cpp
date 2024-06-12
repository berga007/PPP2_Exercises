#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    constexpr Point x(100, 100);

    Simple_window win(x, 600, 400, "Rectangles");

    Rectangle rect00{Point{150, 100}, 200, 100};
    Rectangle rect11{Point{50, 50}, Point{250, 150}};
    Rectangle rect12{Point{50, 150}, Point{250, 250}}; // just below rec11
    Rectangle rect21{Point{250,50}, 200, 100};         // just to the right of rec11
    Rectangle rect22{Point{250,150}, 200, 100};        // just below rec21

    // costumising some colors
    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);

    rect11.move(400, 0);    // to the right of rec21
    rect11.set_fill_color(Color::white);
    win.set_label("Rectangles 2");

    win.put_on_top(rect00);
    win.set_label("Rectangles 3")

    // removing the outline of the rectangle shapes
    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);

    win.wait_for_button();
}