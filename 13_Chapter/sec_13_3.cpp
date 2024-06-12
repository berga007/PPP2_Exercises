#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    constexpr Point x(100, 100);

    Simple_window win3(x, 600, 400, "grid");

    int x_size = win3.x_max();  // get size of window
    int y_size = win3.y_max();

    int x_grid = 80;
    int y_grid = 40;

    Lines grid;

    for(int x = x_grid; x<x_size; x+=x_grid)
        grid.add(Point(x, 0), Point(x, y_size));    // vertical line

    for(int y = y_grid; y<y_size; y+=y_grid)
        grid.add(Point(0, y), Point(x_size, y));    // horizontal line

    // costumising the grid color and line style
    grid.set_color(Color::red);
    grid.set_style(Line_style(Line_style::dash, 2));
    
    win3.attach(grid);

    win3.wait_for_button();
    
}