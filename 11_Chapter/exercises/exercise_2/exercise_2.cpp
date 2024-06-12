// Exercise 2 from Chapter 11 of the book
// Programming: Principles and Practice Using C++

// Goal: Search for word occurrences and print lines where
// that word was found

#include "../../../std_lib_facilities.h"

int main()
{
    string prompt{">>>"};
    cout << "<<<Please introduce the name of the input file:\n"
         << prompt;
    string iname;
    cin >> iname;

    cout << "<<<What is the word you want to find?\n"
         << prompt;
    
    string word_to_look{};
    cin >> word_to_look;

    // initialise the ifstream and attach it to the file given by user
    ifstream ist{iname};
    if(!ist) error("<<<Can't open input file ", iname);

    // read line by line
    int line_counter = 0;
    string words{};

    while(getline(ist, words)){
        istringstream line{words};
        // get a whitespace separated word
        for(string s; line >> s; ){
            // check if the characters match
            for(int j=0; j<word_to_look.size(); ++j){
                // a match has been found
                if(s[j]==word_to_look[j]){
                    // was it the last character in the word_to_look?
                    if(j == word_to_look.size()-1){
                        cout << i << '\t' << line.str() << '\n';
                        break;
                    }
                    continue;
                }
                // if the characters do not match, get the next word
                else break;
            }
        }
        // after searching line, we have to increment the counter
        ++line_counter; 
    }
}