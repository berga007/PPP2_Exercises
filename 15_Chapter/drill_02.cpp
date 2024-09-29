// 2nd drill from Chapter 15 of the book:
// Programming: Principles and Practice Using C++ by Bjarne Stroustrup

// Author: Bernardo Alves

#include <iostream>
#include "../GUI/Window.h"  // get access to our windows lbrary
#include "../GUI/Graph.h"          // get access to our graphics library facilities

//------------------------------------------------------------------------------
// class definition drill

//------------------------------------------------------------------------------
// Helper functions
bool is_name_valid(const string& n, vector<char> chars)
{
    // iterate through all invalid characters
    for(char c: chars){
        // iterate through all characters in the string
        for(int i=0; i<n.size(); ++i){
            // check for a match
            if(n[i] == c) return false;
        }
    }
    // did not return so far, then name is valid
    return true;
}

bool is_person(string first_name, string last_name, int age){
    if(0 > age || 150<age) return false;
    
    vector<char> prohibited_chars{
        ';', ':', '"', '\'', 
        '[', ']', '*', '&', 
        '^', '%', '$','#', 
        '@', '!'
    };
    
    if(!is_name_valid(first_name, prohibited_chars)) return false;
    if(!is_name_valid(last_name, prohibited_chars)) return false;

    return true;
}

//------------------------------------------------------------------------------
// The class Person

struct Person{
    Person(string first_nn, string last_nn, int aa);
    Person() : first_n{""}, last_n{""}, a{0} { }
    
    // read member functions
    string name() const {return first_n+' '+last_n; }
    int age() const {return a; }

    // write member functions
    void set_first_name(string new_name) {first_n = new_name; }
    void set_last_name(string new_name) {last_n = new_name; }
    void set_age(int new_age) {a = new_age; }
private:
    string first_n;   // person's 1st name
    string last_n;  // person's last name
    int a;      // person's age
};

// constructor with simple check
Person::Person(string first_nn, string last_nn, int aa)
    : first_n{first_nn},last_n{last_nn}, a{aa}
{
    if(!is_person(first_nn, last_nn, aa)) error("Invalid person's data");
}

//------------------------------------------------------------------------------
// operator overloading
ostream& operator<<(ostream& os, const Person& p){
    return os << "Person details:\n"
       << "Name: " << p.name() << '\n'
       << "Age: "  << p.age()  << '\n';
}

istream& operator>>(istream& is, Person& p){
    string s1, s2;
    int n;
    std::cout<< "1st Name: ";
    is >> s1;

    std::cout<< "2nd Name: ";
    is >> s2;

    std::cout << "Age: ";
    is >> n;

    // if we cannot read data just terminate
    if(!is){
        is.clear(ios_base::failbit);
        return is;
    }

    if(!is_person(s1, s2, n)) error("Invalid person's data");

    p.set_first_name(s1);
    p.set_last_name(s2);
    p.set_age(n);

    return is;
}

//------------------------------------------------------------------------------
int main()
try{
    string prompt{">>>"};
    Person one_person{"Goofy", "Smith", 63};
    std::cout << one_person;
/*
    Person p{};
    std::cout << "Insert person's details\n"
              << prompt;
    std::cin >> p;

    std::cout << p.name() << " was succesfully registered in our system\n";
*/

    vector<Person> people{};
    std::cout << "Insert person's details below:\n"
              << prompt;

    // read loop
    for(Person p; std::cin>>p; ){
        people.push_back(p);
        std::cout << '\n';
    }

    std::cout << '\n';

    // write loop
    for(Person p:people){
        std::cout << p << '\n';
    }

}
catch(exception &e){
    std::cerr << e.what();
}
catch(...){
    std::cout << "Some error has occured...";
}

//------------------------------------------------------------------------------