
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

vector<string> split(const string& s, const string& w)
{
	string copy = s;

	for (char& c : copy)
		for (char cc : w)
			if (c == cc) c = ' ';

	istringstream is{ copy };
	vector<string> subs;

	for (string sub; is >> sub; )
		subs.push_back(sub);

	return subs;
}

//--------------------------------------------------------------------------------------

int main() try
{
	cout << "Please enter a string: ";
	string s;
	getline(cin, s);

	string w = "aeiou";
	vector<string> subs = split(s, w);

	for (string sub : subs)
		cout << sub << '\n';

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

