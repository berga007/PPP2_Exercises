// This program solves the try-this from pp 240 of chapter 5

#include "../std_lib_facilities.h"

int area(int length, int width) // calculate area of a rectangle
{
    if(length <= 0 || width <= 0) return -1;
    return length * width;
}

int framed_area(int x, int y)   // calculate area within frame
{
    constexpr int frame_width = 2;
    return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z)
{
    int area1 = area(x,y);
    if(area1 <= 0) error("non-positive area");
    
    int area2 = framed_area(1, z);
    if(area2 <= 0) error("non-positive area");

    int area3 = framed_area(y, z);
    if (area3 <= 0) error("non-positive area");
    
    double ratio = double(area1)/area3;

    cout << "area1 == " << area1
         << "area2 == " << area2
         << "area3 == " << area3
         << "ratio == " << ratio;

}

int main()
{
    // initialising the three number variables
    int num1, num2, num3 = 0;
    cout << "Please insert a value for x, y and z, respectively\n";
    cin >> num1 >> num2 >> num3;

    f(num1, num2, num3);
}