// "Programming: Principles and Practice Using C++"
// Sec. 17.5.2 Destructors and free store

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
struct Costumer {   // costumer base class
    std::string name;
    std::vector<std::string> addresses;

    Costumer(std::string n, std::string ad)  // constructor
        :name{n},
        addresses{ad}
        { std::cout << "<<< Costumer constructor was called\n"; }

    virtual ~Costumer()  // destructor
    { std::cout << "<<< Costumer Destructor was called\n"; }
};

struct SportsCostumer : Costumer{    // derived class
    std::string team;

    // constructor
    SportsCostumer(std::string n, std::string ad, std::string t)
        : Costumer::Costumer(n, ad),
        team{t}
        {
            std::cout<< "<<< SportsCostumer created\n";
        }

    ~SportsCostumer()   // destructor
    {
        std::cout<< "<<< SportsCostumer Destructor was called\n";
    }
};

//------------------------------------------------------------------------------
Costumer* call_1()
// A SportsCostumeris a kind of Costumer, so call() can accept a
// SportsCostumer
{ 
    std::cout << "<<< Executing function call \n";
    SportsCostumer B{"Bernardo", "Por", "Far"};
    Costumer* sc = new SportsCostumer{"Maria", "Por", "Far"};
    return sc;
}

void call_2()
{
    Costumer* c1 = call_1();
    delete c1;
}

//------------------------------------------------------------------------------
int main()
try{

    // Create objects
    // Execute call()

    call_2();

    // Costumer Mary{"Maria", "Por"};
    // SportsCostumer B{"Bernardo", "Por", "Far"};

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