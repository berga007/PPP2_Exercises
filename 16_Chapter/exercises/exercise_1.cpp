// "Programming: Principles and Practice Using C++" CH 16
// Exercise 1 

// Author: Bernardo Alves

// Note: My_window class was declared in GUI/Simple_window.h
// Member definitions were placed in GUI/Simple_window.cpp

//------------------------------------------------------------------------------

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary

//------------------------------------------------------------------------------
int main()
try{
    My_window win{Point{100, 100}, 600, 400, "Exercise 1"};
    win.wait_for_button();
}
catch(std::exception& e){
    std::cerr << e.what() << '\n';
    return 1;
}
catch(...){
    std::cerr << "Unknown exception raised";
    return 2;
}