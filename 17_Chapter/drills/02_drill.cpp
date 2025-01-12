// "Programming: Principles and Practice Using C++" CH 17
// Drills 

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

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

    int var{7};
    int* p1 = &var;

    std::cout << "p1==" << p1 << ", *p1==" << *p1;

    // allocate an array of 7 ints
    int* p2 = new int[7];
    for(int i=0; i<7; ++i){
        p2[i] = pow(2,i);
    }

    std::cout<< '\n';

    std::cout << "p2== " << p2 << '\n'
              << "*p2== " << *p2 << '\n';
    print_array(std::cout, p2, 7);

    int* p3 = p2;

    p2 = p1;

    p2 = p3;

    std::cout << '\n';

    std::cout << "p1==" << p1 << '\n'
              << "*p1==" << *p1 << '\n';

    std::cout << "p2==" << p2 << '\n'
              << "*p2==" << *p2 << '\n';

    print_array(std::cout, p2, 7) << '\n';

    // only p2 was allocated from the free store
    delete[] p2;
    p3=0;

    p1 = new int[10];
    for(int i=0; i<10; ++i){
        p1[i] = pow(2,i);
    }

    p2 = new int[10];

    for(int i=0; i<10; ++i){
        p2[i] = p1[i];
    }

    std::cout << '\n';

    print_array(std::cout, p2, 10);

    std::vector<int> v1(10);
    for(int i=0; i<v1.size(); ++i){
        v1[i] = pow(2,i);
    }

    std::vector<int> v2(10);
    v2=v1;

    std::cout << '\n';
    print_vector(std::cout, v2);

    return 0;
}
catch(std::exception& e){
    std::cerr<< e.what();
    return 1;
}
catch(...){
    std::cerr<< "Unknown exception raised somewhere by some code...";
    return 2; 
}

//------------------------------------------------------------------------------