// This program implements the last calculator 
// program as described in chapter 6
// "Software - Principles and Practice using C++" by Bjarne Stroustrup

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
    char kind;  // what kind of token
    double value;   // for numbers: a value
    Token(char k) : kind{k}, value{0.0} {}  //construct from one value
    Token(char k, double v): kind{k}, value{v} {}   // construct from two values
};

//------------------------------------------------------------------------------

class Token_stream{
public:
    Token get();    // get a Token
    void putback(Token t);  // put a Token back into the stream
private:
    bool full{false};   // is there a Token in the buffer? It will be initialised
                        // to false
    Token buffer {0};   // putback will save its Token in the buffer
};

void Token_stream::putback(Token t)
{
    buffer = t;     // copy t to buffer
    full = true;    // buffer is now full
}

Token Token_stream::get()
{
    if(full) {      // do we already have a Token ready?
        full = false;   // remove Token from buffer
        return buffer;
    }
    char ch;
    cin >> ch;  // note that >> skips whitespace (space, newline, tab, etc.)
    switch(ch){
        case ';':   // for print
        case 'q':   // for quit
        case '(': case ')': case '*': case '/': case '+': case '-':
            return Token{ch};   // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);        // put digit back into the input stream
            double val;         
            cin >> val;             // read a floating-point number
            return Token{'8', val}; // let '8' represent "a number"

        }
        default:
            error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;    // provides get() and putback()

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()
{
    Token t = ts.get();
    switch (t.kind){
        case '(':   //handle '('expresion')'
            {
                double d = expression();
                t = ts.get();
                if(t.kind != ')') error("')' expected");
                return d;
            }
        case '8':   // kind '8' represents Tokens which are numbers
            return t.value;     //return the number's value
        default:
            error("primary expected");
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
                {
                    double d = primary();
                    if(d == 0) error("divide by 0");
                    left /= d;
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);  //put t back into the Token stream
                return left;
        }
    }
}

double expression()
{
    double left = term();   // read and evaluate a Term
    Token t = ts.get();  // get the next Token

    while(true){
        switch (t.kind){
            case '+':
                left += term(); //evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term(); //evaluate Term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t);  // put t back into the Token stream
                return left;    //finally: no more  + or -; return the answer
        }
    }
}


//------------------------------------------------------------------------------

int main()
{
    double val = 0;
    while(cin){
        Token t = ts.get();

        if(t.kind == 'q') break;    // 'q' for quit
        if(t.kind == ';')           // ';' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}