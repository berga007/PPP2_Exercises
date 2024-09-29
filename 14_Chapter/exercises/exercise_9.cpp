// Exercise 9 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities
int main()
try{
    Point tl{200, 200};
    Simple_window win{tl, 500, 500, "Exercise 9"};
    int length{50};
    int n_rows{8};
    Vector_ref<Rectangle> recs{};
    Group checkers_board{};
    for(int i=0; i<n_rows; ++i){
        for(int j=0; j<n_rows; ++j){
            // add new rectangle
            recs.push_back(new Rectangle{Point{j*length, (n_rows-1-i)*length}, length, length});
            // fill with appropriate color
            if(i%2==j%2){
                recs[recs.size()-1].set_fill_color(Color::black);
            } else{
                recs[recs.size()-1].set_fill_color(Color::white);
                checkers_board.add(recs[recs.size()-1]);
            }
            win.attach(recs[recs.size()-1]);
        }
    }

    win.wait_for_button();

    checkers_board.set_style(Line_style::dashdot);

    win.wait_for_button();
}
catch(exception& e){
    std::cerr << e.what();
}
catch(...){

}