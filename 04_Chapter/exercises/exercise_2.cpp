// This program stores a sequence of temperatures
// and calculates the mean and the median

#include "../../std_lib_facilities.h"

int main()
{
    vector <double> temps;  // temperatures vector
    cout << "Please provide a set of temperatures in Celsius.\n";
    for(double temp; cin >> temp; ) // read into temp
        temps.push_back(temp);  // put temperature in the temperatures vector
    
    // compute mean temperature
    double sum = 0; 
    for(double x: temps)
        sum += x;
    
    cout << "Avergae temperature: " << sum/temps.size() << " Celsius \n";
    
    // Calculate the median
    sort(temps);    // sort the vector
    if(temps.size() % 2 == 0){
        // find the middle values
        double mid_0 = temps[temps.size()/2];
        double mid_1 = temps[temps.size()/2 - 1];

        cout << "Median temperature: " << (mid_0 + mid_1)/2 << " Celsius \n";
    }
    else
        cout << "Median temperature: " << temps[temps.size()/2];
}