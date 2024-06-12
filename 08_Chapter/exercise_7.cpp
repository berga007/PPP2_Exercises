// exercise 7 from chapter 8
// Programming: Principles and Practice Using C++

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

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
    string name1{}, name2{}, name3{}, name4{}, name5{};
    double age1{}, age2{}, age3{}, age4{}, age5{};

    cout << "Please insert 5 names:\n";
    cin >> name1 >> name2 >> name3 >> name4 >> name5;
    vector <string> name{name1, name2, name3, name4, name5};

    cout << "Insert the ages of the people whose name you inserted before:\n";
    cin >> age1 >> age2 >> age3 >> age4 >> age5;
    vector <double> age{age1, age2, age3, age4, age5};

    // make copy of name
    vector <string> name_copy{};
    for(int i=0;i<name.size(); ++i){
        name_copy.push_back(name[i]);
    }

    // make new age vector
    vector <int> age_sorted(age.size());

    // sorting name vector
    sort(name.begin(), name.end());

    for(int i=0; i<name_copy.size(); ++i){
        int new_index{};
        new_index = find_index(name, name_copy[i]);

        age_sorted[new_index] = age[i];
    }

    cout << "Sorted names:\n";

    for(string n:name) cout << n << ' ';

    cout << '\n';

    cout << "and corresponding ages...\n";

    for(double a : age_sorted) cout << a << ' ';

    cout << '\n';

   return 0;
}
