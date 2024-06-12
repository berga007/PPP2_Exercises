// exercise 8 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

// Same exercise as exercise 7 from the same chapter, but
// allowing an arbitrary number of names

int find_index(const vector <string>& n, string name)
{
    for(int i=0;i<n.size();++i){
        if(name==n[i]){
            return i;
        }
        if(i==n.size()-1) error("name not found in vector");
    }
}

int main()
{
    // termination character
    const char quit{'q'};

    // character to search for quit character
    char ch{};

    string name{};
    int age{};

    vector<string> name_vector{};
    vector<int> age_vector{};

    cout << "Please type in a name and the corresponding age\n";
    while(true){
        cin.get(ch);
        if(ch == quit){
            break;
        }
        else{
            cin.putback(ch);
        }
        cin >> name;
        name_vector.push_back(name);
        cin >> age;
        age_vector.push_back(age);

        // enter is considered a key, so cin.get(ch) will be able to read it
        cin.get(ch);
    }

    // make copy of name
    vector <string> name_vector_copy{};
    for(int i=0;i<name_vector.size(); ++i){
        name_vector_copy.push_back(name_vector[i]);
    }

    // make new age vector
    vector <int> age_sorted(age_vector.size());

    // sorting name vector
    sort(name_vector.begin(), name_vector.end());

    for(int i=0; i<name_vector_copy.size(); ++i){
        int new_index{};
        new_index = find_index(name_vector, name_vector_copy[i]);

        age_sorted[new_index] = age_vector[i];
    }

    cout << "Sorted names:\n";

    for(string n:name_vector) cout << n << ' ';

    cout << '\n';

    cout << "and corresponding ages...\n";

    for(double a : age_sorted) cout << a << ' ';

    cout << '\n';

   return 0;
}