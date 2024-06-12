// Exercise 3 from Chapter 11 of the book
// Programming: Principles and Practice Using C++

// Goal: To write a program to remove all vowels from a file.

#include "../../../std_lib_facilities.h"

bool is_vowel(char ch)
{
    string vowels{"AEIOUaeiou"};
    for(char c:vowels){
        if(ch == c) return true;
    }
    return false;
}

int main()
{
   string prompt{">>>"};
   cout << "<<<Please insert the name of the input file: \n"
        << prompt;

    string iname{};
    cin >> iname;
    ifstream ist{iname};
    if(!ist) error("<<<Can't open input file ", iname);

    cout << "<<<What is the desired name of the output file?\n"
         << prompt;
    string oname{};
    cin >> oname;
    ofstream ost{oname};

    // reading loop
    for(char ch; ist.get(ch); ){
        // if character is not a vowel, put it into ost
        if(!is_vowel(ch)) ost << ch;
    }
}