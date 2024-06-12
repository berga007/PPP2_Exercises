// exercise 6 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------
void print(string label, vector<string> v)
{
    cout << label << " [";
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "]";
}

//------------------------------------------------------------------------------
// goal is to reverse the order of elements in a vector

// without changing the original vector
vector <string> reverse(const vector <string>& v)
{
    vector <string> reversed_vector{};
    for(int i=v.size()-1;i>=0;--i){
        reversed_vector.push_back(v[i]);
    }

    return reversed_vector;
}


//------------------------------------------------------------------------------
// changing the original vector but without using any other vector

vector <string> reverse_2(vector <string>& v)
{
    int length = v.size();
    int middle{0};
    int end{0};
    if(length%2 == 0){
        end = length/2 -1;
    }
    else{
        // middle of the vector
        middle = (length + 1)/2 - 1;
        end = middle - 1;
    }

    for(int i=0; i<=end; ++i){
        swap(v[i], v[length-1-i]);
    }
    return v;
}

//------------------------------------------------------------------------------
int main()
{
    vector <string> my_vector{};
    string aux{};
    cout << "Please introduce the elements of the vector\n";
    while(cin){
        cin >> aux;
        my_vector.push_back(aux);
    }

    print("original vector", my_vector);

    cout << '\n';

    vector <string> reversed{}; 
    reversed = reverse_2(my_vector);

    print("reversed vector:", reversed);
}