// Exercise 4 from chapter 6
// "Programming - Principles and Practice using C++" by Bjarne Stroustrup

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

// Class definition
class Name_value{
public:
    string name;
    double value;
    Name_value(string n, double val)
        :name{n}, value{val} { }
};

//------------------------------------------------------------------------------
int main()
{
    vector <Name_value> names_scores = {};
    string name, search_name;
    char option;
    double score, search_score;
    bool found_name = false, found_score = false;

    cout << "Please insert name value pairs"
         << '\n'
         << "To terminate the input insert 'NoName 0'"
         << '\n';

    while(true)
    {
        cin >> name >> score;
        Name_value pair{name, score};
        for(Name_value name_score: names_scores)
        {
            if(name_score.name == pair.name) error("Names have to be unique");
        }
        if(pair.name == "NoName" && pair.value == 0)
            break;
        names_scores.push_back(pair);
    }

    cout << "To search with a name insert 1 \n"
         << "To search for all names with a particular score, insert 2\n";

    cin >> option;

    switch (option)
    {
    case '1':
        cout << "Please insert a name to search in Database \n";
        cin >> search_name;

        for(Name_value entry:names_scores)
            if(entry.name == search_name)
            {
                cout << entry.value << '\n';
                found_name = true;
                break;
            }
        if(found_name == false)
            cout << "name not found \n";
        break;
    case '2':
        cout << "Please insert a score to search in the Database \n";
        cin >> search_score;
        for(Name_value entry:names_scores)
            if(entry.value == search_score)
            {
                cout << entry.name << '\n';
                found_score = true;
            }
        if(found_score == false)
            cout << "There are no names with that score on the database \n";
        break;
    default:
        error("Option not valid");
        break;
    }
}