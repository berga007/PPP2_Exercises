// This program implements a simple version of the bulls & cows game
#include "../../std_lib_facilities.h"

bool all_diff(vector <int> v)
{
    for(int i=0; i<v.size() - 1; ++i)
    {
        for(int j=i+1; j<v.size(); ++j)
        {
            if(v[i] == v[j]) return false; 
        }
    }
    return true;
}

int play_bulls_cows(vector<int> solution, vector<int> usr_guess)
{
    int bull = 0, cow = 0;  // declaring variables to hold number of bulls and cows

    string s1, s2;  // declaring strings for output message

    // pre-conditions: number consists of 4 digits, all different
    if(usr_guess.size() != 4) error("Please insert 4 different digits");
    if(!all_diff(usr_guess)) error("there are repeated digits.");


    for(int i=0; i<solution.size(); ++i)
    {
        for(int j=0; j<solution.size(); ++j)
        {
            if(j==i && usr_guess[j] == solution[i]){
                ++bull;
            }
            else if(usr_guess[j] == solution[i]){
                ++cow;
            }
        }
    }

    if(bull == 1){
        s1 = "bull";
    }
    else {
        s1 = "bulls";
    }

    if(cow == 1){
        s2 = "cow";
    }
    else{
        s2 = "cows";
    }

    cout << bull << ' ' << s1 << " and " << cow << ' ' << s2 << '\n';

    return bull;
}

int main()
{
    int bull = 0;   // initialising the variable

    while(bull != 4){
        
        bull = 0;   // At the beginning of each iteration bull should be 0

        vector <int> usr_guess = {}; // variable to hold usr guess in vector
        vector <int> guess_reversed = {};   // variable that stores each of the 
                                            // guess digits in reverse

        int num;    // num integer will store the user given input
        
        cin >> num; // store the user given input at each iteration

        // convert the integer to vector format to be used by play_bulls_cows func
        while(num){
            guess_reversed.push_back(num % 10);
            num /= 10;
        }
        // reverse the order to get the original number
        for(int i=1; i<=guess_reversed.size(); ++i)
        {
            usr_guess.push_back(
                guess_reversed[guess_reversed.size()-i]
            );
        }

        bull = play_bulls_cows({1, 2, 3, 4}, usr_guess);
    }
}