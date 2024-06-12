// This program fins the lowest, maximum and average temperature
// of a given set

#include "../std_lib_facilities.h"

int main()
{
    double sum = 0;
    double high_temp = -100;    // initialise to a small value
    double low_temp = 100;      // initialise to a big value
    int no_of_temps = 0;
    vector<double> temps;   // set of temperatures
    
    for(double temp; cin >> temp; ){ // read value and put into temperatures vector
        ++no_of_temps;
        temps.push_back(temp);
        if(temp > high_temp) high_temp = temp;  // find high
        if(temp < low_temp) low_temp = temp;    // find low
        sum += temp;                            // compute sum

    }

    cout << "High temperature: " << high_temp << '\n';
    cout << "Low temperature: " << low_temp << '\n';
    if(no_of_temps!=0)
        cout << "Average temperature: " << sum/no_of_temps << '\n'; 
}