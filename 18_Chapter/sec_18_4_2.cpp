// "Programming: Principles and Practice Using C++"
// Sec. 18.4.2 Debugging Constructors and Destructors

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
struct X{   // simple test class
    int val;
    void out(const std::string& s, int nv)
        {std::cerr << this << "->" << s << ": " << val << "(" << nv << ")\n"; }
        X() { out("X()", 0); val=0; }   // default constructor
        X(int v){val=v; out("X(int)", v); }
        X(const X& x){val=x.val; out("X(X&)", x.val); }   // copy constructor
        X& operator=(const X& a)    // copy assignment
            {out("X::operator=()", a.val); val=a.val; return *this; }
        ~X() {out("~X()", 0); } // destructor
};

X glob(2);  // global variable
X copy(X a){ return a; }

X copy2(X a){X aa=a; return aa; }

X& ref_to(X& a) {return a; }

X* make(int i){X a(i); return new X(a); }

struct XX { X a; X b; };

//------------------------------------------------------------------------------
int main()
try{
    std::cout<< "<<<1-\n";
    X loc(4);   // local variable
    
    std::cout<< "<<<2-\n";
    X loc2{loc};    // copy construction
    
    std::cout<< "<<<3-\n";
    loc = X{5};     // copy assignment
    
    std::cout<< "<<<4-\n";
    loc2 = copy(loc);   // call by value and return
    
    std::cout<< "<<<5-\n";
    loc2 = copy2(loc);
    
    std::cout<< "<<<6-\n";
    X loc3{6};
    
    std::cout<< "<<<7-\n";
    X& r = ref_to(loc); // call by reference and return
    
    std::cout<< "<<<8-\n";
    delete make(7);
    
    std::cout<< "<<<9-\n";
    delete make(8);
   
    std::cout<< "<<<10-\n";
    std::vector<X> v(4);    // a vector of 4 default X's
    
    std::cout<< "<<<11-\n";
    XX loc4;
    
    std::cout<< "<<<12-\n";
    X* p = new X{9};  // an X on the free store
    
    std::cout<< "<<<13-\n";
    delete p;
    
    std::cout<< "<<<14-\n";
    X* pp = new X[5];   // an array of X's on the free store
    
    std::cout<< "<<<15-\n";
    delete[] pp;

}
catch(std::exception& e)
{
    std::cerr << e.what();
    return 1;
}
catch(...)
{
    std::cerr << "Something unexpected happened somewhere in time\n";
    return 2;
}

//------------------------------------------------------------------------------