// exercise 5 from chapter 4

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter two floating point values and an arithmetic operator such as"
         << " \'+\', \'-\', \'*\' or \'/\' \n";

    double num_a, num_b = 0.0;  // initialising the variables to store the numbers
    char operation = ' ';

    cin >> num_a >> operation >> num_b;

    switch(operation){
    case '+':
        cout << "The sum of " << num_a << " with " << num_b << " is " 
             << num_a + num_b;
        break;
    case '-':
        cout << "The subtration of " << num_b << " from " << num_a << " is " 
             << num_a - num_b;
        break;
    case '*':
        cout << "The multiplication of " << num_a << " with " << num_b
             << " is " << num_a * num_b;
        break;
    case '/':
        cout << "The division of " << num_a << " with " << num_b
             << " is " << num_a/num_b;
        break;
    }
}