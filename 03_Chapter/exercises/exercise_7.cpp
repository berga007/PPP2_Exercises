// This program sorts three words alphabetically

#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter three words.\n";     // Prompt to user enter three integer values
    string word1{"0"};
    string word2{"0"};    // initialising all three variables to store the strings given
    string word3{"0"};

    cin >> word1 >> word2 >> word3;    // reading the values to the variables

    int num1 = word1[0];
    int num2 = word2[0];
    int num3 = word3[0];

    if(num1 <= num2)
        if(num2 <= num3)
            cout << word1 << ", " << word2 << ", " << word3 << "\n";
        else
            if(num1 <= num3)
                cout << word1 << ", " << word3 << ", " << word2 << "\n";
            else
                cout << word3 << ", " << word1 << ", " << word2 << "\n";

    else        //num1 is bigger than num2
        if(num3 <= num1)    //then num1 is the biggest
            if(num3 <= num2)
                cout << word3 << ", " << word2 << ", " << word1 << "\n";

            else
                cout << word2 << ", " << word3 << ", " << word1 << "\n";
        else    //num3 is bigger than num1, which is bigger than num2
            cout << word2 << ", " << word1 << ", " << word3 << "\n";
}