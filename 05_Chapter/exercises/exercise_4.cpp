#include "../../std_lib_facilities.h"

double ctok(double c)   // converts Celsius to Kelvin
{
    if(c < -273.15) error("Temperature given is lower than the minimum in the universe: 0 K");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)   // converts Kelvin to Celsius
{
    if(k < 0) error("Temperature given is lower than the minimum in the universe: 0 K");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c = 0;   // declare input variable
    double k = 0;   // declare input variable for temp in Kelvin
    cin >> c >> k;   // retrieve temperature to input variables

    double c_to_k = ctok(c);   // convert temperature
    double k_to_c = ktoc(k);
    cout << c_to_k << '\n'
         << k_to_c << '\n';  // print out temperature

}