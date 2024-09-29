// Technical example to explain virtual function overriding mechanisms 
// ref. Sec 14.3.3 from Chapter 14 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>

struct B{
    virtual void f() const { std::cout << "B::f"; }
    void g() const { std::cout << "B::g"; } // not virtual
};

struct D: B {
    void f() const { std::cout << "D::f"; } // overrides B::f
    void g() { std::cout << "D::g"; }

};

struct DD: D{
    void f() {std::cout << "DD::f"; }  // does not override D::f (not const)
    void g() {std::cout << "DD:g"; } 
};

void call(const B& b)
    // a D is a kind of B, so call() can accept a D
    // a DD is a kind of D and D is a kind of B. Hence call() can accept
    // a DD
{
    b.f();
    b.g();
}

int main()
try{
    B b;
    D d;
    DD dd;
    call(b);    // B::f B::g
    call(d);    // D::f B::g
    call(dd);   // D::f B::g

    std::cout << "\n---------------\n";

    b.f();  // B::f
    b.g();  // B::g

    d.f();  // D::f
    d.g();  // D::g

    dd.f(); // D::f
    dd.g(); // D::g


}
catch(std::exception& e){
    std::cerr << e.what();
}
catch(...){
    std::cerr << "Unknown exception was throwed somewhere.";
}