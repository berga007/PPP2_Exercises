/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

//------------------------------------------------------------------------------

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Token {
	/*
		Token is the basic unit of this program
		Three types of Tokens, numbers, names and operators
	*/
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }	// initialise kind 
	Token(char ch, double val) :kind(ch), value(val) { }	// initialise kind 
															// and value
    Token(char ch, string n) :kind(ch), name(n) {}			// initialise kind
															// and name
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }	// puts t in the buffer

	void ignore(char c);
};

const char let = 'L';	// declaration Token
const char quit = 'Q';
const char print = ';';
const char number = '8';	// t.kind == number means that t is a number Token
const char name = 'a';		// t.kind == name means that t is a name Token

const char declkey = '#';	// declaration keyword

Token Token_stream::get()
// This function reads from cin and returns Tokens
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
    case quit:
    case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
		return Token(ch);
	case declkey:
		return Token(let);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

//------------------------------------------------------------------------------

vector<Variable> names;

double get_value(string s)
// search for a variable with name s and return its value
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
// set the value of Variable with name s to d
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
// if Variable with name s already defined, return true
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double define_name(string var, double val)
// Add Variable {var, val} to names vector
{
	if(is_declared(var)) error(var, "declared twice");
	names.push_back(Variable(var, val));
	return val;
}

//------------------------------------------------------------------------------

Token_stream ts;	// provides get(), unget() and ignore()

double expression();	// forward declaration of function so that primary()
						// can call expression()

//------------------------------------------------------------------------------

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':	// handle '('Expression')'
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
    case '+':
        return primary();
	case number:	// if it is a name Token, get its value
		return t.value;
	case name:
	{
		if(t.name == "sqrt"){   // handle sqrt'('...')'
			t = ts.get();
			if(t.kind != '(') error("'(' expected");

			double d = expression();

			if(d<0) error("Square root of negative number is imaginary");

			t = ts.get();
			if(t.kind != ')') error("')' expected");

			return sqrt(d);
		}
		else if(t.name=="pow"){ // handle pow'('x,i')'
			t = ts.get();
			
			if(t.kind != '(') error("'(' expected");

			double d = expression();

			t = ts.get();
			if(t.kind!= ',') error("',' expected in pow(x,y)");

			int i = narrow_cast<int>(expression());

			t = ts.get();
			if(t.kind != ')') error("')' expected");

			return pow(d, i);

		}
		return get_value(t.name);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
// Assume 'let' was already read
// handle Name "= "  Expression
// Initialise a Variable with name var_name and value expression
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	
	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()	// expression evaluation loop
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()

try {
	define_name("k", 1000);
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}