// Exercise 11 from Chapter 13 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

int main()

try{
    const Point tl{100,100};
    Simple_window win{tl, 1000, 1000, "Exercise 11"};

    Ellipse e1{Point{500,500}, 300, 200};

    Axis xaxis{Axis::x, Point{300, e1.center().y}, 400, 10, "X axis"};
    Axis yaxis{Axis::y, Point{e1.center().x, 650}, 300, 10, "Y axis"};

    Point f1{e1.focus1()};
    Point f2{e1.focus2()};

    Marks foci{"x", {f1, f2}};

    // get a point on the ellipse which is not on the axes
    Point p1{ne(e1)};
    Mark p{p1, 'O'};

    // draw the lines connecting P to the foci
    Line l1{p1, f1};
    Line l2{p1, f2};

    win.attach(e1);
    win.attach(xaxis);
    win.attach(yaxis);
    win.attach(foci);
    win.attach(p);
    win.attach(l1);
    win.attach(l2);

    win.wait_for_button();

}
catch(exception& e){

}

catch(...){

}