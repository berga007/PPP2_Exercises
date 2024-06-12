// This program checks if an integer number number is even or odd

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter an integer value.\n";     // Prompting the user
    int number{0};      // initialising the variable to store the number given
    cin >> number;

    if(number%2 == 0)
        cout << "The number " << number << " is even.\n";
    else
        cout << "The number " << number << " is odd.\n";
}