// This is a version of "The first program"
// it prints the integer numbers in [0, 100) and their square

#include "../std_lib_facilities.h"

int square(int x)
{
    // Pre-condition: x must be an integer
    // Post-condition: result should be an integer
    int result = 0;
    for(int i = 0; i < x; ++i){
        result += x;
    }
    return result;
}

int main()
{
    for(int i = 0; i<100; ++i ){
        cout << i << '\t' << square(i) << '\n';
    }
}