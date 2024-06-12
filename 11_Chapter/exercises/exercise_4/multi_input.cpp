// Exercise 4 from Chapter 11 of the book
// Programming: Principles and Practice Using C++

// Goal: read integer numbers in one of the following bases: octal, decimal, hexadecimal
// Convert all numbers to decimal and output the values in a table.

#include "../../../std_lib_facilities.h"

int main()
{
    string prompt{">>>"};
    string quit {"q"};    // the quit character
    string message{"converts to"};
    string base{};
    char octal_char {'0'};
    char hexa_char{'X'};

    cout << "<<<Please introduce an integer value, preceded with the respective base\n"
         << "<<<'0' for octal, \"0X\" for hexadecimal\n"
         << "<<<To quit press 'q'\n"
         << prompt;

    // read each number into a stringstream
    // test first character: if numeric, convert to int
    // if 0 read as octal
    // if 0x read as hexadecimal

    ostringstream os{};  // initialise ostringstream
    for(string s{}; cin >> s; ){
        if (s==quit) break;
        istringstream is{s}; // read the string into the stringstream

        int num;
        char ch{};

        // read 1st character
        is.get(ch);

        if(ch == octal_char){
            // read next character
            is.get(ch);

            if(ch == hexa_char){
                is >> hex >> num;
                base = "hexadecimal";
                os << showbase << hex << num << "\t\t";
            }
            else{
                is.putback(ch);
                // read as octal
                is >> oct >> num;
                base = "octal";
                os << showbase << oct << num << "\t";
            }
        }
        else{
            //put the character back
            is.putback(ch);
            
            // read as decimal
            is >> dec >> num;
            base = "decimal";
            os << showbase << dec << num << "\t";
        }

        if(!is){
            // clear the flags
            is.clear();
            
            error(is.str(), " could not be converted to a number");
        }
        os << base << "\t" << message << '\t' << dec << num << "\tdecimal\n";  

        cout << prompt;
    }
    cout << os.str().c_str();
}
