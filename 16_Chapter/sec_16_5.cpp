// Code for section 16.5 An Example, of "Programming: Principles and Practice Using C++"

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include "../GUI/GUI.h"  // get access to our windows lbrary

//------------------------------------------------------------------------------
int main()
try{
    Graph_lib::Lines_window win (Graph_lib::Point{100, 100}, 600, 400, "lines");
    return Graph_lib::gui_main();
}
catch(exception& e){
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...){
    std::cerr << "Some unknown error \n";
    return 2;
}