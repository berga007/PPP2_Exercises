// This program reads words into a word vector
// replaces 'disliked' words with "BLEEP" and then prints
// back all the others

#include "../std_lib_facilities.h"

int main()
{
    vector<string> disliked_words = {"Broccoli", "Banana", "Potato"};   // vector with disliked words
    vector<string> words;   // initialising the vector to read the input
    for(string word; cin>>word; )   // read whitespace-separated words
    {
        for(string disliked_word: disliked_words){
            if(word == disliked_word)
                word = "BLEEP";     // in case word matches a disliked word, it is replaced
                                    // with "BLEEP"
        }
        words.push_back(word);      // put the word into the words vector
    }
    for(string word: words)
        cout << word << '\n';
}