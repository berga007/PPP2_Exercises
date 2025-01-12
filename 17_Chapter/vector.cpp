// "Programming: Principles and Practice Using C++"
// CH 17, Simplified Vector class  

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// very simplified vector of doubles
class vector{
    int sz;         // the size
    double* elem;   // a pointer to the elements
public:
    vector(int s)   // constructor
        :sz{s}, // initialise sz
        elem{new double[s]} // initialise elem
        {
            for(int i=0; i<s; ++i) elem[i] = 0; // initialise elements
        }
        int size() const {return sz; }  // the current size
        ~vector()   // destructor
        { delete[] elem; }  // free memory      
};

//------------------------------------------------------------------------------
int main()
try{
    return 0;
}
catch(std::exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    std::cerr<< "Unknown exception raised...";
    return 2;
}

//------------------------------------------------------------------------------