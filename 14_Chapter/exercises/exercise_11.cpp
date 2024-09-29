// Exercise 11 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

int main()
try{
    Point tl{200, 200};
    Simple_window win{tl, 500, 500, "Exercise 11"};

    Binary_tree btree{Point{250, 50}, 4, "da"};
    btree.set_fill_color(Color::black);

    btree.set_node_label("lll", "Test");

    win.attach(btree);

    win.wait_for_button();
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}