// Exercise 7 from Chapter 10 of the book
// Programming: Principles and Practice using C++ by Bjarne Stroustrup

// Goal: Define a version of the calculator from Chapter 7 that accepts Roman numerals
// instead of the usual Arabic ones

// This program will make use of the Roman_int class already defined

/*
    Simple calculator

    Revision history:

        Revised by Bernardo Alves November 2022;
        Originally written by Bjarne Stroustrup Spring 2004;

    This program implements a basic expression calculator.
    Input from cin
    Output to cout

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Help
        Calculation Statement
    Statement:
        Expression
        Variable-Declaration
        Constant-Declaration
        Assignment
    Print:
        ';'
    Quit:
        "quit"
    Help:
        "help"
        "Help"
    Expression:
        Term
        Expression + Term
        Expression - Term
    Variable-Declaration:
        "let" Name '=' Expression
    Constant-Declaration:
        "const" Name '=' Expression
    Assignment:
        Name '=' Expression
    Term:
        Sub-term
        Term * Sub-term
        Term / Sub-term
        Term % Sub-term
    Name:
        Letter
        Name Digit
        Name Letter
        Name'_'
    Sub-term:
        Primary-Function
        Primary-Function !
    Primary-Function:
        Primary
        Primary'^'Expression
        "sqrt"(Expression)
    Primary:
        Number
        Variable
        (Expression)
        sqrt(Expression)
        pow(Expression',' Expression) -> primary^(expression)
        - Primary
        + Primary
    Number:
        floating-point-literal

    Input comes from cin through the Token_stream named ts.
*/

#include "../../../std_lib_facilities.h"
#include "Roman_int.h"

//------------------------------------------------------------------------------

const char number = '8'; // t.kind == number means that t is a number Token
// const char quit = 'q'; t.kind == quit means that t is a quit Token
const char print = ';';  // t.kind == print means that t is a print Token

const char let = 'L';   // variable declaration Token
const char constant = 'C'; // constant declaration Token
const char var = 'V';   // used to indicate a variable 'Variable'
const char name = 'a';  // name Token
const char help = 'h';  // help Token
const char Roman = 'R'; // Roman numeral Token   
const char newline = '\n';  //new line character

const string help_key_1 = "Help";    // help key
const string help_key_2 = "help";    // help key

const string result = "= "; // used to indicate that what follows is a result
const string quit = "quit"; // exit keyword

const string var_declkey = "let";   // variable declaration keyword
const string const_declkey = "const";    // constant declaration keyword

const string square_root = "sqrt";  // name of square root function

//------------------------------------------------------------------------------

char print_help()
    // function prints user guide
{
    cout << "This program is a simple calculator \n"
         << "Just type mathematical expressions and press Enter \n"
         << "\nYou can declare variables:\n"
         << "Use \"let var_name = expression\" to declare them\n"
         << "\nYou can also define constants:\n"
         << "Type \"const var_name = expression\" to declare them\n"
         << "\nIt is possible to change the value of variables:\n"
         << "\"var_name = expression\" to assign a new value\n"
         << "\nIf an error is found enter ';' to continue\n"
         << "To exit, enter \"quit\" \n";
    
    return '\n';
}

//------------------------------------------------------------------------------

class Variable{
public:
    string name;
    double value;
    char kind;
    Variable(string n, double val, char k) :name{n}, value{val}, kind{k} { }
};

//------------------------------------------------------------------------------

class Token{
public:
    char kind;  // what kind of token
    double value;   // for numbers: a value
    string name;
    Token() : kind{0} {};   // default constructor
    Token(char ch) :kind{ch} { }
    Token(char ch, double val) :kind{ch}, value{val} { }    // initialize kind
                                                            // and value
    Token(char ch, string n) :kind{ch}, name{n} { }         // initialize kind
                                                            // and name
};

//------------------------------------------------------------------------------

class Token_stream{
public:
    Token get();    // get a Token
    void putback(Token t);  // put a Token back into the stream
    void ignore(char c);    // discard characters up to and including a c
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

    cin.get(ch);
    if(isspace(ch)){
        if(ch == newline) return Token(print);
        cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)
    }
  
    switch(ch){
        case print:   // for print
        // case quit:   // for quit
        case '!':   // for factorial
        case '{': 
        case '}':
        case '(': 
        case ')':
        case ',':
        case '^': 
        case '*': 
        case '/': 
        case '+': 
        case '-': 
        case '%':
        case '=':
            return Token{ch};   // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);        // put digit back into the input stream
            double val;         
            cin >> val;             // read a floating-point number
            return Token{number, val}; 

        }
        default:
            if(isalpha(ch)){
                string s;
                s += ch;

                while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) 
                    s+=ch;
                cin.putback(ch);
                if(s == var_declkey) return Token{let}; // var decl keyword found
                if(s == const_declkey) return Token{constant};
                if(s == help_key_1 || s == help_key_2) return Token(help);
                if(is_roman(s)) return Token(Roman, s); // a Roman numeral has been found
                return Token{name, s};
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char c)
    // c represents the kind of Token
    {
        // first look in buffer:
        if(full && c == buffer.kind) {
            full = false;
            return;
        }
        full = false;

        // now look in the input stream
        char ch = 0;
        while(cin >> ch)
            if(ch == c) return;
    }

