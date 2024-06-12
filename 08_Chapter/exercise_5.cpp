// exercise 5 from chapter 8
// Programming: Principles and Practice Using C++

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

//------------------------------------------------------------------------------
// goal is to reverse the order of elements in a vector

// without changing the original vector
vector <int> reverse(const vector <int>& v)
{
    vector <int> reversed_vector{};
    for(int i=v.size()-1;i>=0;--i){
        reversed_vector.push_back(v[i]);
    }

    return reversed_vector;
}


//------------------------------------------------------------------------------
// changing the original vector but without using any other vector

vector <int> reverse_2(vector <int>& v)
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
    vector <int> my_vector{};
    int aux{0};
    cout << "Please introduce the elements of the vector\n";
    while(cin){
        cin >> aux;
        my_vector.push_back(aux);
    }

    print("original vector", my_vector);

    cout << '\n';

    vector <int> reversed{}; 
    reversed = reverse_2(my_vector);

    print("reversed vector:", reversed);
}