// exercise 18 from chapter 4
// this program finds the two solutions x1 and x2 of a quadratic equation

#include "../../std_lib_facilities.h"

int main()
{
    // Quadratic equation is of the form:
    // ax**2 + bx + c = 0

    // Initialising the variables a, b and c in the above equation
    double a, b, c = 0.0;

    // Initialising the two solutions
    double x1, x2 = 0.0;

    // prompting the user
    cout << "This program solves the quadratic equation ax^2 + bx + c = 0\n"
         << "Enter the value of the constans a, b, and c:\n";
    
    cin >> a >> b >> c;

    x1 = (-b + sqrt(b*b - 4 * a * c)) / 2 / a;
    x2 = (- b - sqrt(b*b - 4 * a * c)) / 2 / a;

    cout << "The solution to the equation "
         << a << "*x^2 + " << b << "*x + " << c << " == 0\n"
         << "x1 == " << x1 << '\n'
         << "x2 == " << x2 << '\n'; 
}
