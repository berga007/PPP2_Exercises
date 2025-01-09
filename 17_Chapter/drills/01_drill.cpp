// "Programming: Principles and Practice Using C++" CH 17
// Drills 

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------

std::ostream& print_array10(std::ostream& os, int* a)
{
    // pre-condition: a is assumed to have 10 elements
    for(int i=0; i<10; ++i){
        os << a[i] << '\n';
    }

    return os;
}

//------------------------------------------------------------------------------
std::ostream& print_array(std::ostream& os, int* a, int n)
{
    // pre-condition: a has n elements
    os << '{';
    for(int i=0; i<n; ++i){
        os << a[i];
        if(i==n-1){
            break;
        }
        os << ',';
    }
    os << '}';

    return os;
}

//------------------------------------------------------------------------------
std::ostream& print_vector(std::ostream& os, const std::vector<int>& v)
{
    os << '{';
    for(int i=0; i<v.size(); ++i){
        os << v[i];
        if(i==v.size()-1){
            break;
        }
        os << ',';
    }
    os << '}';
    return os;
}
//------------------------------------------------------------------------------
int main()
try{
    // Allocate an array of 10 ints
    int* ip = new int[10];

    // print the values of those integers
    print_array10(std::cout, ip);

    // deallocate the array
    delete[] ip;

    // allocate an array of 10 ints
    int* ip2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_array10(std::cout, ip2);
    delete[] ip2;

    // allocate an array of 11 ints
    int* ip3 = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 
        108, 109, 110};
    print_array(std::cout, ip3, 11);
    delete[] ip3;

    // allocate an array of 20 ints
    int* ip4 = new int[20];
    // initialise the elements
    for(int i=0; i<20; ++i)
    {
        ip4[i] = 100+i;
    }

    std::cout << '\n';
    print_array(std::cout, ip4, 20);
    delete[] ip4;

    // make a vector of 10 ints
    std::vector<int> v1{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_vector(std::cout, v1);


    // make a vector of 11 ints
    std::vector<int> v2{100, 101, 102, 103, 104, 105, 106, 107, 
        108, 109, 110};

    std::cout << '\n';    
    print_vector(std::cout, v2);

    // initialise a vector of 20 ints
    std::vector<int> v3(20);
    for(int i=0; i<v3.size(); ++i){
        v3[i] = 100+i;
    }
    
    std::cout << '\n';

    print_vector(std::cout, v3);

    return 0;
}
catch(std::exception& e){
    std::cerr << e.what();
    return 1;
}
catch(...){
    std::cerr << "Unknown exception raised";
    return 2;
}

//------------------------------------------------------------------------------