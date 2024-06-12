// exercise 2 from chapter 8
// Programming: Principles and Practice Using C++

//------------------------------------------------------------------------------

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

void print(string label, vector<int> v)
{
    cout << label << " [";
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "]";
}

int main()
{
    vector <int> my_vector = {1, 3, 4, 6};
    print("int", my_vector);

    return 0;
}