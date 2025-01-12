// "Programming: Principles and Practice Using C++" CH 17
// Exercise 3, 4 and 5

// Author: Bernardo Alves

//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
void to_lower(char* s){
    // replace all uppercase characters in C-style string
    // by their lowercase equivalent
    int i=0; // iterator variable
    while(true){
        if(s[i]==0) return; // reached the end of the string
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;    // convert assuming
                                                            // ASCII
        ++i;
    }
}

//------------------------------------------------------------------------------
char* strdup(const char* s){
    // do not use any std library functions

    // find the size of the original string
    int len{0};
    while (s[len]){
        ++len;
    }
    
    // allocate memory in the free store
    char* c = new char[len+1];

    // copy the contents of the original C-style string
    for(int i=0; i<len; ++i){
        c[i] = s[i];
    }

    // add the terminating zero
    c[len] = 0;

    return c;

}
//------------------------------------------------------------------------------
void print(char* c){
    int i=0;
    while(c[i]){
        std::cout<<c[i];
        ++i;
    }
}

void print(const char* c){
    int i=0;
    while(c[i]){
        std::cout<<c[i];
        ++i;
    }
}
//------------------------------------------------------------------------------
const char* findx(const char* s, const char* x){
    // checks for string x in s
    // if it finds returns pointer to the character of s corresponding to the
    // beginning of the occurrence
    int i = 0, j = 0;
    while(i<strlen(s)){
        // match the 1st character of x
        if(s[i]==x[0]){
            ++i;
            ++j;
            while(j<strlen(x)){
                if(s[i] == x[j]){
                    ++i;
                    ++j;
                    continue;
                }
                else{
                    j=0;
                    ++i;
                    break;
                }
            }
            // check if we found a full occurrence of x in s
            if(j==strlen(x)){
                const char* c = &s[i-j];
                return c;
            }

            // in case we did not, the if clauses will end
            // and we resume with the 1st while loop at the top
        }
        // did not match 1st character of x, so we move 1 character
        // right on s and re-try
        else{
            ++i;
        }
    }
    // in case no occurrence of x was found:
    return nullptr;
}
//------------------------------------------------------------------------------
int main()
try{
    char c[] = "FOR tesTINg PurposES";  // array of characters
    to_lower(c);
    std::cout<< c << '\n';

    // exercise 4
    char c1[] = "C-Style String. Very Original...";
    char* c2 = strdup(c1);

    print(c2);

    // exercise 5
    char* c3 = "Peanut";
    char* c4 = "Is there a Peanut here?";

    const char* c5 = findx(c4, c3);

    std::cout<<'\n';

    print(c5);
}
catch(std::exception& e){
    std::cerr<<e.what();
    return 1;
}
catch(...){
    std::cerr<<"Unknown exception thrown...";
    return 2;
}

//------------------------------------------------------------------------------