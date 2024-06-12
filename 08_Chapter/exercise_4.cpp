// exercise 3 from chapter 8
// Programming: Principles and Practice Using C++

// with n == 48 we get a negative number

// so n == 47 will give the biggest fibonacci sequence we can get with ints
// the highest num is approx. 1.8e10

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------
// the previously defined print() function
void print(string label, vector<int> v)
{
    cout << label << " [";
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "]";
}

//------------------------------------------------------------------------------
// A Fibonacci sequence is one where element i+2 is the sum
// of element i with element i+1

vector <int> fibonacci(int x, int y, vector <int> v, int n){
    // pre-condition: n > must be greater than 2
    if(n <= 2) error("n must be greater than 2");

    v.push_back(x);
    v.push_back(y);

    for(int i=0;i<n-2;++i){
        int sum = v[i] + v[i+1];
        v.push_back(sum);
    }

    return v;
}

//------------------------------------------------------------------------------
int main()
{
    int n = 2, x = 0, y = 0;
    cout << "Please insert how many numbers you wish to have on your sequence:";
    cout << "\n> ";
    cin >> n;
    cout << "Insert the 1st element of your sequence:\n";
    cout << '>' << ' ';
    cin >> x ;
    cout << "Insert the 2nd element of your sequence\n";
    cout << '>' << ' ';
    cin >> y;

    vector <int> v{};

    v = fibonacci(x, y, v, n);

    print("int", v);
}