// exercise 10 from chapter 4, rock paper scissors game
#include "../../std_lib_facilities.h"

int main()
{
    cout << "Let's play a game! \n"
         << "Rock, Paper, Scissors \n"
         << "Introduce the character 'R' for Rock, 'P' for Paper or 'S' for Scissors\n";

    char usr_hand = 'f'; // initialising the variable for holding the player's move
    vector <char> computer_moves = {'P', 'R', 'S', 'S', 'S', 'P', 'P', 'R', 'R', 'P'};

    int i = 0;  // variable to keep track of the round number

    for(char move:computer_moves){
        cout << "Ready... Round " << i+1 << '\n';
        cin >> usr_hand;
        
        if(move == 'P'){
            cout << "I picked Paper\n";
        }
        else if(move == 'S'){
            cout << "I picked Scissors\n";
        }
        else{
            cout << "I picked Rock\n";
        }

        switch(usr_hand){
        case 'P':
            if(move == 'P'){
                cout << "Draw!\n";
            }
            else if(move == 'S'){
                cout << "You Lost!\n";
            }
            else{
                cout << "You won!\n";
            }
            break;
        case 'S':
            if(move == 'P'){
                cout << "You won!\n";
            }
            else if(move == 'S'){
                cout << "Draw!\n";
            }
            else{
                cout << "You lost!\n";
            }
            break;
        case 'R':
            if(move == 'P'){
                cout << "You lost!\n";
            }
            else if(move == 'S'){
                cout << "You won!\n";
            }
            else{
                cout << "Draw!\n";
            }
            break;
        default:
            cout << "Please enter a valid character, 'R', 'P' or 'S' only\n";
            break;
        }
        ++i;
        cout << '\n';
    }
}