// Section 11.7- Using non-standard separators of the book:
// Programming: Principles and Practice Using C++

// The goal is to read punctuated sentences and retrieve only the
// words, treating punctuation characters as whitespace 

// Author: Bernardo Alves

// User interface:
// ps.whitespace(";:,.");

// for (string word; ps>>word; )
//    vs.push_back(word);

#include "../std_lib_facilities.h"

class Punct_stream{   // like an istream, but the user can add to
                        // the set of whitesapce characters
public:
    Punct_stream(istream& is)
        : source{is}, sensitive{true} {}

    void whitespace(const string& s)    // make s the whitespace set
    {
        white = s;
    }

    void add_white(char c){white +=c; }  // add to the whitespace set
    bool is_whitespace(char c);          // is c in the whitesace set?

    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive(){ return sensitive; }

    // operator overloading, defined as a member function
    Punct_stream& operator>>(string& s);

    operator bool();

private:
    istream& source;        // character source
    istringstream buffer;   // buffer will do formatting
    string white;           // characters considered "whitespace"
    bool sensitive;         // is the stream case-sensitive?

};

// definitions
Punct_stream& Punct_stream::operator>>(string& s)
{
    string prompt{">>>"};
    while(!(buffer>>s)){   // try to read from buffer
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        cout << prompt;
        getline(source, line);  // we get a line from source

        // do chaarcter replacement as needed
        for(char& ch: line)
            if(is_whitespace(ch))
                ch = ' ';   // to space
            else if(!sensitive)
                ch = tolower(ch);   // to lower case
        
        buffer.str(line);   // put the string into stream
    }
    return *this;
}

bool Punct_stream::is_whitespace(char c)
{
    for(char w: white)
        if(c == w) return true;

    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && buffer.good();
}

int main()
    // given text input, produce a sorted list of all words in that text
    // ignore punctuation and case differences
    // eliminate duplicates from the output
{
    
    Punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^|~");   // note: \" means " in a string
    ps.case_sensitive(false);

    cout << "<<<Please enter words\n";
    vector<string> vs;

    for(string word; ps>>word; )
        vs.push_back(word); // read words

    sort(vs.begin(), vs.end()); // sort words in lexicographical order
    for(int i=0; i<vs.size(); ++i)  // write dictionary
        if(i==0 || vs[i] != vs[i-1]) cout << '\n' << vs[i];
}