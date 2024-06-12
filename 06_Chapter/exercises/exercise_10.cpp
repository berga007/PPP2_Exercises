// Exercise 10 from chapter 6
// "Programming - Principles and Practice using C++" by Bjarne Stroustrup

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------
int factorial(int num)
{
    if(num == 0){
        return 1;
    } else {
        return num *= factorial(num - 1);
    }
}

int permutations(int a, int b)
{
    // pre-condition: 0 < b <= a
    if(b<0) error("Both numbers should be greater than or equal to 0");
    if(a<b) error(
        "The first number has to be greater than or equal to the first"
    );
    return factorial(a)/factorial(a-b);
}

int combinations(int a, int b)
{
    // pre-condition: 0 < b <= a
    if(b<0) error("Both numbers should be greater than or equal to 0");
    if(a<b) error(
        "The first number has to be greater than or equal to the first"
    );
    return permutations(a, b)/factorial(b);
}

//------------------------------------------------------------------------------
int main()
try {
    int num_a, num_b, result;   // declare both numbers and the result

    char option;    // declare option variable. It will be used to decide
                    // wether a permutation or a combination is 
                    // to be calculated.

    string error_message = "Please insert only 'P' for permutations, 'C'";

    error_message.append(" for combinations, or 'q' to exit"); 

    // Prompt the user to introduce two numbers
    cout << "Please insert two integer numbers\n"
         << "> ";

    cin >> num_a >> num_b;

    // Testing if input operation suceeded or not
    if(!cin) error("Please insert two integer numbers");

    // Prompting the user again
    cout << "Please choose wheter you want to calculate a permutation\n"
         << "or a combination \n"
         << "Insert 'P' for permutation, 'C' for combination or 'q' to exit\n"
         << "> ";

    cin >> option;

    switch(option){
        case 'P':
        {
            result = permutations(num_a, num_b);
            cout << "P(" << num_a << ", " << num_b << ") = " << result << '\n';
            break;
        }
        case 'C':
        {
            result = combinations(num_a, num_b);
            cout << "C(" << num_a << ", " << num_b << ") = " << result << '\n';
            break;
        }
        case 'q':
        {
            return 0;
        }
        default:
            error(error_message);
    }

    return 0;

} catch(exception & e) {
    cerr << "runtime error: " << e.what() << '\n';
    keep_window_open();
    return 1;   // 1 indicates failure
} catch(...) {
    cerr << "Exception: Something went wrong somewhere \n";
    return 2;
}