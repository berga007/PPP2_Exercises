// Exercise 1 from Chapter 11 of the book
// Programming: Principles and Practice Using C++

// Goal: Write a program that converts text to lower case

#include "../../../std_lib_facilities.h"

int main()
{
    string prompt{">>>"};
    cout << "<<<Please enter input file name:\n"
         << prompt;
    string iname{};
    cin >> iname;

    ifstream ifs{iname};
    if(!ifs) error("Can't open input file ", iname);

    string oname{};
    cout << "What is the name of the output file "
         << "to where you would like to store the all lower case version?\n"
         << prompt;

    cin >> oname;
    ofstream ofs{oname};
    if(!ofs) error("Can't open output file ", oname);

    // reading loop
    for(char ch; ifs.get(ch); ){
        if(isalpha(ch)) ch = tolower(ch);

        ofs.put(ch);
    }
}
