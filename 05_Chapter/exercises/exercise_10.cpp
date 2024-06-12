// sums the first N numbers, N defined by user
#include "../../std_lib_facilities.h"

int main()
{
    int N, sum = 0;
    cout << "Please insert how many numbers you want to sum:\n";
    cin >> N;

    cout << "Please enter some integers (press '|' to stop) \n";
    vector <double> nums = {};    // declaring the vector to store the user numbers
    vector <double> adj_diff = {};  // declaring a vector for storing adjacent differences 

    for(double num; cin >> num; )   // continue the iteration until no more integers are entered 
    {
        nums.push_back(num);
    }

    if(N > nums.size()) error("More numbers are needed to accomplish the request");

    for(int i = 0; i < N; ++i)
    {
        sum += nums[i];
    }

    for(int i = 1; i < N; ++i)
    {
        adj_diff.push_back(nums[i] - nums[i-1]);
    }

    int sum_int = narrow_cast<int>(sum);

    cout << "The sum of the first " << N
         << " numbers is: " << sum_int << '\n';

    cout << "The adjacent differences are: \n";
    for(double n:adj_diff) cout << n << '\n';

}