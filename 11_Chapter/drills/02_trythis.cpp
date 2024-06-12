// Try This exercise from section 11.2.2- Integer Input of the book:
// Programming: Principles and Practice Using C++

// Author: Bernardo Alves

#include "../../std_lib_facilities.h"

int main()
{
    int a;
    int b;
    int c;
    int d;
    string prompt{">>>"};

    cout << "<<<Please insert 4 integer values:\n"
         << prompt;

    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}