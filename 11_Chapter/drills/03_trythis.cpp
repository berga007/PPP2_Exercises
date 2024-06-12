// Try This exercise from section 11.2.4- Precision of the book:
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

#include "../../std_lib_facilities.h"

int main()
{
    float number{1234567.89};
    
    cout << number << '\t'
         << fixed << number << '\t'
         << scientific << number << '\n'; 
}