//------------------------------------------------------------------------------

class Symbol_table{
public:
    vector <Variable> var_table;
    double get(string s);
    void set(string s, double d);
    bool is_declared(string s);
    double declare(string s, double d, char k);        
};

double Symbol_table::get(string s)
    // returns the value of variable with name s
{
    for(const Variable& v : var_table)
        if(v.name == s) return v.value;
    error("get: undefined variable ", s);
}

void Symbol_table::set(string s, double d)
    // This function sets the value of Variable s to d
{
    for(Variable& v:var_table)
        if(v.name == s && v.kind == var){
            v.value = d;
            return;
        } else if(v.name == s && v.kind == constant){
            error("set: cannot set the value of a constant");
        }
    error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string s)
    // is var already in the var_table vector?
{
    for(const Variable& v:var_table)
        if(v.name == s) return true;
    return false;
}

double Symbol_table::declare(string s, double d, char k)
    // Add Variable {var, val, kind} to var_table vector
{
    if(is_declared(s)) error(s, " defined twice");
    var_table.push_back(Variable{s, d, k});
    return d;
}

//------------------------------------------------------------------------------

int factorial(int num)
{
    if(num == 0){
        return 1;
    } else {
        return num *= factorial(num - 1);
    }
}

//------------------------------------------------------------------------------

Symbol_table table;     // this table will store all Variables
                        // declared by user

Token_stream ts;    // provides get() and putback()

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()
{
    Token t = ts.get();
    switch (t.kind){
        case '(':     // handle '('expression')'   
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')') error("')' expected");
            return d;
        }
        case '{':     // handle '{'expression'}'
        {
            double d = expression();
            t = ts.get();
            if(t.kind != '}') error("'}' expected");
            return d;
        }
        case number:   
            return t.value;     //return the number's value
        case name:
            return table.get(t.name);
        case Roman:
        {
            Roman_int r{t.name};
            return r.as_int();
        }
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}

double primary_function()
{
    Token t = ts.get();
    if(t.kind == name && t.name == square_root){
        t = ts.get();
        if(t.kind != '(') error("'(' expected after sqrt");

        double d = expression();

        if(d < 0) error("square root of negative number");

        t = ts.get();
        if(t.kind != ')') error("')' expected");

        return sqrt(d);
    }

    ts.putback(t);

    double left = primary();
    t = ts.get();
    switch(t.kind){
        case '^':
            return pow(left, expression());
        default:
            ts.putback(t);
            return left;
    }
}

double sub_term()
{
    double left = primary_function();
    Token t = ts.get();
    switch(t.kind){
        case '!':
        {
            int num = left;    //initializing num as an integer
            left = factorial(num);
            return left;
        }
        default:
            ts.putback(t);  // cannot handle the Token here, so put it back
                            // in the Token_stream
            return left;
    }
}

double term()
{
    double left = sub_term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '*':
                left *= sub_term();
                t = ts.get();
                break;
            case '/':
            {
                double d = sub_term();
                if(d == 0) error("divide by 0");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = sub_term();
                if(d == 0) error("%: divide by 0");
                left = fmod(left, d);
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

void clean_up_mess()
{
    ts.ignore(print);
}

double var_declaration()
    // Assume "let" was already taken care of
    // handle: name '=' expression
    // declare a variable Variable
{
    Token t = ts.get(); 
    if(t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error(" = missing in the declaration of ", var_name);
    
    double d = expression();
    table.declare(var_name, d, var);
    return d;
}

double const_declaration()
    // Assume "constant" was taken care of
    // handle: name '=' expression
    // declare a constant Variable
{
    Token t = ts.get();
    if(t.kind != name) error("name expected in declaration");
    string const_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error(" = missing in declaration of ", const_name);

    double d = expression();
    table.declare(const_name, d, constant);
    return d;
}

double assignment(string s)
    // Assume a Name was found, not preceded by "let"
    // handle: Name '=' Expression
    // change the value of Variable with the name == Name to Expression
{

    // pre-condition: a variable with that name already exists
    // verification performed inside set_value

    double d = expression();

    table.set(s, d);

    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind){
        case let:
            return var_declaration();
        case constant:
            return const_declaration();
        case name:
        {
            Token t2 = ts.get();

            if(t2.kind != '='){ 
                cin.putback(t2.kind);
                ts.putback(t);
                return expression();
            }

            return assignment(t.name);
        }
        default:
            ts.putback(t);
            return expression();
    }
}

void calculate()    // expression evaluation loop
{
    while(cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while(t.kind == print) t = ts.get();    // first discard all "prints"
        if(t.name == quit) return;
        if(t.kind == help){
            Token t2 = ts.get();
            if(t2.kind != print){
                cin.putback(t2.kind);
                ts.putback(t);
                cout << result << statement() << '\n';
            } else {
                cout << print_help();
            }
        } else{
            ts.putback(t);
            cout << result << statement() << '\n';
        }
        
    }
    catch(exception& e) {
        cerr << e.what() << '\n';   // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
{
    try {
        // predefine names:
        table.declare("pi", 3.1415926535, constant);
        table.declare("e", 2.7182818284, constant);

        calculate();
        
        keep_window_open();
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch(...)
    {
        cerr << "exception: \n";
        keep_window_open("~~");
        return 2;
    }
}
