// sums the first N numbers, N defined by user
#include "../../std_lib_facilities.h"

int main()
{
    int N, sum = 0;
    cout << "Please insert how many numbers you want to sum:\n";
    cin >> N;

    cout << "Please enter some integers (press '|' to stop) \n";
    vector <int> nums = {};    // declaring the vector to store the user numbers

    for(int num; cin >> num; )   // continue the iteration until no more integers are entered 
    {
        nums.push_back(num);
    }

    if(N > nums.size()) error("More numbers are needed to accomplish the request");

    for(int i = 0; i < N; ++i)
    {
        sum += nums[i];
    }

    cout << "The sum of the first " << N
         << " numbers is: " << sum << '\n';

}