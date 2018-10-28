
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
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
	case ';':    // for "print"
	case 'q':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '{':
	case '}': case '!':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
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

Token_stream ts;      // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary();	  // read and evaluate a Primary

//------------------------------------------------------------------------------

int main()
try {
	double val = 0;
	while (cin) {
		Token t = ts.get();

		if (t.kind == 'q') break;
		if (t.kind == ';')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

//------------------------------------------------------------------------------


double expression()
{
    double left = term();      // read and evaluate a Term
	Token t = ts.get();
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
			t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
			t = ts.get();
            break;
        default:
			ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
	Token t = ts.get();

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
			t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
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

double primary()     // read and evaluate a Primary
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '8':    // we use '8' to represent a number
	{
		int num = t.value;
		t = ts.get();
		if (t.kind == '!') {
			if (num == 0) return 1;
			int d = num;
			for (int i = num - 1; i > 0; --i) d *= i;
			return d;
		}
		else {
			ts.putback(t);
			return num;
		}
	}
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

