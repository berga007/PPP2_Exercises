// Generate an error without catching any exception.
// What will happen?

#include "../std_lib_facilities.h"

void my_error(string s)
{
    throw runtime_error(s);
}

double rectangle_area(int x, int y)
{
    if(x <= 0 || y <= 0) 
        my_error("Bad arguments given to rectangle_area()");

    return x*y;
}

int main()
try{
    int a,b = 0;
    double area = 0.0;

    cin >> a >> b;

    area = rectangle_area(a, b);

    cout << "Area of the rectangle with length "
         << a << " and width " << b << ": \n"
         << area << '\n';

    return 0;   // 0 indicates success
}
catch(runtime_error& e){
    cerr << "error: " << e.what() << '\n';
    return 1;   // 1 indicates failure
}