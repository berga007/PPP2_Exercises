// Exercise 3 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../../GUI/Graph.h"          // get access to our graphics library facilities

class abst{ // abstract class
public:
    virtual void f() =0;    // pure virtual function
    void g() { std::cout << "abs::g()"; }
};

int main()
try{
    // Try to construct an object of an abstract class
    // abst obj{};

    // A compile time error is generated
}
catch(exception& e){

}
catch(...){

}
