// This program sorts three integer values from the lowest to the highest

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter three integer values.\n";     // Prompt to user enter three integer values
    int num1{0};
    int num2{0};    // initialising all three variables to store the numbers given
    int num3{0};

    cin >> num1 >> num2 >> num3;    // reading the values to the variables

    if(num1 <= num2)
        if(num2 <= num3)
            cout << num1 << ", " << num2 << ", " << num3 << "\n";
        else
            if(num1 <= num3)
                cout << num1 << ", " << num3 << ", " << num2 << "\n";
            else
                cout << num3 << ", " << num1 << ", " << num2 << "\n";

    else        //num1 is bigger than num2
        if(num3 <= num1)    //then num1 is the biggest
            if(num3 <= num2)
                cout << num3 << ", " << num2 << ", " << num1 << "\n";

            else
                cout << num2 << ", " << num3 << ", " << num1 << "\n";
        else    //num3 is bigger than num1, which is bigger than num2
            cout << num2 << ", " << num1 << ", " << num3 << "\n";
}