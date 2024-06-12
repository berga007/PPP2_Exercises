// Drill 1
// Chapter 13 from the book Programming: Principles and Practice Using C++

#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 800, 1000, "Drill");

    // make grid on the leftmost 800 by 800 part of the window
    int x_size = win.x_max();
    int y_size(800);

    int x_grid{100};
    int y_grid{100};

    Lines grid;

    for(int x=0; x<x_size; x+=x_grid)
        grid.add(Point(x, 0), Point(x, y_size));

    for(int y=0; y<y_size; y+=y_grid)
        grid.add(Point(0, y), Point(x_size, y));

    win.attach(grid);

    Vector_ref<Rectangle> rects;

    int y{0};

    float rec_width{100};
    float rec_height{100};

    for(int x=0; x<x_size; x+=x_grid)
    {
        rects.push_back(new Rectangle(Point(x,y), rec_width, rec_height));
        rects[rects.size()-1].set_fill_color(Color::red);
        rects[rects.size()-1].set_color(Color::invisible);
        win.attach(rects[rects.size()-1]);
        y +=y_grid;
    }

    Image img1{Point{2*x_grid, 0}, "./drills/Patch_Distintos.jpg"};
    img1.set_mask(Point{0,150}, 200, 200);
    
    Image img2{Point{0, 2*y_grid}, "./drills/Patch_Distintos.jpg"};
    img2.set_mask(Point{0,150}, 200, 200);

    Image img3{Point{4*x_grid, 2*y_grid}, "./drills/Patch_Distintos.jpg"};
    img3.set_mask(Point{0,150}, 200, 200);

    win.attach(img1);
    win.attach(img2);
    win.attach(img3);

    int n_moves{4};
    Image img4{Point{0, 4*y_grid}, "./drills/Patch_Distintos.jpg"};
    img4.set_mask(Point{0,150}, 100, 100);
    win.attach(img4);

    for(int i=0; i<n_moves; ++i)
    {
        win.wait_for_button();
        img4.move(x_grid, 0);
    }
}