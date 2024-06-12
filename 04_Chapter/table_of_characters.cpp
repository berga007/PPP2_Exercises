// This program will print a table of characters with their
// corresponding integer values

#include "../std_lib_facilities.h"

int main()
{
    char first_low_char = 'a';  // initialising the current char to be printed
                                // at each loop iteration
    char first_upper_char = 'A';    // initialising the first uppercase letter

    char first_digit = '0';             // initialising the 1st digit as a character
    
    for (int i = 0; i < 26; ++i) {
        cout << char(first_low_char + i) << "\t" << int(first_low_char + i) << '\n';
    }

    for (int i = 0; i < 26; ++i){
        cout << char(first_upper_char + i) << "\t" << int(first_upper_char + i) << "\n";
    }

    for (int i = 0; i < 10; ++i){
        cout << char(first_digit + i) << "\t" << int(first_digit + i) << "\n";
    }
}