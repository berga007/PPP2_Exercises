// "Programming: Principles and Practice Using C++" CH 17
// Exercise 7

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
std::string prompt{">>>"};
//------------------------------------------------------------------------------
void copy(char* c1, char* c2){
    // copy the contents of c1 to c2
    for(int i=0; i<strlen(c1); ++i){
        c2[i] = c1[i];  // copy the elements
    }
}

//------------------------------------------------------------------------------
void print(char* c){
    int i=0;
    while(c[i]){
        std::cout<<c[i];
        ++i;
    }
}

//------------------------------------------------------------------------------
int main()
try{
    // array on the free store, initialisation
    char* c = new char[1];
    int i{0};   // iterator variable

    // prompt the user
    std::cout<< "<<< Please insert 1 character at a time\n"
             << "<<< To terminate the program enter '!'\n"
             << prompt;

    // read 1st character
    c[0] = std::cin.get();

    while(true){
        // check if exclamation mark was entered
        if(c[i] == '!') break;

        ++i;
        // allocate more space from the heap
        char* temp = new char[i];

        // copy the old values into temp
        copy(c, temp);
        
        // read one more character
        std::cout<< '\n' << prompt;
        temp[i] = std::cin.get();

        // free the previous memory allocated by c
        delete[] c;
        // make c point to temp
        c = temp;
    }

    std::cout<<'\n';

    print(c);

    return 0;
}
catch(std::exception& e){
    std::cerr<< e.what();
    return 1;
}
catch(...){
    std::cerr<< "Unknown exception raised somewhere...";
    return 2;
}

//------------------------------------------------------------------------------