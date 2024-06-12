// Exercise 6 from chapter 6
// "Programming - Principles and Practice using C++" by Bjarne Stroustrup

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------
// Function splits words from a given string and saves each one
// in a vector

vector<string> splitSentence(string str)
{
    // get str length
    int n = str.length();

    // new empty string
    string word = "";

    // New empty vector of strings. 
    // Each index has a string corresponding to each word
    vector <string> words = {};

    // Iterate over the str string, character by character
    for(int i=0; i<n; i++)
    {
        // if empty space is found, then the word is completed
        if(str[i] == ' '){
            words.push_back(word);
            word = "";
        }
        // Sentences must end with ' ' (empty space)
        else if(i == (n-1) && str[i] != ' ') {
            error("not Ok. Sentences must end with ' '");
        }
        else{
            // Word is not finished, so concatenate the character to it
            word += str[i];
        }
    }

    return words;
}

//------------------------------------------------------------------------------

void article(string word){
    if(word == "the"){

    }
    else{
        error("Not Ok. Article");
    }
}


void noun(string word){
    bool found = false;
    vector <string> allowed_nouns = {
        "fish", "birds", "C++"
    };

    for(string noun:allowed_nouns){
        if(word == noun){
            found = true;
            break;
        }
    }

    if(!found) error("Not Ok. noun");

}

void verb(string word){
    bool found = false;
    vector <string> allowed_verbs = {
        "rules", "fly", "swim"

    };

    for(string verb:allowed_verbs){
        if(word == verb){
            found = true;
            break;
        }
    }

    if(!found) error("Not Ok. verb");
    
}

void conjunctions(string word){
    bool found = false;
    vector <string> allowed_conjuntions = {
        "and", "or", "but"
    };

    for(string conjunction:allowed_conjuntions){
        if(word == conjunction){
            found = true;
            break;
        }
    }

    if(!found) error("Not Ok. conjunction");

}

void sentence(vector <string> words){
    int i = 0;
    while(true){
        article(words[i]);
        ++i;
        noun(words[i]);
        ++i;
        verb(words[i]);
        ++i;
        if(i == words.size() - 1)
            break;
        conjunctions(words[i]);
        ++i;

    }
}
//------------------------------------------------------------------------------
int main()
{
    string phrase;

    cout << "Please insert the sentence. \n";

    // using cin to read a string will stop at the first whitespace
    // if string is composed of multiple words, it will only get the first

    // use getline() instead
    
    getline(cin, phrase);

    // Get each of the words inserted in the sentence
    vector <string> word_vector = splitSentence(phrase);

    for(string w:word_vector){
        cout << w << '\n';
    }

    sentence(word_vector);

    cout << "Ok.";

}