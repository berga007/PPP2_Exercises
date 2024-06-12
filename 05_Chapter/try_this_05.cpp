// this program calculates the area of a rectangle
// an I will try to break the post-condition only

#include "../std_lib_facilities.h"

int area(int length, int width)
// calculate area of a rectangle
// pre-conditions: length and width are positive
// post-conditions: returns a positive value that is the area
{
    if(length <= 0 || width <= 0) error("area() pre-condition");
    int a = length * width;
    if(a <= 0) error("area() post-condition");
    return a;
}

int main()
{
    int length, width = 0;
    int a = 0;

    cin >> length >> width;

    a = area(length, width);
    cout << a;

}