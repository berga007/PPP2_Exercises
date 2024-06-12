// Exercise 3 from Chapter 9 of the book
// Programming Principles and Practice Using C++

// Goal: Overload the output operator <<, == and !=

// ---------------------------------------------------------------------- /
// Sorting alphabetically is not that simple

#include "../../std_lib_facilities.h"

struct Name_pairs{
public:
    void sort();
    void print() const;
    void read_names();
    void read_ages();
    vector <string> name() const { return name_vector; }
    vector <double> age() const { return age_vector; }

// implementation details
private:
    vector <string> name_vector;
    vector <double> age_vector;    
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
        name_vector.push_back(temp);
    }
}

void Name_pairs::read_ages()
{
    double temp{0.0};
    for(string n:name_vector)
    {
        cout << "<< " << n << "'s age: ";
        cin >> temp;
        age_vector.push_back(temp);
    }
}


void Name_pairs::sort()
{
    // Member-function to sort alphabetically all names and the
    // correspnding ages
    // Note: this works because strings have already the > (comparison) operator defined
    
    // Bubble sort:
    for(int i=0; i<name_vector.size(); ++i){
        for(int j=0; j<name_vector.size()-1; ++j){
            if(name_vector[j]>name_vector[j+1]){
                swap(name_vector[j], name_vector[j+1]);
                swap(age_vector[j], age_vector[j+1]);
            }
        }
    }
    
}

void Name_pairs::print() const
{
    // function prints (name, age) pairs according to
    // the order determined by the name vector
    for(int i=0; i<name_vector.size(); ++i){
        cout << '(' << name_vector[i] << ", " << age_vector[i] << ")\n"; 
    }
}

// operator overloading

// output operator
ostream& operator<<(ostream& os, const Name_pairs& name_pair)
{
    // function prints (name, age) pairs according to
    // the order determined by the name vector
    for(int i=0; i<name_pair.name().size(); ++i){
        os << '(' << name_pair.name()[i] << ", " << name_pair.age()[i] << ")\n"; 
    }
    return os;
}

// equality operator ==
bool operator ==(const Name_pairs& name_pair1, const Name_pairs& name_pair2)
{
    return name_pair1.name() == name_pair2.name()
           && name_pair1.age() == name_pair2.age();
}

// inequality operator !=
bool operator !=(const Name_pairs& name_pair1, const Name_pairs& name_pair2)
{
    return !(name_pair1 == name_pair2);
}

int main()
{
    // initialise the object of type Name_pairs
    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();
    pairs.print();
    pairs.sort();

    Name_pairs pairs2{};
    pairs2.read_names();
    pairs2.read_ages();

    cout << pairs << pairs2;

    cout << (pairs==pairs2);

    return 0;
}