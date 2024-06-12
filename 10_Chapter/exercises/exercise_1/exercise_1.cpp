// Exercise 1 from Chapter 10 of the book 
// Programming: Principles and Practice Using C++

// Goal: Write a program that produces the sum of all the numbers stored
// in a file of whitespace-separated integers

#include "../../../std_lib_facilities.h"

int main(){
    string prompt{">>>"};
    // open the input file:
    cout << "Please enter input file name\n"
         << prompt;
    string iname;
    cin >> iname;
    ifstream ifs{iname};
    if(!ifs) error("can't open input file ", iname);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit); // throw for bad()

    // variable to store the sum of all numbers read
    double sum{};

    for(double num; ifs >> num;){
        sum += num;
    }

    cout << "<<< The sum of all numbers stored in the file is:\n"
         << sum;
}