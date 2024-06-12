// Exercise 3 from Chapter 12 of the book
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows library
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()
{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib
    Point tl(100, 100);

    Simple_window win(tl, 600, 400, "Canvas");
    
    Closed_polyline letter_b;
    letter_b.add(Point(100, 100));
    letter_b.add(Point(125, 100));
    letter_b.add(Point(150, 125));
    letter_b.add(Point(150, 150));
    letter_b.add(Point(125, 175));
    letter_b.add(Point(150, 200));
    letter_b.add(Point(150, 225));
    letter_b.add(Point(125, 250));
    letter_b.add(Point(100, 250));
    letter_b.set_style(Line_style(Line_style::solid, 4));

    Open_polyline letter_a;
    letter_a.add(Point(170, 250));
    letter_a.add(Point(190, 100));
    letter_a.add(Point(210, 250));
    letter_a.set_style(Line_style(Line_style::solid, 4));

    Line letter_a_line(Point(184.33, 150), Point(196.66, 150));

    letter_a_line.set_style(Line_style(Line_style::solid, 4));

    // attach letters to window
    win.attach(letter_b);
    win.attach(letter_a);
    win.attach(letter_a_line);

    win.wait_for_button();
}