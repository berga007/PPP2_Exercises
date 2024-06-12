// This program solves the 2nd drill

#include "../../std_lib_facilities.h"

// Function definitions

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

int main()
{
    int x = 7;
    int y = 9;

    swap_r(x, y);

    // swap_r(7,9);

    cout << "x == " << x << " y == " << y << '\n';

    const int cx = 7;
    const int cy = 9;

    // swap_r(cx, cy);
    // swap_r(7.7, 9.9);
    
    cout << "cx == " << cx << " cy == " << cy << '\n';

    double dx = 7.7;
    double dy = 9.9;

    // swap_r(dx, dy);
    // swap_r(7.7, 9.9);

    // cout << "dx == " << dx << " dy == " << dy << '\n';

}