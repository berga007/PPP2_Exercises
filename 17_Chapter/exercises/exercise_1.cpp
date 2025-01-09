// "Programming: Principles and Practice Using C++" CH 17
// Exercise 1, 2

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
int main()
try{
    // exercise 1
    int a{0};
    int* p_a{&a};
    std::cout<<"Pointer to integer: " << p_a << '\n';

    // After printing the value to the screen, it is clear that its format is
    // hexadecimal
    //

    // exercise 2

    int* sev_ints = new int[2]; // allocate 2 integers from the free-store
    std::cout << "Address of the 1st: " << &sev_ints[0] << '\n'
              << "Address of the 2nd: " << &sev_ints[1] << '\n';
    // from the output we can see that the two addresses differ by 4 bytes
    // integers are stored in 4 bytes

    // size of doubles...? well 2*sizeof(int) == 2*4 = 8 bytes

    bool* sev_bools = new bool[2]; // allocate 2 integers from the free-store
    std::cout << "Address of the 1st: " << &sev_bools[0] << '\n'
              << "Address of the 2nd: " << &sev_bools[1] << '\n';

    // again, from the output we observe that the two allocated bools
    // differ by 1  byte. Since arrays are contiguous, i.e. with no empty space
    // we can conclude that bools are stored in 1 byte

    std::cout<< "Size of int: " << sizeof(int) << '\n';
    std::cout<< "Size of double: " << sizeof(double) << '\n';
    std::cout<< "Size of bool: " << sizeof(bool) << '\n';
}
catch(std::exception& e){
    std::cerr<<e.what();
    return 1;

}
catch(...){
    std::cerr<< "Unknown exception raised...";
    return 2;
}

//------------------------------------------------------------------------------