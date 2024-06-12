// exercise 10 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

int maxv(const vector<int>& v){
    int max{v[0]};
    for(int i=1; i<v.size(); ++i)
    {
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

int main()
{
    // declaring the vector
    vector <int> v{};
    // declaring the val variable to store input from cin
    int val{};
    cout << "Introduce the numeric values:\n";
    while(cin){
        cin >> val;
        v.push_back(val);
    }

    cout << "Max value is: " << maxv(v) << '\n';
}
