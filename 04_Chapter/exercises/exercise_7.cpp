// exercise 7 from chapter 4

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter two floating point values and an arithmetic operator such as"
         << " \'+\', \'-\', \'*\' or \'/\' \n";

    string num_a, num_b = "";   // these variables will read user input
    int a,b = 0;  // initialising the variables to store the numbers
    char operation = ' ';

    vector <string> numbers_spelled = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten"
    };

    vector <string> numbers_digits = {
        "0", "1", "2", "3", "4", "5", "6",
        "7", "8", "9"
    };

    cin >> num_a >> operation >> num_b;

    // Converting the first input to an integer
    for(int i = 0; i<10; ++i){
       
        if (num_a == numbers_spelled[i]){
            a = i;
            break;
        }
        else if(num_a == numbers_digits[i]){
            a = i;
            break;
        }
    }

    // Converting the second input to an integer
    for(int i = 0; i<10; ++i){
        
        if (num_b == numbers_spelled[i]){
            b = i;
        }
        else if(num_b == numbers_digits[i]){
            b = i;
        }
    }

    switch(operation){
    case '+':
        cout << "The sum of " << num_a << " with " << num_b << " is " 
             << a + b << '\n';
        break;
    case '-':
        cout << "The subtration of " << num_b << " from " << num_a << " is " 
             << a - b << '\n';
        break;
    case '*':
        cout << "The multiplication of " << num_a << " with " << num_b
             << " is " << a * b << '\n';
        break;
    case '/':
        cout << "The division of " << num_a << " with " << num_b
             << " is " << a/b << '\n';
        break;
    }
}