// exercise 8 from chapter 4
#include "../../std_lib_facilities.h"

int main()
{
    vector <int> grains;    // vector that holds the number of grains
                            // that correspond to each chess square
    int i = 0;              // loop variable
    int sum = 0;            // sum of the accumulated grains so far
    while(sum < 1 * pow(10,9)){
        grains.push_back(pow(2, i));
        sum += grains[i];

        cout << "At square " << i + 1 << ": \n"
             << "Number of grains: " << grains[i] << '\n'
             << "So far, the total number of grains is: " << sum << '\n'
             << '\n';
        ++i;
    }
}