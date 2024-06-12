// This program will convert a value in miles to kilometers

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter the distance in miles\n";
    double distance_in_miles{0};    // initialising the variable with 0
    cin >> distance_in_miles;
    double distance_in_km = distance_in_miles * 1.609;  // 1 mile is 1.609 km
    cout << "The corresponding distance in kilometers is " << distance_in_km << ".\n";
}