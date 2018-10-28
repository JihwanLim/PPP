
/*
	Simple calculator

	Revision history:
		Revised by Jihwan Lim April 2018
		Revised by Jihwan Lim February 2018
		Revised by Jihwan Lim January 2018
		Originally written by Jihwan Lim
			(ghwn5936@gmail.com) Winter 2017.

	This program implements a basic expression calculator.
	Input from cin; output to cout.
	
	The grammar for input is:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement

	Statement:
		Declaration
		Expression
		Function

	Declaration:
		"let" Name "=" Expression

	Function:
		Name "(" Expression ")"

	Print:
		;

	Quit:
		q

	Expression:
		Term
		Expression + Term
		Expression - Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		Name
		( Expression )
		+Primary
		-Primary
	Number:
		floating-point-literal

	Input comes from cin through the Token_stream called ts.
*/

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8';	// t.kind == number means that t is a number Token
const char quit = 'q';		// t.kind == quit means that t is a quit Token
const char print = ';';		// t.kind == print means that t is a print Token
const char name = 'a';			// name Token
const char let = 'L';			// declaration Token
const char func = 'f';
const string declkey = "let";	// declaration keyword
const string prompt = "> ";
const string result = "= ";	// used to indicate that what follows is a result


//------------------------------------------------------------------------------

class Variable {
public:
	string name;
	double value;

	Variable(string n, double v)
		: name(n), value(v) { }
};

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

vector<string> func_table;

//------------------------------------------------------------------------------

double get_value(string s)	// return the value of the Variable named s
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

void set_value(string s, double d)	// set the Variable named s to d
{
	for (Variable& v : var_table) {
		if (v.name == s) {
			v.value = d;
			return;
		}
	}
	error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
	string name;

    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
	Token(char ch, string n)
		:kind(ch), name(n), value(0) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();
	Token_stream(const istream&);
	Token get();			// get a Token
	void putback(Token t);	// put a Token back
	void ignore(char c);	// discard characters up to and including a c
private:
	bool full;
	Token buffer;
};

//------------------------------------------------------------------------------

Token_stream::Token_stream()
	: full(false), buffer(0)
{
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case print:
	case quit:
	case '(': case ')': 
	case '+': case '-': 
	case '*': case '/':
	case '%':
	case '=':
	case ',':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			for (string& f : func_table)
				if (s == f)	return Token(func, s);
			return Token(name, s);
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)	// c represents the kind of Token
{
	// first look in buffer
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	// now search input
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

double expression(Token_stream&);  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term(Token_stream&);        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary(Token_stream&);	  // read and evaluate a Primary

//------------------------------------------------------------------------------

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
	// is var already in var_table?
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val)
	// add (var, val) to var_table
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var, val });
	return val;
}

//------------------------------------------------------------------------------

double declaration(Token_stream& ts)
	// assume we have seen "let"
	// handle: name = expression
	// declare a variable called "name" with the initial value "expression"
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression(ts);
	define_name(var_name, d);
	return d;
}

//------------------------------------------------------------------------------

double function(Token_stream& ts)
{
	Token t = ts.get();
	if (t.name == "sqrt") {
		double res = expression(ts);
		if (res < 0) error("sqrt() can't handle a negative number.");
		return sqrt(res);
	}
	else if (t.name == "pow") {
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double x = primary(ts);

		t = ts.get();
		if (t.kind != ',') error("',' expected");
		double i = primary(ts);

		double res = pow(x, i);

		t = ts.get();
		if (t.kind != ')') error("')' expected");

		return res;
	}
}

//------------------------------------------------------------------------------

double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(ts);
	case func:
		ts.putback(t);
		return function(ts);
	default:
		ts.putback(t);
		return expression(ts);
	}
}

//------------------------------------------------------------------------------

void calculate(Token_stream& ts)
{
	while (cin) try
	{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement(ts) << '\n';
	}
	catch (exception& e)
	{
		cerr << e.what() << '\n';
		clean_up_mess(ts);
	}
}

//------------------------------------------------------------------------------

int main() try
{
	Token_stream ts;
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	func_table.push_back("sqrt");
	func_table.push_back("pow");
	calculate(ts);
	keep_window_open("~~");
	return 0;
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...)
{
	cerr << "Oops: unknown exception!\n";
	keep_window_open("~~");
	return 2;
}

//------------------------------------------------------------------------------

double expression(Token_stream& ts)
{
    double left = term(ts);      // read and evaluate a Term
	Token t = ts.get();
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term(ts);    // evaluate Term and add
			t = ts.get();
            break;
        case '-':
            left -= term(ts);    // evaluate Term and subtract
			t = ts.get();
            break;
        default:
			ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term(Token_stream& ts)
{
    double left = primary(ts);
	Token t = ts.get();

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary(ts);
			t = ts.get();
            break;
        case '/':
        {    
			double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d; 
			t = ts.get();
			break;
        }
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary(ts));
			if (i2 == 0) error("%: divide by zero");
			left = i1 % i2;
			t = ts.get();
			break;
		}
        default: 
			ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double primary(Token_stream& ts)     // read and evaluate a Primary
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:
		return t.value;  // return the number's value
	case name:
		return t.value;
	case func:
	{
		ts.putback(t);
		return function(ts);
	}
	case '+':
		return primary(ts);
	case '-':
		return -primary(ts);		
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

