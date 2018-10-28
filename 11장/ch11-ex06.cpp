
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

void f()
{
	string punctuations = ".;,?-'";

	cout << "Please enter a string\n";
	string s;
	getline(cin, s);

	for (char& ch : s)
		for (char& punct : punctuations)
			if (ch == punct) ch = ' ';

	cout << s << '\n';
}

//--------------------------------------------------------------------------------------

int main() try
{
	f();

	return 0;
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}

//--------------------------------------------------------------------------------------

