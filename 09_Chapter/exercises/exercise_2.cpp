// Exercise 2 from Chapter 9 of the book
// Programming Principles and Practice Using C++

// Goal: Design and implement a Name_age pairs class

// ---------------------------------------------------------------------- /
#include "../../std_lib_facilities.h"

struct Name_pairs{
public:
    void sort();
    void print();
    void read_names();
    void read_ages();

// implementation details
private:
    vector <string> name;
    vector <double> age;    
};

// helper function to prompt the user
void prompt_user()
{
    cout << "Please enter the names you wish to store \n"
         << "To proceed enter 'p': \n";
}

// member functions
void Name_pairs::read_names()
{
    string temp{""};
    prompt_user();
    while(cin){
        cin >> temp;
        if(temp == "p") return;
        name.push_back(temp);
    }
}

void Name_pairs::read_ages()
{
    double temp{0.0};
    for(string n:name)
    {
        cout << "<< " << n << "'s age: ";
        cin >> temp;
        age.push_back(temp);
    }
}


void Name_pairs::sort()
{
    // Member-function to sort alphabetically all names and the
    // correspnding ages
    // Note: this works because strings have already the > (comparison) operator defined
    
    // Bubble sort:
    for(int i=0; i<name.size(); ++i){
        for(int j=0; j<name.size()-1; ++j){
            if(name[j]>name[j+1]){
                swap(name[j], name[j+1]);
                swap(age[j], age[j+1]);
            }
        }
    }
    
}

void Name_pairs::print()
{
    // function prints (name, age) pairs according to
    // the order determined by the name vector
    for(int i=0; i<name.size(); ++i){
        cout << '(' << name[i] << ", " << age[i] << ")\n"; 
    }
}

int main()
{
    // initialise the object of type Name_pairs
    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();
    pairs.print();
    pairs.sort();
    pairs.print();
    return 0;
}