// exercise 4 from chapter 4

#include "../../std_lib_facilities.h"

int main()
{
    int num;    // declaring the variable to store the number inserted
    char guess_status = ' ';
    int guess = 0;  // Initialising the guess number
    int step = 0;   // Initialising step. Will be used to calculate
                    // next guess
    int upper_limit = 100;  // Defining the upper limit of possible numbers
    int lower_limit = 1;    // Defining the lower limit of possible numbers

    // Writing the prompt to user
    cout << "Welcome to the number guessing game!\n"
         << '\n'
         << "You will enter a number between 1 and 100, and I will try to guess it. \n"
         << "After entering the number I will make a guess. For each guess I make, please type:\n"
         << "\'h\' if the number is higher than my guess;\n"
         << "\'l\' if the number is lower than my guess;\n"
         << "\'y\' if I guessed correctly.\n";
    cout << "Please enter an integer value between 1 and 100 \n";
    
    cin >> num; // read into num

    // Try to guess the value, stop when guessed right

    // The guess status variable
    // It will be used to know if guess is correct
    // or, if incorrect, to know wheter the number
    // is higher or lower than the guess made.

    int i = 0;  // Simple loop variable to keep track of
                // number of attempts

    for(char guess_status = ' '; guess_status != 'y'; ++i){
        
        // Calculate guess
        step = (upper_limit - lower_limit) / 2;
        guess = lower_limit + step;

        // in case more than 7 attempts were made, terminate the loop
        if(i>5){
            cout << "Your number is " << guess << '\n';
            break;
        }

        cout << "My guess is: " << guess << '\n'
             << "Type \'y\' if the number was guessed, \n"
             << "Type \'h\' if the number is higher, \n"
             << "Type \'l\' if the number is lower. \n";

        cin >> guess_status; // Update guess_status with user feedback

        switch(guess_status){
        case 'y':
            cout << "Guessed correctly in " << ++i << " attempts.\n";
            break;
        case 'h':
            lower_limit = ++guess;
            break;
        case 'l':
            upper_limit = --guess;
            break;
        default:
            cout << "Please type \'y\', \'h\' or \'l\' only.\n";
            cin >> guess_status;
            break;
        }
    }
}