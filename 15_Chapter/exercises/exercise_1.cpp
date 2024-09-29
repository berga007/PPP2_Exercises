// Exercise 1 from Chapter 15 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
// factorial implementation using recursion
double fac_recursive(int n){ return n>1? n*fac_recursive(n-1): 1;} // factorial n!

//------------------------------------------------------------------------------
// factorial implementaion using iteration ref.(sec.15.5)
double fac_iterative(int n){
    double p{1};
    while(n>1){
        p *= n;
        --n;
    }
    return p;
}

// Comment: original implementation stores the value in an int;
// The problem is it will overflow at n == 13

//------------------------------------------------------------------------------
int main()
try{
    std::cout << "|n |Iterative Factorial|Recursive Factorial|\n"
              << "|--|-------------------|-------------------|\n";
    // compute factorials up to (and including) 20
    for(int i=0; i<21; ++i){    
        std::cout << '|' << setw(2) << i << '|' 
            << setw(19) << fac_iterative(i) << '|'
            << setw(19) << fac_recursive(i) << "|\n";
    }
    return 0;
}
catch(exception& e){
    std::cerr << e.what();
    return 1;
}

catch(...){
    cerr << "Unknown excpetion has been thrown";
    return 2;
}

//------------------------------------------------------------------------------