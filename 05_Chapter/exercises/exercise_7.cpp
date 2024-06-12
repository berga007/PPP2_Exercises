// This program solves a 2nd degree polynomial equation
// of the form ax^2 + bx + c = 0
#include "../../std_lib_facilities.h"

int main()
{
    double a, b, c = 0.0;   // declare the input variables
    cin >> a >> b >> c;     // read the values entered by the user

    double condition = b*b - 4*a*c; // pre-condition to check if the computation is possible

    if(condition < 0) error("In the real domain the square root of negative numbers does not exist");

    double x1 = (- b - sqrt(b*b - 4*a*c)) / 2 / a;

    double x2 = (- b + sqrt(b*b - 4*a*c)) / 2 / a;

    cout << "The roots of the equation "
         << a << "x^2 + " << b << "x + " << c
         << " = 0 are: \n"
         << "x1 = " << x1 << '\n'
         << "x2 = " << x2 << '\n';
}