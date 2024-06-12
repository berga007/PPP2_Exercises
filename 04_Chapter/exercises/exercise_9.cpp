// exercise 9 from chapter 4
#include "../../std_lib_facilities.h"

int main()
{
    vector <int> grains;    // vector that holds the number of grains
                            // that correspond to each chess square
    vector <double> grains_double;
    int i = 0;              // loop variable
    int sum = 0;            // sum of the accumulated grains so far
    double sum_2 = 0.0;     // sum of the accumulated grains so far, stored in a double
    while(i < 63){
        grains.push_back(pow(2, i));
        grains_double.push_back(pow(2, i));
        sum += grains[i];
        sum_2 += grains_double[i];

        cout << "At square " << i + 1 << ": \n"
             << "Number of grains: " << grains[i] << '\n'
             << "So far, the total number of grains is: " << sum << '\n'
             << "or approximately " << sum_2 << '\n'
             << '\n';
        ++i;
    }
}