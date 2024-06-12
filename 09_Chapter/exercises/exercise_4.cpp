// Exercise 4 from Chapter 9 of the book
// Programming Principles and Practice Using C++

// Indent the example of section 8.4., explain meaning of each construct
// ----------------------------------------------------------------------- 

// dangerously ugly code
struct X{
    // function f defined inside the scope of X
    void f(int x){
        // struct Y available inside the scope of f
        struct Y {
            // new function f, in the scope of Y
            int f() { return 1; }
            int m;
        };

        int m;

        // x was passed as an argument to f, in the scope of X
        m = x;
        // Initialise variable m2 of type Y
        Y m2;

        // return...? function was defined as void
        // recursive function, calling itself f(1)
        // Infinite recursion
        return f(m2.f());
    }

    // new m
    int m;

    // new memebr function called g, with an argument
    void g(int m){
        if(m)
            // call f defined above in the scope of X
            f(m+2);
        else{
            // recursive case
            // calls itself, if previous if condition is not met
            g(m+2);
        }
    }
    // constructor of the struct X
    X() { }

    // another member function of X
    void m3(){}

    // member function of X, called main
    void main()
    {
        // initialise a new variable of type X
        X a;
        
        // call its member function f
        a.f(2);
    }
};