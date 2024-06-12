// calculates the largest Fibonnaci number that can fit into int
#include "../../std_lib_facilities.h"

int main()
{
    vector <int> fib_nums = {1, 1}; // declaring a vector to store Fibonacci numbers

    cout << fib_nums[0] << '\n'
         << fib_nums[1] << '\n';

    for(int i=0; i>-1; ++i) // for loop will never end, condition is always true
    {
        int new_number = fib_nums[i+1] + fib_nums[i];
        // post-condition: 
        // new_number should always be greater than previous number
        if(new_number < fib_nums[i+1]) error("Result is too large. Cannot fit in an int");
        fib_nums.push_back(new_number);
        cout << new_number << '\n';
    }
}