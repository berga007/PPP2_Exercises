// example of unsafe conversions between different data types

#include "../std_lib_facilities.h"

int main()
{
    double d = 0;
    while(cin>>d){  // repeat the statements below
                    // as long as we type information
        int i = d;  // try to squeeze a double into an int
        char c = i; // try to squeeze an int into a char
        int i2 = c; // get the integer value of the character
        cout << "d ==" << d                 // the original value
                << "i==" << i               // converted into int
                << "i2==" << i2             // int value of char
                << "char("<< c <<")\n";   // the char
    }
}
