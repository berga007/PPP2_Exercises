// This program does not do anything
// It simply has a bunch of legal and illegal names to test the compiler reaction

#include "../../std_lib_facilities.h"

int main()
{
    string name;            // legal name
    double _number;         // illegal name. Starts with an '_'
    int to1_ne#;            // illegal name. Starts with a number
    int number_2_!number;   // illgeal name. Contains special character. Only numbers, characters and underscores are valid. 
    char new_char$;   
}