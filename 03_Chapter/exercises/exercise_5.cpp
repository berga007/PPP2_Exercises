// This program compares to floating point values and
// performs basic operations with the two

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter two floating point values \n";      // prompt the user to enter to integers
    double val1{0};        // initialising val1 variable
    double val2{0};        // initialising val2 variable
    cin >> val1 >> val2;    // read the values inserted by the user
    double larger{0};          // initialising the larger variable
    if(val1 < val2)
        larger = val2;

    if(val1 > val2)
        larger = val1;

    if(val1 == val2)
        cout << "Both values inserted are equal";  

    double sum = val1 + val2;
    double diff = val1 - val2;
    double product = val1 * val2;
    double ratio = val1/val2;

    cout << "The larger is " << larger << ". \n"
            << "The product between " << val1 << " and " << val2 << " is " << product 
            << ". \n"
            << "The sum between the two is " << sum << ".\n"
            << "The ratio of " << val1 << " over " << val2 << " is " << ratio << ".\n"
            << "The difference between " << val1 << " and " << val2 << " is " << diff << ".\n";    
}