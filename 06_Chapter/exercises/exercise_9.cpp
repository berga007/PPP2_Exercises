// Exercise 9 from chapter 6
// "Programming - Principles and Practice using C++" by Bjarne Stroustrup

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    // Prompt the user to enter, at most, 4 digits
    cout << "Please insert no more than 4 digits\n"
         << "Type Ctr+D to terminate the input\n";

    char c1 = '0', c2 = '0', c3 = '0', c4 = '0';

    cin >> c1 >> c2 >> c3 >> c4;

    vector <char> v = {c1, c2, c3, c4};
    vector <int> nums = {};

    int number = 0, order_of_mag = 4;

    // for each digit given by user, convert it ito int and save to
    // the vector of ints
    for(char c:v){
        nums.push_back(c - '0');
    }

    int j = 0;  // var to iterate nums from left to right

    // Convert the vector of ints to an int
    // multiply the first int by the order of magnitude and add to number
    // the second int by 1 less the order of magnitude and add to number
    // (...)
    for(int i=order_of_mag; i>0; --i){
        int n = nums[j] * pow(10, (i-1));
        number += n;
        ++j;      
    }

    string s1, s2, s3, s4;

    // Output the messages
    cout << number << " is: \n";

    for(int i=0; i<order_of_mag; ++i){
        if(i == 0){
            if(nums[i] != 1){
                s4 = "thousands";
            } else {
                s4 = "thousand";
            }
        } else if(i == 1){
            if(nums[i] != 1){
                s3 = "hundreds";
            } else {
                s3 = "hundred";
            }
        } else if(i == 2){
            if(nums[i] != 1) {
                s2 = "tens";
            } else {
                s3 = "ten";
            }
        } else if(i == 3){
            if(nums[i] != 1){
                s1 = "ones";
            } else{
                s1 = "one";
            }
        }
    }

    cout << nums[0] << ' ' << s4 << '\n'
         << nums[1] << ' ' << s3 << '\n'
         << nums[2] << ' ' << s2 << '\n'
         << nums[3] << ' ' << s1 << '\n';
}
