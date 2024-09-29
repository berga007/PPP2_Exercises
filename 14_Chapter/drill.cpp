// Drill from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Simple_window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
class B1{
public:
    virtual void vf() { std::cout << "B1::vf()"; }  // virtual function
    void f() { std::cout << "B1::f()"; }
    virtual void pvf() =0; // pure virtual function
};

//------------------------------------------------------------------------------
class D1: public B1{
public:
    void vf() {std:: cout << "D1::vf()"; }
    void f() {std::cout << "D1::f()"; }
};

//------------------------------------------------------------------------------
class D2: public D1{
public:
    void pvf() {std:cout << "D2::pvf()"; }
};

//------------------------------------------------------------------------------
class B2{
public:
    virtual void pvf() =0;  // pure virtual function
    virtual void f() { std::cout << "B2::f()"; }
};

//------------------------------------------------------------------------------
class D21: public B2{
public:
    void f() {std::cout <<"D21::f()"; }
    string s{"D21::pvf()"};
    void pvf() {std::cout << s; }
};

//------------------------------------------------------------------------------
class D22: public D21{
public:
    void f() {std:: cout << "D22::f()"; }
    int s{0};
};

//------------------------------------------------------------------------------
void f(B2& b)
{
    b.f();
    std::cout << '\n';
    b.pvf();
}

//------------------------------------------------------------------------------
int main()
try{

    /*
    Because there is a "pure" virtual function defined in B, this class
    becomes an abstract class. By definition, it can only be used as base
    for other classes.
    B1 b{};
    b.vf();
    b.f();
    */
    
    std::cout << '\n';
    
    /*
    D1 is derived from class B. D1 objects are a type of class B objects.
    Until all pure virtual functions are overriden in some derived class,
    it will be considered abstract as well.
    Because B1::pvf() is not overriden, class D1 is considered abstract and
    creation of objects of its type is not allowed.
    D1 d{};
    d.vf();
    d.f();
    */

    std::cout << '\n';

    /*
    B1& bb{d};

    bb.vf();
    bb.f();
    */

    D2 d2{};

    d2.f();
    d2.vf();
    d2.pvf();

    std::cout << '\n';

    D21 d21{};
    d21.s = "Test";
    f(d21);

    std::cout << '\n';

    D22 d22{};
    f(d22);

    return 0;
}
catch(exception& e){

}
catch(...){


}

//------------------------------------------------------------------------------