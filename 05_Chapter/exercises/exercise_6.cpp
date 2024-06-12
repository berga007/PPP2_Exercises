// program to convert from Celsius to Fahrenheit and from Fahrenheit
// to Celsius
#include "../../std_lib_facilities.h"

double ctof(double c)
{
    if(c < -273.15) error("Temperature given is below 0 K");
    double fahrenheit = c * 9/5 + 32;
    return fahrenheit;
}

double ftoc(double f)
{
    if(f < -459.67) error("Temperature given is below 0 K");
    double celsius = (f - 32) * 5/9;
    return celsius;
}

int main()
{
    double celsius, fah = 0.0;  // declare input variables
    cin >> celsius >> fah;      // read into the input variables

    double c_to_f = ctof(celsius);  // convert from Celsius to Fahrenheit
    double f_to_c = ftoc(fah);      // convert from Fahrenheit to Celsius

    cout << c_to_f << " Fahrenheit" << '\n'
         << f_to_c << " Celsius" << '\n';
}