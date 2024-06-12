// Exercise 6 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

// Define class arrow, which draws a line with an arrowhead

int main()
{
    using namespace Graph_lib;
    const Point x(100, 100);
    Simple_window win(x, 800, 1000, "Class diagrams");

    string s1{"Shape"};
    string s2{"Line"};
    string s3{"Lines"};
    string s4{"Polygon"};
    string s5{"Axis"};
    string s6{"Rectangle"};
    string s7{"Text"};
    string s8{"Image"};

    Textbox shape{Point{400, 500}, 50, 24, s1};

    // get the points to connect to
    Point low_left = sw(shape);
    Point bottom = s(shape);
    Point low_right = se(shape);

    // make the derived classes boxes
    Textbox line{Point{200, 800}, 50, 24, s2};
    Textbox lines{Point{270, 800}, 50, 24, s3};
    Textbox polygon{Point{340, 800}, 60, 24, s4};
    Textbox axis{Point{420, 800}, 50, 24, s5};
    Textbox rectangle{Point{490, 800}, 70, 24, s6};
    Textbox text{Point{580, 800}, 50, 24, s7};
    Textbox image{Point{650, 800}, 50, 24, s8};

    // draw the connecting lines
    Point up_line{n(line).x, n(line).y-4};
    Arrow l1{up_line, Point{low_left.x, low_left.y+6}};

    Point up_lines{n(lines).x, n(lines).y-4};
    Arrow l2{up_lines, Point{low_left.x+4, low_left.y+6}};

    Point up_poly{n(polygon).x, n(polygon).y-4};
    Arrow l3{up_poly, Point{low_left.x+8, low_left.y+6}};

    Point up_axis{n(axis).x, n(axis).y-4};
    Arrow l4{n(axis), Point{bottom.x, bottom.y+6}};

    Point up_rectangle{n(rectangle).x, n(rectangle).y-4};
    Arrow l5{up_rectangle, Point{bottom.x+4, bottom.y+6}};

    Point up_text{n(text).x, n(text).y-4};
    Arrow l6{up_text, Point{bottom.x+8, bottom.y+6}};

    Point up_image{n(image).x, n(image).y-4};
    Arrow l7{up_image, Point{low_right.x, low_right.y+6}};

    win.attach(shape);
    win.attach(line);
    win.attach(lines);
    win.attach(polygon);
    win.attach(axis);
    win.attach(rectangle);
    win.attach(text);
    win.attach(image);
    win.attach(l1);
    win.attach(l2);
    win.attach(l3);
    win.attach(l4);
    win.attach(l5);
    win.attach(l6);
    win.attach(l7);

    win.wait_for_button();
}