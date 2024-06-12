// code from section 12.7 of Programming: Principles and Practice
// Using C++ by Bjarne Stroustrup

#include <stdexcept>

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

int main()
try
{
    Point tl(100, 100); // top left corner of our window

    Simple_window win(tl, 600, 400, "Canvas");
    // screen coordinate tl for top left corner
    // windows size (600*400)
    // title: Canvas

    Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");    // make an Axis
        // an Axis is a kind of Shape
        // Axis::x means horizontal
        // starting at (20, 300)
        // 280 pixels long
        // 10 "notches"
        // label the axis "x axis"

    win.attach(xa); // attach xa to the window, win


    Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
    ya.set_color(Color::cyan);  // choose a color
    ya.label.set_color(Color::dark_red);    // choose a color for the text  
    
    win.attach(ya);

    Function sine(sin, 0, 100, Point(20,150), 1000, 50, 50); // sine curve
    // plot sin() in the range [0: 100) with (0,0) at (20,150)

    win.attach(sine);

    sine.set_color(Color::blue);    // we changed our mind about sine's color

    Polygon poly;                   // a polygon; a Polygon is a kind of Shape
    poly.add(Point(300, 200));       // three points make a triangle
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));

    poly.set_color(Color::red);
    poly.set_style(Line_style:: dash);
    win.attach(poly);

    Rectangle r(Point(200, 200), 150, 50);  // top left corner, width and height
    
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point(100, 50));
    poly_rect.add(Point(200, 50));
    poly_rect.add(Point(200, 100));
    poly_rect.add(Point(100, 100));
    poly_rect.add(Point(50, 75));

    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);    // colour the inside of the rectangle
    poly.set_style(Line_style(Line_style:: dash, 4));
    poly_rect.set_fill_color(Color::green);
    poly_rect.set_style(Line_style(Line_style::dash, 2));

    Text t(Point(150, 150), "Hello Graphical World!");
    win.attach(t);

    t.set_font(Font::times_bold);
    t.set_font_size(20);

    Image ii(Point(100, 50), "image.jpg");  // 400*212 pixel jpg
    win.attach(ii);

    ii.move(100, 200);

    Circle c(Point(100, 200), 50);
    Ellipse e(Point(100, 200), 75, 25);
    e.set_color(Color::dark_red);
    Mark m(Point(100, 200), 'x');

    ostringstream oss;

    oss << "screen size: " << x_max() << "*" << y_max()
        << " ; window size: " << win.x_max() << "*" << win.y_max();

    Text sizes (Point(100, 20),oss.str());

    Image cal(Point(225, 225), "snow_cpp.gif");   // 320*240-pixel gif
    cal.set_mask(Point(40, 40), 200, 150);  // display centre part of image

    win.attach(c);
    win.attach(e);
    win.attach(m);
    win.attach(sizes);
    win.attach(cal);

    win.set_label("Canvas #12");

    win.wait_for_button();  // display!
}
catch(exception& e){
    return 1;
}
catch(...){
    return 2;
}