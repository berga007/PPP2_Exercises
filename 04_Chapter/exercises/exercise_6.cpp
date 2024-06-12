// exercise 6 from chapter 4

#include "../../std_lib_facilities.h"

int main()
{
    vector <string> numbers = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten"
    };

    int num = 0; // declaring the variable to hold the user given number
    string num_string = "";

    cin >> num >> num_string;

    for(int i = 0; i<10; ++i){
        if (num == i && num_string == numbers[i]){
            cout << numbers[i] << '\n'
                 << i << '\n'; 
        }
        else if(num == i){
            cout << numbers[i] << '\n';
        }
        else if(num_string == numbers[i]){
            cout << i << '\n';
        }
    }
}